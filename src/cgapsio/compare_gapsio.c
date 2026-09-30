#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
typedef struct {
  FILE *f;
  int64_t type, dim, n, steps, *shape;
} G;
static int op(G *g, const char *p) {
  int64_t v, i;
  long e;
  memset(g, 0, sizeof(*g));
  g->f = fopen(p, "rb");
  if (!g->f || fread(&v, 8, 1, g->f) != 1 || fread(&g->type, 8, 1, g->f) != 1 ||
      fread(&g->dim, 8, 1, g->f) != 1 || v != 0 || g->dim < 1 || g->dim > 32)
    return 1;
  g->shape = malloc(g->dim * 8);
  if (!g->shape || fread(g->shape, 8, g->dim, g->f) != (size_t)g->dim)
    return 1;
  g->n = 1;
  for (i = 0; i < g->dim; i++)
    g->n *= g->shape[i];
  if (g->type != 7)
    return 1;
  if (fseek(g->f, 0, SEEK_END) || ((e = ftell(g->f)) < 0))
    return 1;
  g->steps = (e - (3 + g->dim) * 8) / (g->n * 8);
  return 0;
}
static void cl(G *g) {
  if (g->f)
    fclose(g->f);
  free(g->shape);
}
static int one(const char *pa, const char *pb, const char *name, double tol) {
  G a, b;
  int64_t t, i, h;
  double *x, *y, ma, sc, d, r;
  if (op(&a, pa) || op(&b, pb)) {
    fprintf(stderr, "[fatal] invalid GAPSIO: %s or %s\n", pa, pb);
    return 2;
  }
  if (a.type != b.type || a.dim != b.dim || a.n != b.n || a.steps != b.steps) {
    printf("%s SHAPE/TYPE/STEP MISMATCH\n", name);
    cl(&a);
    cl(&b);
    return 1;
  }
  for (i = 0; i < a.dim; i++)
    if (a.shape[i] != b.shape[i]) {
      printf("%s SHAPE MISMATCH\n", name);
      cl(&a);
      cl(&b);
      return 1;
    }
  x = malloc(a.n * 8);
  y = malloc(a.n * 8);
  h = (3 + a.dim) * 8;
  for (t = 0; t < a.steps; t++) {
    fseek(a.f, h + t * a.n * 8, SEEK_SET);
    fseek(b.f, h + t * b.n * 8, SEEK_SET);
    fread(x, 8, a.n, a.f);
    fread(y, 8, b.n, b.f);
    ma = 0;
    sc = 1;
    for (i = 0; i < a.n; i++) {
      d = fabs(x[i] - y[i]);
      if (d > ma)
        ma = d;
      if (fabs(y[i]) > sc)
        sc = fabs(y[i]);
    }
    r = ma / sc;
    printf("%s t%04ld max|d|=% .3e rel=% .3e %s\n", name, (long)t, ma, r, r < tol ? "OK" : "DIFF");
    if (r >= tol) {
      free(x);
      free(y);
      cl(&a);
      cl(&b);
      return 1;
    }
  }
  free(x);
  free(y);
  cl(&a);
  cl(&b);
  return 0;
}
int main(int ac, char **av) {
  const char *td = 0, *rd = 0;
  double tol = 1e-10;
  int i, rc = 0, z;
  char a[4096], b[4096];
  const char *v[] = {"tmpEB", "tmpEN", "tmpJ"};
  for (i = 1; i < ac; i++) {
    if (!strcmp(av[i], "--test-dir") && i + 1 < ac)
      td = av[++i];
    else if (!strcmp(av[i], "--ref-dir") && i + 1 < ac)
      rd = av[++i];
    else if (!strcmp(av[i], "--rel-tol") && i + 1 < ac)
      tol = atof(av[++i]);
    else {
      fprintf(stderr, "usage: %s --test-dir DIR --ref-dir DIR [--rel-tol TOL]\n", av[0]);
      return 2;
    }
  }
  if (!td || !rd)
    return 2;
  for (i = 0; i < 3; i++) {
    snprintf(a, sizeof(a), "%s/%s", td, v[i]);
    snprintf(b, sizeof(b), "%s/%s", rd, v[i]);
    if (access(a, 4) && access(b, 4))
      continue;
    if (access(a, 4) || access(b, 4)) {
      fprintf(stderr, "missing %s\n", v[i]);
      rc = 1;
      continue;
    }
    z = one(a, b, v[i], tol);
    if (z > rc)
      rc = z;
  }
  return rc;
}
