#include <stdlib.h>
#include <math.h>

double rand01(double x0, double x1) {
  return ((((x1 - x0) * (0.5 + rand())) / (((double)RAND_MAX) + 1.0)) + x0);
}
double maxwell_dist(double ava, double sig) {
  return (((sig * sqrt(((-1 * 2.0) * log(rand01(0, 1))))) *
           cos(((M_PI * 2.0) * rand01(0, 1)))) +
          ava);
}
