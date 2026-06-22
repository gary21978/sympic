#include <stdio.h>

#include <stdlib.h>

#include "pubdefs.h"

#include "cuda_/cuda_pscmc_inc.h"

#include "cuda_/inner_split_pass.kernel_inc.h"


#include "cuda_/stencil.kernel_inc.h"

#include "cuda_/mergefields.kernel_inc.h"

#include "cuda_/miniblas.kernel_inc.h"

#include "cuda_/general_partial_sort.kernel_inc.h"

#include "cuda_/move_back.kernel_inc.h"

#include "cuda_/particle_iter.kernel_inc.h"

#include "cuda_/geo_yeefdtd_rect.kernel_inc.h"

#include "cuda_/geo_yeefdtd.kernel_inc.h"

#include "cuda_yeefdtd.h"

#include <math.h>

#include "blas_shell.h"

#include <cgapsio.h>

#include "mpi_fieldio.h"

#include "cfgcst.h"

#include "run_particle.h"

#include "sync_fields.h"

double wclk_now();

int cuda_dump_ene_num(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC, double Deltat) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;

  Field3D_Seq *pfieldE = (pthis)->pfieldE;

  Field3D_Seq *pfieldB = (pthis)->pfieldB;


  Field3D_Seq *pFoutJ = (pthis)->pFoutJ;


  Field3D_Seq *pFoutEN = (pthis)->pFoutEN;


  double Mass = (pthis)->Mass;

  double Charge = (pthis)->Charge;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;

  void *dump_ene_num_kernel = (pthis)->dump_ene_num_kernel;

  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;


  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;

  int num_ele = (pfield)->num_ele;


  double delta_x = (pfield)->delta_x;

  double delta_y = (pfield)->delta_y;

  double delta_z = (pfield)->delta_z;


  //====================Field3D_Seq
  long the_xlen = (cuda_dump_ene_num_get_xlen());

  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  double DELTA_X = delta_x;

  double DELTA_Y = delta_y;

  double DELTA_Z = delta_z;

  void *fieldE = (pfieldE)->main_data;

  void *fieldB = (pfieldB)->main_data;

  void *FoutJ = (pFoutJ)->main_data;


  void *FoutEN = (pFoutEN)->main_data;

  cuda_dump_ene_num_scmc_set_parameter_FoutEN(dump_ene_num_kernel, FoutEN);
  cuda_dump_ene_num_scmc_set_parameter_FoutJ(dump_ene_num_kernel, FoutJ);
  cuda_dump_ene_num_scmc_set_parameter_fieldB(dump_ene_num_kernel, fieldB);
  cuda_dump_ene_num_scmc_set_parameter_fieldE(dump_ene_num_kernel, fieldE);
  cuda_dump_ene_num_scmc_set_parameter_cu_xyzw(dump_ene_num_kernel, cu_xyzw);
  cuda_dump_ene_num_scmc_set_parameter_cu_cache(dump_ene_num_kernel, cu_cache);
  cuda_dump_ene_num_scmc_set_parameter_xyzw(dump_ene_num_kernel, xyzw);
  cuda_dump_ene_num_scmc_set_parameter_inoutput(dump_ene_num_kernel, inoutput);
  cuda_pscmc_mem cuda_alloc_prefix_Deltat;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_Deltat), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_Deltat).h_data))[0] = Deltat);
  cuda_dump_ene_num_scmc_set_parameter_Deltat(dump_ene_num_kernel, &(cuda_alloc_prefix_Deltat));
  cuda_pscmc_mem cuda_alloc_prefix_DELTA_Z;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_DELTA_Z), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_DELTA_Z).h_data))[0] = DELTA_Z);
  cuda_dump_ene_num_scmc_set_parameter_DELTA_Z(dump_ene_num_kernel, &(cuda_alloc_prefix_DELTA_Z));
  cuda_pscmc_mem cuda_alloc_prefix_DELTA_Y;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_DELTA_Y), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_DELTA_Y).h_data))[0] = DELTA_Y);
  cuda_dump_ene_num_scmc_set_parameter_DELTA_Y(dump_ene_num_kernel, &(cuda_alloc_prefix_DELTA_Y));
  cuda_pscmc_mem cuda_alloc_prefix_DELTA_X;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_DELTA_X), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_DELTA_X).h_data))[0] = DELTA_X);
  cuda_dump_ene_num_scmc_set_parameter_DELTA_X(dump_ene_num_kernel, &(cuda_alloc_prefix_DELTA_X));
  cuda_pscmc_mem cuda_alloc_prefix_NUM_SPEC;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_NUM_SPEC), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_NUM_SPEC).h_data))[0] = NUM_SPEC);
  cuda_dump_ene_num_scmc_set_parameter_NUM_SPEC(dump_ene_num_kernel, &(cuda_alloc_prefix_NUM_SPEC));
  cuda_pscmc_mem cuda_alloc_prefix_SPEC;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_SPEC), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_SPEC).h_data))[0] = SPEC);
  cuda_dump_ene_num_scmc_set_parameter_SPEC(dump_ene_num_kernel, &(cuda_alloc_prefix_SPEC));
  cuda_pscmc_mem cuda_alloc_prefix_Charge;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_Charge), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_Charge).h_data))[0] = Charge);
  cuda_dump_ene_num_scmc_set_parameter_Charge(dump_ene_num_kernel, &(cuda_alloc_prefix_Charge));
  cuda_pscmc_mem cuda_alloc_prefix_Mass;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_Mass), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_Mass).h_data))[0] = Mass);
  cuda_dump_ene_num_scmc_set_parameter_Mass(dump_ene_num_kernel, &(cuda_alloc_prefix_Mass));
  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
  cuda_dump_ene_num_scmc_set_parameter_cu_cache_length(dump_ene_num_kernel, &(cuda_alloc_prefix_cu_cache_length));
  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
  cuda_dump_ene_num_scmc_set_parameter_grid_cache_len(dump_ene_num_kernel, &(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem cuda_alloc_prefix_num_ele;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_num_ele), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_num_ele).h_data))[0] = num_ele);
  cuda_dump_ene_num_scmc_set_parameter_num_ele(dump_ene_num_kernel, &(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_dump_ene_num_scmc_set_parameter_numvec(dump_ene_num_kernel, &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_dump_ene_num_scmc_set_parameter_ovlp(dump_ene_num_kernel, &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_dump_ene_num_scmc_set_parameter_ZLEN(dump_ene_num_kernel, &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_dump_ene_num_scmc_set_parameter_YLEN(dump_ene_num_kernel, &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_dump_ene_num_scmc_set_parameter_XLEN(dump_ene_num_kernel, &(cuda_alloc_prefix_XLEN));
  cuda_dump_ene_num_exec(dump_ene_num_kernel, the_xlen, numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_Deltat));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_DELTA_Z));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_DELTA_Y));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_DELTA_X));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_NUM_SPEC));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_SPEC));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_Charge));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_Mass));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  return 0;
}
int dump_ene_num_all(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC, double dt) {

  // defined from class One_Particle_Collection


  //====================One_Particle_Collection

  // defined from class Field3D_Seq


  //====================Field3D_Seq
  cuda_dump_ene_num(pthis, SPEC, NUM_SPEC, dt);

  return 0;
}
int dump_ene_num_mpi(Particle_in_Cell_MPI *pthis, double dt0) {

  // defined from class Particle_in_Cell_MPI
  Field3D_MPI MPI_fieldE = (pthis)->MPI_fieldE;


  int *o_particle_type = (pthis)->o_particle_type;


  //====================Particle_in_Cell_MPI
  int num_spec = (MPI_fieldE).num_spec;

  int num_runtime = (MPI_fieldE).num_runtime;

  {
    long i;

    for ((i = 0); (i < (num_runtime * num_spec)); (i = (i + 1))) {
      int ptype = (o_particle_type)[(i / num_runtime)];

      if ((1 || (ptype == 0))) {
        dump_ene_num_all(((MPI_fieldE).particles + i), (i / num_runtime), num_spec, dt0);
      }
    }
  }
  return 0;
}
