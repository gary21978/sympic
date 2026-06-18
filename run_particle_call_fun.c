#include <stdio.h>

#include <stdlib.h>

#include "pubdefs.h"

#include "cuda_/cuda_pscmc_inc.h"

#include "cuda_/inner_split_pass.kernel_inc.h"

#include "cuda_/yeefdtd.kernel_inc.h"

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

int cuda_One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(One_Particle_Collection *pthis, Field3D_Seq *fieldE,
                                                         Field3D_Seq *fieldB, Field3D_Seq *fieldB1, Field3D_Seq *FoutJ,
                                                         double Mass0_lst_fix, double Charge0_lst_fix, double Deltat,
                                                         double Tori_X0, double r0, double MIN_R0, double Q0, double b0,
                                                         double zmid, int SPEC, int NUM_SPEC) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void **nonrel_test_kernel = (pthis)->nonrel_test_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;


  //====================One_Particle_Collection

  // Generate one runtime one species version of ker-name

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;

  int num_ele = (pfield)->num_ele;


  void *xoffset = (pfield)->xoffset;

  void *yoffset = (pfield)->yoffset;

  void *zoffset = (pfield)->zoffset;


  double delta_x = (pfield)->delta_x;

  double delta_y = (pfield)->delta_y;

  double delta_z = (pfield)->delta_z;


  //====================Field3D_Seq
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  double DELTA_X = delta_x;

  double DELTA_Y = delta_y;

  double DELTA_Z = delta_z;

  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_inoutput((nonrel_test_kernel)[0], inoutput);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldE((nonrel_test_kernel)[0], (fieldE)->main_data);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB((nonrel_test_kernel)[0], (fieldB)->main_data);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB1((nonrel_test_kernel)[0], (fieldB1)->main_data);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_FoutJ((nonrel_test_kernel)[0], (FoutJ)->main_data);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xyzw((nonrel_test_kernel)[0], xyzw);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache((nonrel_test_kernel)[0], cu_cache);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_xyzw((nonrel_test_kernel)[0], cu_xyzw);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xoffset((nonrel_test_kernel)[0], xoffset);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_yoffset((nonrel_test_kernel)[0], yoffset);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zoffset((nonrel_test_kernel)[0], zoffset);
  {
    double Mass0 = Mass0_lst_fix;

    double Charge0 = Charge0_lst_fix;

    cuda_pscmc_mem cuda_alloc_prefix_XLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_XLEN((nonrel_test_kernel)[0], &(cuda_alloc_prefix_XLEN));
    cuda_pscmc_mem cuda_alloc_prefix_YLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_YLEN((nonrel_test_kernel)[0], &(cuda_alloc_prefix_YLEN));
    cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ZLEN((nonrel_test_kernel)[0], &(cuda_alloc_prefix_ZLEN));
    cuda_pscmc_mem cuda_alloc_prefix_ovlp;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ovlp((nonrel_test_kernel)[0], &(cuda_alloc_prefix_ovlp));
    cuda_pscmc_mem cuda_alloc_prefix_numvec;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_numvec((nonrel_test_kernel)[0], &(cuda_alloc_prefix_numvec));
    cuda_pscmc_mem cuda_alloc_prefix_num_ele;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_num_ele), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_num_ele).h_data))[0] = num_ele);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_num_ele((nonrel_test_kernel)[0], &(cuda_alloc_prefix_num_ele));
    cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_grid_cache_len((nonrel_test_kernel)[0],
                                                                   &(cuda_alloc_prefix_grid_cache_len));
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache_length((nonrel_test_kernel)[0],
                                                                    &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_DELTA_X;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_DELTA_X), PS_DOUBLE_NUM, 0);
    ((((double *)(cuda_alloc_prefix_DELTA_X).h_data))[0] = DELTA_X);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_X((nonrel_test_kernel)[0], &(cuda_alloc_prefix_DELTA_X));
    cuda_pscmc_mem cuda_alloc_prefix_DELTA_Y;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_DELTA_Y), PS_DOUBLE_NUM, 0);
    ((((double *)(cuda_alloc_prefix_DELTA_Y).h_data))[0] = DELTA_Y);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Y((nonrel_test_kernel)[0], &(cuda_alloc_prefix_DELTA_Y));
    cuda_pscmc_mem cuda_alloc_prefix_DELTA_Z;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_DELTA_Z), PS_DOUBLE_NUM, 0);
    ((((double *)(cuda_alloc_prefix_DELTA_Z).h_data))[0] = DELTA_Z);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Z((nonrel_test_kernel)[0], &(cuda_alloc_prefix_DELTA_Z));
    cuda_pscmc_mem cuda_alloc_prefix_Mass0;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_Mass0), PS_DOUBLE_NUM, 0);
    ((((double *)(cuda_alloc_prefix_Mass0).h_data))[0] = Mass0);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Mass0((nonrel_test_kernel)[0], &(cuda_alloc_prefix_Mass0));
    cuda_pscmc_mem cuda_alloc_prefix_Charge0;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_Charge0), PS_DOUBLE_NUM, 0);
    ((((double *)(cuda_alloc_prefix_Charge0).h_data))[0] = Charge0);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Charge0((nonrel_test_kernel)[0], &(cuda_alloc_prefix_Charge0));
    cuda_pscmc_mem cuda_alloc_prefix_Deltat;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_Deltat), PS_DOUBLE_NUM, 0);
    ((((double *)(cuda_alloc_prefix_Deltat).h_data))[0] = Deltat);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Deltat((nonrel_test_kernel)[0], &(cuda_alloc_prefix_Deltat));
    cuda_pscmc_mem cuda_alloc_prefix_Tori_X0;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_Tori_X0), PS_DOUBLE_NUM, 0);
    ((((double *)(cuda_alloc_prefix_Tori_X0).h_data))[0] = Tori_X0);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Tori_X0((nonrel_test_kernel)[0], &(cuda_alloc_prefix_Tori_X0));
    cuda_pscmc_mem cuda_alloc_prefix_r0;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_r0), PS_DOUBLE_NUM, 0);
    ((((double *)(cuda_alloc_prefix_r0).h_data))[0] = r0);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_r0((nonrel_test_kernel)[0], &(cuda_alloc_prefix_r0));
    cuda_pscmc_mem cuda_alloc_prefix_MIN_R0;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_MIN_R0), PS_DOUBLE_NUM, 0);
    ((((double *)(cuda_alloc_prefix_MIN_R0).h_data))[0] = MIN_R0);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_MIN_R0((nonrel_test_kernel)[0], &(cuda_alloc_prefix_MIN_R0));
    cuda_pscmc_mem cuda_alloc_prefix_Q0;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_Q0), PS_DOUBLE_NUM, 0);
    ((((double *)(cuda_alloc_prefix_Q0).h_data))[0] = Q0);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Q0((nonrel_test_kernel)[0], &(cuda_alloc_prefix_Q0));
    cuda_pscmc_mem cuda_alloc_prefix_b0;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_b0), PS_DOUBLE_NUM, 0);
    ((((double *)(cuda_alloc_prefix_b0).h_data))[0] = b0);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_b0((nonrel_test_kernel)[0], &(cuda_alloc_prefix_b0));
    cuda_pscmc_mem cuda_alloc_prefix_zmid;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_zmid), PS_DOUBLE_NUM, 0);
    ((((double *)(cuda_alloc_prefix_zmid).h_data))[0] = zmid);
    cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zmid((nonrel_test_kernel)[0], &(cuda_alloc_prefix_zmid));
    cuda_geo_nr_Bfield_pushJ_vlo_exec((nonrel_test_kernel)[0], cuda_geo_nr_Bfield_pushJ_vlo_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_num_ele));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_DELTA_X));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_DELTA_Y));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_DELTA_Z));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_Mass0));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_Charge0));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_Deltat));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_Tori_X0));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_r0));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_MIN_R0));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_Q0));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_b0));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_zmid));
  }
  return 0;
}

