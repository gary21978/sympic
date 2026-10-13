#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <cgapsio.h>

#define BLOCK_THREH (1 << 30)

static const int gaps_type_len[] = {4, 8, 2, 4, 8, 2, 4, 8, 16, 16, 16, 1, 1};

static int serial_type_len(int type) {
  if (type < 0 || type >= (int)(sizeof(gaps_type_len) / sizeof(gaps_type_len[0]))) {
    fprintf(stderr, "Unsupported GAPSIO type %d\n", type);
    exit(1);
  }
  return gaps_type_len[type];
}

static void serial_init_input(Gaps_IO_DataFile *data, const char *filename) {
  memset(data, 0, sizeof(*data));
  data->pfile = fopen(filename, "rb");
  if (!data->pfile) {
    perror(filename);
    exit(1);
  }
  if (fread(&data->version, sizeof(int64_t), 1, data->pfile) != 1 ||
      fread(&data->type, sizeof(int64_t), 1, data->pfile) != 1 ||
      fread(&data->dim, sizeof(int64_t), 1, data->pfile) != 1 || data->version != 2 ||
      data->dim <= 0) {
    fprintf(stderr, "Invalid GAPSIO v2 header in %s\n", filename);
    exit(1);
  }
  data->pdimarray = malloc((size_t)data->dim * sizeof(int64_t));
  data->pblockarray = malloc((size_t)data->dim * sizeof(int64_t));
  if (!data->pdimarray || !data->pblockarray ||
      fread(data->pdimarray, sizeof(int64_t), (size_t)data->dim, data->pfile) !=
          (size_t)data->dim ||
      fread(data->pblockarray, sizeof(int64_t), (size_t)data->dim, data->pfile) !=
          (size_t)data->dim) {
    fprintf(stderr, "Incomplete GAPSIO v2 header in %s\n", filename);
    exit(1);
  }
  data->numperstep = 1;
  data->block_len = 1;
  for (int64_t i = 0; i < data->dim; ++i) {
    data->numperstep *= data->pdimarray[i] * data->pblockarray[i];
    data->block_len *= data->pdimarray[i];
  }
  data->time_step_current = 0;
}

static int64_t serial_num_steps(Gaps_IO_DataFile *data) {
  long current = ftell(data->pfile);
  if (fseek(data->pfile, 0, SEEK_END) != 0) {
    perror("fseek input");
    exit(1);
  }
  long end = ftell(data->pfile);
  if (current < 0 || end < 0 || fseek(data->pfile, current, SEEK_SET) != 0) {
    perror("measure input");
    exit(1);
  }
  int64_t header_bytes = (3 + 2 * data->dim) * (int64_t)sizeof(int64_t);
  int64_t elements_per_step = data->num_block_current_proc * data->block_len;
  int64_t element_bytes = serial_type_len((int)data->type);
  int64_t payload = (int64_t)end - header_bytes;
  if (payload < 0 || elements_per_step <= 0 ||
      payload % (elements_per_step * element_bytes) != 0) {
    fprintf(stderr, "Invalid GAPSIO v2 payload size in input shard\n");
    exit(1);
  }
  return payload / (elements_per_step * element_bytes);
}

static void serial_init_output(Gaps_IO_DataFile *data, const char *filename, int64_t type,
                               int64_t dim, const int64_t *dimensions, int64_t timestep) {
  memset(data, 0, sizeof(*data));
  data->version = 0;
  data->type = type;
  data->dim = dim;
  data->pdimarray = malloc((size_t)dim * sizeof(int64_t));
  data->pblockarray = malloc((size_t)dim * sizeof(int64_t));
  if (!data->pdimarray || !data->pblockarray) {
    fprintf(stderr, "Unable to allocate output dimensions\n");
    exit(1);
  }
  memcpy(data->pdimarray, dimensions, (size_t)dim * sizeof(int64_t));
  data->numperstep = 1;
  for (int64_t i = 0; i < dim; ++i) {
    data->pblockarray[i] = 1;
    data->numperstep *= dimensions[i];
  }
  data->pfile = fopen(filename, (timestep == -1) ? "wb+" : "r+b");
  if (!data->pfile) {
    perror(filename);
    exit(1);
  }
  if (timestep == -1) {
    if (fwrite(&data->version, sizeof(int64_t), 1, data->pfile) != 1 ||
        fwrite(&data->type, sizeof(int64_t), 1, data->pfile) != 1 ||
        fwrite(&data->dim, sizeof(int64_t), 1, data->pfile) != 1 ||
        fwrite(data->pdimarray, sizeof(int64_t), (size_t)dim, data->pfile) != (size_t)dim) {
      fprintf(stderr, "Unable to write GAPSIO v0 header to %s\n", filename);
      exit(1);
    }
  } else {
    int64_t header[3];
    if (fread(header, sizeof(int64_t), 3, data->pfile) != 3 || header[0] != 0 ||
        header[1] != type || header[2] != dim) {
      fprintf(stderr, "Existing output %s has an incompatible GAPSIO header\n", filename);
      exit(1);
    }
    for (int64_t i = 0; i < dim; ++i) {
      int64_t existing_dim;
      if (fread(&existing_dim, sizeof(int64_t), 1, data->pfile) != 1 ||
          existing_dim != dimensions[i]) {
        fprintf(stderr, "Existing output %s has incompatible dimensions\n", filename);
        exit(1);
      }
    }
  }
}