int One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(One_Particle_Collection *pthis, Field3D_Seq *fieldE,
                                                    Field3D_Seq *fieldB, Field3D_Seq *fieldB1, Field3D_Seq *FoutJ,
                                                    double Mass0_lst_fix, double Charge0_lst_fix, double Deltat,
                                                    double Tori_X0, double r0, double MIN_R0, double Q0, double b0,
                                                    double zmid, int spec, int num_spec) {

  // defined from class One_Particle_Collection


  //====================One_Particle_Collection

  // defined from class Field3D_Seq


  //====================Field3D_Seq
  cuda_One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(pthis, fieldE, fieldB, fieldB1, FoutJ, Mass0_lst_fix,
                                                       Charge0_lst_fix, Deltat, Tori_X0, r0, MIN_R0, Q0, b0, zmid, spec,
                                                       num_spec);

  return 0;
}

int MPI_geo_nr_Bfield_pushJ_vlo(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                Field3D_MPI *fieldB1, Field3D_MPI *FoutJ, double *Mass0, double *Charge0, double Deltat,
                                double Tori_X0, double r0, double MIN_R0, double Q0, double b0, double zmid) {

  // defined from class Particle_in_Cell_MPI
  Field3D_MPI MPI_fieldE = (pthis)->MPI_fieldE;


  int *o_particle_type = (pthis)->o_particle_type;


  //====================Particle_in_Cell_MPI
  long i = 0;

  // Generate MPI version of ker-name
  int num_spec = (MPI_fieldE).num_spec;

  int num_runtime = (MPI_fieldE).num_runtime;

  for (i = 0; (i < (num_runtime * num_spec)); i++) {
    int cur_spec = (i / num_runtime);

    if (((o_particle_type)[cur_spec] == 0)) {
      One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(
          ((MPI_fieldE).particles + i), ((fieldE)->data + (i % num_runtime)), ((fieldB)->data + (i % num_runtime)),
          ((fieldB1)->data + (i % num_runtime)), ((FoutJ)->data + (i % num_runtime)), (Mass0)[(i / num_runtime)],
          (Charge0)[(i / num_runtime)], Deltat, Tori_X0, r0, MIN_R0, Q0, b0, zmid, cur_spec, num_spec);
    }
  }
  return 0;
}