static void serial_seek_output(Gaps_IO_DataFile *data, int64_t step, int64_t offset) {
  int64_t header_bytes = (3 + data->dim) * (int64_t)sizeof(int64_t);
  int64_t byte_offset = header_bytes +
                        (step * data->numperstep + offset) * serial_type_len((int)data->type);
  if (fseek(data->pfile, (long)byte_offset, SEEK_SET) != 0) {
    perror("fseek output");
    exit(1);
  }
}

static void serial_write_output(Gaps_IO_DataFile *data, const void *buffer, int64_t elements) {
  if (fwrite(buffer, (size_t)serial_type_len((int)data->type), (size_t)elements,
             data->pfile) != (size_t)elements) {
    perror("write output");
    exit(1);
  }
}

static void serial_delete_data(Gaps_IO_DataFile *data) {
  if (data->pfile) fclose(data->pfile);
  free(data->pdimarray);
  free(data->pblockarray);
  free(data->locations);
}

int read_file(void **pptr, int64_t *plen, char *name) {
  FILE *fp = fopen(name, "rb");
  if (!fp) {
    perror(name);
    exit(1);
  }
  if (fseek(fp, 0, SEEK_END) != 0) {
    perror("seek metadata");
    exit(1);
  }
  long l = ftell(fp);
  if (l < 0 || fseek(fp, 0, SEEK_SET) != 0) {
    perror("read metadata size");
    exit(1);
  }
  pptr[0] = malloc((size_t)l);
  if (!pptr[0] && l != 0) {
    fprintf(stderr, "Unable to allocate metadata buffer for %s\n", name);
    exit(1);
  }
  plen[0] = l;
  if (fread(pptr[0], 1, (size_t)l, fp) != (size_t)l) {
    fprintf(stderr, "Short read from metadata file %s\n", name);
    fclose(fp);
    exit(1);
  }
  fclose(fp);
  return 0;
}
int read_one_block_stdio(Gaps_IO_DataFile *pgid, void *ptr, char *file_name, int64_t ts,
                         int64_t num_blocks_one_step_this_file, int64_t bid) {
  FILE *fp = fopen(file_name, "rb");
  if (!fp) {
    perror(file_name);
    exit(1);
  }
  int64_t blk_len = pgid->block_len * serial_type_len((int)pgid->type);
  int64_t offset_zero = sizeof(int64_t) * (3 + (pgid->dim * 2));
  if (fseek(fp, (long)(offset_zero + (blk_len * (bid + (num_blocks_one_step_this_file * ts)))),
            SEEK_SET) != 0) {
    perror("seek input block");
    exit(1);
  }
  size_t nread = fread(ptr, 1, blk_len, fp);
  if (nread != (size_t)blk_len) {
    fprintf(stderr, "Short read from %s\n", file_name);
    exit(1);
  }
  fclose(fp);
  return 0;
}
int main(int argc, char **argv) {
  Gaps_IO_DataFile gi;
  Gaps_IO_DataFile *pgi = &gi;
  Gaps_IO_DataFile go;
  Gaps_IO_DataFile *pgo = &go;
  if (argc < 3) {
    fprintf(stderr, "Usage: %s infile(s) outfile\n", argv[0]);
    return 0;
  }
  pgi->version = 2;
  serial_init_input(pgi, argv[1]);
  if (2 != pgi->version) {
    fprintf(stderr, "File %s is not version 2\n", argv[1]);
  }
  int64_t type = pgi->type;
  int64_t dim = pgi->dim;
  int64_t *pdimarray = pgi->pdimarray;
  int64_t *pblockarray = pgi->pblockarray;
  int64_t numperstep = pgi->numperstep;
  int typelen = serial_type_len((int)type);
  int64_t *poutlen = malloc(sizeof(int64_t) * dim);
  int64_t oneblock_len = 1;
  int64_t numblocks = 1;
  {
    long g;
    for (g = 0; g < dim; g++) {
      poutlen[g] = pdimarray[g] * pblockarray[g];
      oneblock_len *= pdimarray[g];
      numblocks *= pblockarray[g];
    }
  }
  int num_files = (argc - 2);
  int64_t **meta_data = malloc(num_files * sizeof(int64_t *));
  int64_t *meta_data_len = malloc(num_files * sizeof(int64_t));
  int64_t *file_id = malloc(sizeof(int64_t) * numblocks);
  int64_t *local_block_id = malloc(sizeof(int64_t) * numblocks);
  {
    long i;
    for (i = 1; i < (argc - 1); i++) {
      long cur_i = (i - 1);
      fprintf(stderr, "Checking %s\n", argv[i]);
      char meta_file_name[512];
      strncpy(meta_file_name, argv[i], 512);
      int l = strlen(meta_file_name);
      int sj = 0;
      {
        long j;
        for (j = 0; j < l; j++) {
          if (meta_file_name[l - (1 + j)] == '_') {
            sj = (l - (1 + j)) - 4;
            break;
          }
        }
      }
      memcpy((meta_file_name + sj), "META", 4);
      read_file((void **)(meta_data + cur_i), (meta_data_len + cur_i), meta_file_name);
      meta_data_len[cur_i] = meta_data_len[cur_i] / sizeof(int64_t);
      {
        long j;
        for (j = 0; j < meta_data_len[cur_i]; j++) {
          int64_t local_id_m = (meta_data[cur_i])[j];
          file_id[local_id_m] = cur_i;
          local_block_id[local_id_m] = j;
        }
      }
    }
  }
  int64_t numsteps = 0;
  pgi->num_block_current_proc = meta_data_len[0];
  pgi->num_block_all_reduce_group = pgi->num_block_current_proc;
  numsteps = serial_num_steps(pgi);
  char *display_steps = "GAPS_IO_DISPLAY_NUM_STEPS";
  char *uds = getenv(display_steps);
  //fprintf(stderr, "0x%p 0x%p\n", display_steps, uds);
  if (uds && (strcmp(uds, "1") == 0)) {
    fprintf(stdout, "%ld\n", numsteps);
    exit(0);
  }
  char *min_env_str = "GAPS_IO_MIN_TIME_STEP";
  char *max_env_str = "GAPS_IO_MAX_TIME_STEP";
  char *output_offset_str = "GAPS_IO_OUTPUT_OFFSET_TIME_STEP";
  char *min_numt = getenv(min_env_str);
  char *max_numt = getenv(max_env_str);
  char *output_offset_numt = getenv(output_offset_str);
  long t_min = 0;
  long t_max = numsteps;
  if (min_numt) {
    sscanf(min_numt, "%ld", &t_min);
  }
  fprintf(stderr, "t_min=%ld ns=%ld\n", t_min, numsteps);
  if (t_min >= numsteps) {
    exit(0);
  }
  t_min = (t_min + numsteps) % numsteps;
  if (max_numt) {
    sscanf(max_numt, "%ld", &t_max);
  }
  long t_opt_offset = t_min;
  if (output_offset_numt) {
    sscanf(output_offset_numt, "%ld", &t_opt_offset);
  }
  t_max = ((t_max + (numsteps + -1)) % numsteps) + 1;
  fprintf(stderr, "tmin=%ld tmax=%ld topt=%ld\n", t_min, t_max, t_opt_offset);
  serial_init_output(pgo, argv[argc - 1], type, dim, poutlen,
                     ((t_min - t_opt_offset == 0) ? (-1) : (t_min - t_opt_offset)));
  int64_t opt_write_block = 1;
  int64_t opt_read_block = oneblock_len;
  int dim_current = 0;
  for (; dim_current < dim; dim_current++) {
    opt_write_block *= poutlen[dim_current];
    opt_read_block *= pblockarray[dim_current];
    if (opt_read_block > BLOCK_THREH) {
      opt_write_block /= poutlen[dim_current];
      opt_read_block /= pblockarray[dim_current];
      break;
    }
  }
  int64_t one_write_offset = 1;
  {
    long i;
    for (i = 0; i < dim_current; i++) {
      one_write_offset *= poutlen[i];
    }
  }
  int64_t one_write_stride_num =
      one_write_offset * ((dim_current < dim) ? (pdimarray[dim_current]) : (1));
  int64_t num_reads_per_step = pgo->numperstep / opt_read_block;
  int64_t num_blocks_per_read = opt_read_block / oneblock_len;
  int64_t num_writes_per_read = opt_read_block / opt_write_block;
  char *read_block_buffer = malloc(opt_read_block * typelen);
  char *read_one_block_buffer = malloc(oneblock_len * typelen);
  int64_t *pblkid = malloc(sizeof(int64_t) * dim);
  int64_t *plocalid = malloc(sizeof(int64_t) * dim);
  int64_t *pallid = malloc(sizeof(int64_t) * dim);
  int64_t *palldim = malloc(sizeof(int64_t) * dim);
  int64_t *pallid_local = malloc(sizeof(int64_t) * dim);
  int64_t *palldim_local = malloc(sizeof(int64_t) * dim);
  {
    long t;
    for (t = t_min; t < t_max; t++) {
      {
        long b_rd;
        for (b_rd = 0; b_rd < num_reads_per_step; b_rd++) {
          int64_t global_offset_new = 0;
          {
            long r_rd;
            for (r_rd = 0; r_rd < num_blocks_per_read; r_rd++) {
              int64_t bid_all = r_rd + (num_blocks_per_read * b_rd);
              read_one_block_stdio(pgi, read_one_block_buffer, argv[1 + file_id[bid_all]], t,
                                   meta_data_len[file_id[bid_all]], local_block_id[bid_all]);
              {
                int64_t gid = bid_all;
                {
                  long tmpids;
                  for (tmpids = 0; tmpids < dim; tmpids++) {
                    pblkid[tmpids] = gid % pblockarray[tmpids];
                    gid /= pblockarray[tmpids];
                  }
                }
              }
              {
                long l;
                for (l = 0; l < oneblock_len; l++) {
                  {
                    long gid = l;
                    {
                      long tmpids;
                      for (tmpids = 0; tmpids < dim; tmpids++) {
                        plocalid[tmpids] = gid % pdimarray[tmpids];
                        gid /= pdimarray[tmpids];
                      }
                    }
                  }
                  {
                    long a;
                    for (a = 0; a < dim; a++) {
                      pallid[a] = plocalid[a] + (pdimarray[a] * pblkid[a]);
                      palldim[a] = pdimarray[a] * pblockarray[a];
                      (pallid_local[a] =
                           ((a < dim_current) ? (plocalid[a] + (pdimarray[a] * pblkid[a]))
                                              : (plocalid[a])));
                      (palldim_local[a] =
                           ((a < dim_current) ? (pdimarray[a] * pblockarray[a]) : (pdimarray[a])));
                    }
                  }
                  int64_t global_id_out = ({
                    int64_t gid = 0;
                    int64_t stride_len = 1;
                    {
                      long tmpids;
                      for (tmpids = 0; tmpids < dim; tmpids++) {
                        gid = gid + (pallid[tmpids] * stride_len);
                        stride_len = stride_len * palldim[tmpids];
                      }
                    }
                    gid;
                  });
                  if ((l == 0) && (r_rd == 0)) {
                    global_offset_new = global_id_out;
                  }
                  int64_t global_id = ({
                    int64_t gid = 0;
                    int64_t stride_len = 1;
                    {
                      long tmpids;
                      for (tmpids = 0; tmpids < dim; tmpids++) {
                        gid = gid + (pallid_local[tmpids] * stride_len);
                        stride_len = stride_len * palldim_local[tmpids];
                      }
                    }
                    gid;
                  });
                  memcpy((read_block_buffer + (global_id * typelen)),
                         (read_one_block_buffer + (l * typelen)), typelen);
                  int data = ((double *)read_block_buffer)[global_id];
                }
              }
            }
          }
          {
            long w_rd;
            for (w_rd = 0; w_rd < num_writes_per_read; w_rd++) {
              int64_t offset = global_offset_new + (w_rd * one_write_offset);
              serial_seek_output(pgo, (t - t_opt_offset), offset);
              serial_write_output(pgo, (read_block_buffer + (w_rd * (opt_write_block * typelen))),
                                  opt_write_block);
            }
          }
        }
      }
      fprintf(stderr, "t=%ld done\n", t);
    }
  }
  free(pblkid);
  free(plocalid);
  free(pallid);
  free(palldim);
  free(pallid_local);
  free(palldim_local);
  free(read_block_buffer);
  free(read_one_block_buffer);
  serial_delete_data(pgo);
  serial_delete_data(pgi);
  return 0;
}
