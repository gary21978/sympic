#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <assert.h>

#include <math.h>

#include "pubdefs.h"

#include "genrand.h"

#include "cfgcst.h"

#include "init_field3d_mpi.h"

#include "init_particle.h"

#include "seqfields.h"

#include "sync_fields.h"

#include "blas_shell.h"

void user_defined_particle_distribution(double *xyzvx, long xyzx, long xyzy, long xyzz, int cur_sp, long l,
                                        long grid_load, long external_para);

#include "cuda_/cuda_pscmc_inc.h"

#include "cuda_/inner_split_pass.kernel_inc.h"



#include "cuda_/mergefields.kernel_inc.h"

#include "cuda_/miniblas.kernel_inc.h"

#include "cuda_/general_partial_sort.kernel_inc.h"

#include "cuda_/move_back.kernel_inc.h"

#include "cuda_/particle_iter.kernel_inc.h"


#include "cuda_/geo_yeefdtd.kernel_inc.h"

#include "cuda_yeefdtd.h"

extern long srand_seed;
long find_vec_id(long id, long *adj_ids, long numvec) {
  long num_id_min = (adj_ids)[(NUM_SYNC_LAYER / 2)];

  long num_id_max = (num_id_min + (numvec - 1));

  if (((id < num_id_min) || (id > num_id_max))) {
    return -1;

  } else {
    return (id - num_id_min);
  }
}
int init_particle(One_Particle_Collection *pthis, Field3D_Seq *pfield, double Mass, double Charge,
                  double Number_particle_per_marker, long grid_cache_len, long cu_cache_length) {
  if ((grid_cache_len % 4)) {
    (grid_cache_len = (4 * ((grid_cache_len / 4) + 1)));
  }

  if ((cu_cache_length % 4)) {
    (cu_cache_length = (4 * ((cu_cache_length / 4) + 1)));
  }

  ((pthis)->pfield = pfield);
  ((pthis)->Mass = Mass);
  ((pthis)->Charge = Charge);
  ((pthis)->Number_particle_per_marker = Number_particle_per_marker);
  ((pthis)->grid_cache_len = grid_cache_len);
  ((pthis)->cu_cache_length = cu_cache_length);
  {

    // defined from class Field3D_Seq
    void *pe = (pfield)->pe;

    long xlen = (pfield)->xlen;

    long ylen = (pfield)->ylen;

    long zlen = (pfield)->zlen;


    long numvec = (pfield)->numvec;


    long *adj_ids = (pfield)->adj_ids;


    //====================Field3D_Seq
    void **sort_kernel = (pthis)->sort_kernel;

    ((pthis)->inoutput = malloc((sizeof(cuda_pscmc_mem))));
    ((pthis)->xyzw = malloc((sizeof(cuda_pscmc_mem))));
    ((pthis)->cu_cache = malloc((sizeof(cuda_pscmc_mem))));
    ((pthis)->cu_xyzw = malloc((sizeof(cuda_pscmc_mem))));
    ((pthis)->adjoint_vec_pids = malloc((sizeof(cuda_pscmc_mem))));
    ((pthis)->swap_len_buf = malloc((sizeof(cuda_pscmc_mem))));
    // NOTE: Standard CUDA regression uses *_pushJ_vlo path only.
    {
      size_t structlen;

      cuda_geo_nr_Bfield_pushJ_vlo_get_struct_len(&(structlen));

      (((pthis)->nonrel_test_kernel)[0] = malloc(structlen));
      cuda_geo_nr_Bfield_pushJ_vlo_init(pe, ((pthis)->nonrel_test_kernel)[0]);
    }

    ((pthis)->cu_swap_l_6_kernel = malloc((sizeof(cuda_cu_swap_l_6_struct))));
    cuda_cu_swap_l_6_init(pe, (pthis)->cu_swap_l_6_kernel);

    ((pthis)->cu_swap_r_6_kernel = malloc((sizeof(cuda_cu_swap_r_6_struct))));
    cuda_cu_swap_r_6_init(pe, (pthis)->cu_swap_r_6_kernel);

    ((pthis)->move_back_kernel_6_kernel = malloc((sizeof(cuda_move_back_kernel_6_struct))));
    cuda_move_back_kernel_6_init(pe, (pthis)->move_back_kernel_6_kernel);

    ((pthis)->cu_swap_l_8_kernel = malloc((sizeof(cuda_cu_swap_l_8_struct))));
    cuda_cu_swap_l_8_init(pe, (pthis)->cu_swap_l_8_kernel);

    ((pthis)->cu_swap_r_8_kernel = malloc((sizeof(cuda_cu_swap_r_8_struct))));
    cuda_cu_swap_r_8_init(pe, (pthis)->cu_swap_r_8_kernel);

    ((pthis)->move_back_kernel_8_kernel = malloc((sizeof(cuda_move_back_kernel_8_struct))));
    cuda_move_back_kernel_8_init(pe, (pthis)->move_back_kernel_8_kernel);

    ((pthis)->dump_ene_num_kernel = malloc((sizeof(cuda_dump_ene_num_struct))));
    cuda_dump_ene_num_init(pe, (pthis)->dump_ene_num_kernel);

    ((sort_kernel)[0] = malloc((sizeof(cuda_gpu_sort_one_grid_x_6_struct))));
    ((sort_kernel)[1] = malloc((sizeof(cuda_sort_one_grid_x_6_struct))));
    cuda_gpu_sort_one_grid_x_6_init(pe, (sort_kernel)[0]);

    cuda_sort_one_grid_x_6_init(pe, (sort_kernel)[1]);

    ((sort_kernel)[2] = malloc((sizeof(cuda_gpu_sort_one_grid_y_6_struct))));
    ((sort_kernel)[3] = malloc((sizeof(cuda_sort_one_grid_y_6_struct))));
    cuda_gpu_sort_one_grid_y_6_init(pe, (sort_kernel)[2]);

    cuda_sort_one_grid_y_6_init(pe, (sort_kernel)[3]);

    ((sort_kernel)[4] = malloc((sizeof(cuda_gpu_sort_one_grid_z_6_struct))));
    ((sort_kernel)[5] = malloc((sizeof(cuda_sort_one_grid_z_6_struct))));
    cuda_gpu_sort_one_grid_z_6_init(pe, (sort_kernel)[4]);

    cuda_sort_one_grid_z_6_init(pe, (sort_kernel)[5]);

    ((sort_kernel)[6] = malloc((sizeof(cuda_gpu_sort_one_grid_x_vlo_6_struct))));
    ((sort_kernel)[7] = malloc((sizeof(cuda_sort_one_grid_x_vlo_6_struct))));
    cuda_gpu_sort_one_grid_x_vlo_6_init(pe, (sort_kernel)[6]);

    cuda_sort_one_grid_x_vlo_6_init(pe, (sort_kernel)[7]);

    ((sort_kernel)[8] = malloc((sizeof(cuda_gpu_sort_one_grid_y_vlo_6_struct))));
    ((sort_kernel)[9] = malloc((sizeof(cuda_sort_one_grid_y_vlo_6_struct))));
    cuda_gpu_sort_one_grid_y_vlo_6_init(pe, (sort_kernel)[8]);

    cuda_sort_one_grid_y_vlo_6_init(pe, (sort_kernel)[9]);

    ((sort_kernel)[10] = malloc((sizeof(cuda_gpu_sort_one_grid_z_vlo_6_struct))));
    ((sort_kernel)[11] = malloc((sizeof(cuda_sort_one_grid_z_vlo_6_struct))));
    cuda_gpu_sort_one_grid_z_vlo_6_init(pe, (sort_kernel)[10]);

    cuda_sort_one_grid_z_vlo_6_init(pe, (sort_kernel)[11]);

    ((sort_kernel)[12] = malloc((sizeof(cuda_gpu_sort_one_grid_x_8_struct))));
    ((sort_kernel)[13] = malloc((sizeof(cuda_sort_one_grid_x_8_struct))));
    cuda_gpu_sort_one_grid_x_8_init(pe, (sort_kernel)[12]);

    cuda_sort_one_grid_x_8_init(pe, (sort_kernel)[13]);

    ((sort_kernel)[14] = malloc((sizeof(cuda_gpu_sort_one_grid_y_8_struct))));
    ((sort_kernel)[15] = malloc((sizeof(cuda_sort_one_grid_y_8_struct))));
    cuda_gpu_sort_one_grid_y_8_init(pe, (sort_kernel)[14]);

    cuda_sort_one_grid_y_8_init(pe, (sort_kernel)[15]);

    ((sort_kernel)[16] = malloc((sizeof(cuda_gpu_sort_one_grid_z_8_struct))));
    ((sort_kernel)[17] = malloc((sizeof(cuda_sort_one_grid_z_8_struct))));
    cuda_gpu_sort_one_grid_z_8_init(pe, (sort_kernel)[16]);

    cuda_sort_one_grid_z_8_init(pe, (sort_kernel)[17]);

    ((sort_kernel)[18] = malloc((sizeof(cuda_gpu_sort_one_grid_x_vlo_8_struct))));
    ((sort_kernel)[19] = malloc((sizeof(cuda_sort_one_grid_x_vlo_8_struct))));
    cuda_gpu_sort_one_grid_x_vlo_8_init(pe, (sort_kernel)[18]);

    cuda_sort_one_grid_x_vlo_8_init(pe, (sort_kernel)[19]);

    ((sort_kernel)[20] = malloc((sizeof(cuda_gpu_sort_one_grid_y_vlo_8_struct))));
    ((sort_kernel)[21] = malloc((sizeof(cuda_sort_one_grid_y_vlo_8_struct))));
    cuda_gpu_sort_one_grid_y_vlo_8_init(pe, (sort_kernel)[20]);

    cuda_sort_one_grid_y_vlo_8_init(pe, (sort_kernel)[21]);

    ((sort_kernel)[22] = malloc((sizeof(cuda_gpu_sort_one_grid_z_vlo_8_struct))));
    ((sort_kernel)[23] = malloc((sizeof(cuda_sort_one_grid_z_vlo_8_struct))));
    cuda_gpu_sort_one_grid_z_vlo_8_init(pe, (sort_kernel)[22]);

    cuda_sort_one_grid_z_vlo_8_init(pe, (sort_kernel)[23]);

    {
      cuda_pscmc_mem_init(pe, (pthis)->inoutput, PS_DOUBLE_NUM,
                          (6 * (grid_cache_len * (xlen * (ylen * (zlen * numvec))))));

      char *tmp_h_data;

      cuda_pscmc_get_h_data((pthis)->inoutput, &(tmp_h_data));

      memset(tmp_h_data, 0, (sizeof(double) * (6 * (grid_cache_len * (xlen * (ylen * (zlen * numvec)))))));
    }
    {
      cuda_pscmc_mem_init(pe, (pthis)->xyzw, PS_INT_NUM, (4 * (xlen * (ylen * (zlen * numvec)))));

      char *tmp_h_data;

      cuda_pscmc_get_h_data((pthis)->xyzw, &(tmp_h_data));

      memset(tmp_h_data, 0, (sizeof(int) * (4 * (xlen * (ylen * (zlen * numvec))))));
    }
    {
      cuda_pscmc_mem_init(pe, (pthis)->cu_cache, PS_DOUBLE_NUM, (6 * (cu_cache_length * numvec)));

      char *tmp_h_data;

      cuda_pscmc_get_h_data((pthis)->cu_cache, &(tmp_h_data));

      memset(tmp_h_data, 0, (sizeof(double) * (6 * (cu_cache_length * numvec))));
    }
    {
      cuda_pscmc_mem_init(pe, (pthis)->cu_xyzw, PS_INT_NUM, (numvec * 4));

      char *tmp_h_data;

      cuda_pscmc_get_h_data((pthis)->cu_xyzw, &(tmp_h_data));

      memset(tmp_h_data, 0, (sizeof(int) * (numvec * 4)));
    }
    {
      cuda_pscmc_mem_init(pe, (pthis)->adjoint_vec_pids, PS_LONG_NUM, (numvec * 6));

      char *tmp_h_data;

      cuda_pscmc_get_h_data((pthis)->adjoint_vec_pids, &(tmp_h_data));

      memset(tmp_h_data, 0, (sizeof(long) * (numvec * 6)));
    }
    {
      cuda_pscmc_mem_init(pe, (pthis)->swap_len_buf, PS_INT_NUM, (numvec * 5));

      char *tmp_h_data;

      cuda_pscmc_get_h_data((pthis)->swap_len_buf, &(tmp_h_data));

      memset(tmp_h_data, 0, (sizeof(int) * (numvec * 5)));
    }
    {

      // defined from class One_Particle_Collection


      void *adjoint_vec_pids = (pthis)->adjoint_vec_pids;

      //====================One_Particle_Collection
      long *adjoint_vec_pids_host = (((long **)adjoint_vec_pids))[0];

      {
        long xyzz;

        for ((xyzz = 0); (xyzz < 1); (xyzz = (xyzz + 1))) {
          {
            long xyzy;

            for ((xyzy = 0); (xyzy < 1); (xyzy = (xyzy + 1))) {
              {
                long xyzx;

                for ((xyzx = 0); (xyzx < numvec); (xyzx = (xyzx + 1))) {
                  long *cur_adj_id = (adjoint_vec_pids_host + (6 * xyzx));

                  ((cur_adj_id)[0] = find_vec_id(
                       (adj_ids)[((xyzx * NUM_SYNC_LAYER) + (0 + (1 * (0 + (3 * (1 + (3 * 1)))))))], adj_ids, numvec));
                  ((cur_adj_id)[1] = find_vec_id(
                       (adj_ids)[((xyzx * NUM_SYNC_LAYER) + (0 + (1 * (2 + (3 * (1 + (3 * 1)))))))], adj_ids, numvec));
                  ((cur_adj_id)[2] = find_vec_id(
                       (adj_ids)[((xyzx * NUM_SYNC_LAYER) + (0 + (1 * (1 + (3 * (0 + (3 * 1)))))))], adj_ids, numvec));
                  ((cur_adj_id)[3] = find_vec_id(
                       (adj_ids)[((xyzx * NUM_SYNC_LAYER) + (0 + (1 * (1 + (3 * (2 + (3 * 1)))))))], adj_ids, numvec));
                  ((cur_adj_id)[4] = find_vec_id(
                       (adj_ids)[((xyzx * NUM_SYNC_LAYER) + (0 + (1 * (1 + (3 * (1 + (3 * 0)))))))], adj_ids, numvec));
                  ((cur_adj_id)[5] = find_vec_id(
                       (adj_ids)[((xyzx * NUM_SYNC_LAYER) + (0 + (1 * (1 + (3 * (1 + (3 * 2)))))))], adj_ids, numvec));
                }
              }
            }
          }
        }
      }
      cuda_pscmc_mem_sync_h2d(adjoint_vec_pids);
    }
  }
  return 0;
}

int init_particle_mpi(Field3D_MPI *pthis, int num_spec, double *Mass, double *Charge,
                      double *Number_particle_per_marker, long *grid_cache_len, long *cu_cache_length) {
  ((pthis)->num_spec = num_spec);
  long num_runtime = (pthis)->num_runtime;

  ((pthis)->particles = malloc((sizeof(One_Particle_Collection) * (num_spec * num_runtime))));
  int i;

  int j;

  for (i = 0; (i < num_spec); i++) {
    for (j = 0; (j < num_runtime); j++) {

      // defined from class Field3D_Seq


      long numvec = (((pthis)->data + j))->numvec;


      long *global_id = (((pthis)->data + j))->global_id;


      //====================Field3D_Seq
      init_particle(((pthis)->particles + ((i * num_runtime) + j)), ((pthis)->data + j), (Mass)[i], (Charge)[i],
                    (Number_particle_per_marker)[i],
                    ((grid_cache_len)[i] * ((USE_NON_UNI_CACHE_DIST) ? (({
                       double cplx = 0.00000000000000000e+00;

                       {
                         long k;

                         for ((k = 0); (k < numvec); (k = (k + 1))) {
                           double new_cplx = call_GET_NON_UNI_CACHE_DIST(i, (global_id)[k]);

                           if ((new_cplx > cplx)) {
                             (cplx = new_cplx);
                           }
                         }
                       }
                       cplx;
                     }))
                                                                     : (1))),
                    ((cu_cache_length)[i] * ((USE_NON_UNI_CACHE_DIST) ? (({
                       double cplx = 0.00000000000000000e+00;

                       {
                         long k;

                         for ((k = 0); (k < numvec); (k = (k + 1))) {
                           double new_cplx = call_GET_NON_UNI_CACHE_DIST(i, (global_id)[k]);

                           if ((new_cplx > cplx)) {
                             (cplx = new_cplx);
                           }
                         }
                       }
                       cplx;
                     }))
                                                                      : (1))));
    }
  }
  return 0;
}

int init_non_uni_particle_opc(One_Particle_Collection *pthis, int tgrid_load, int cur_sp, double VT, double vmax,
                              int ptlen) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;


  void *cu_xyzw = (pthis)->cu_xyzw;


  //====================One_Particle_Collection
  {

    // defined from class One_Particle_Collection
    Field3D_Seq *pfield = (pthis)->pfield;


    long grid_cache_len = (pthis)->grid_cache_len;


    void *inoutput = (pthis)->inoutput;

    void *xyzw = (pthis)->xyzw;


    //====================One_Particle_Collection

    // defined from class Field3D_Seq

    long xlen = (pfield)->xlen;

    long ylen = (pfield)->ylen;

    long zlen = (pfield)->zlen;


    long numvec = (pfield)->numvec;


    long *global_x_offset = (pfield)->global_x_offset;

    long *global_y_offset = (pfield)->global_y_offset;

    long *global_z_offset = (pfield)->global_z_offset;

    long *global_id = (pfield)->global_id;


    //====================Field3D_Seq
    long alllenoff = (xlen * (ylen * zlen));

    long cur_pcid;

    double *host_data = (((double **)inoutput))[0];

    int *xyzw_data = (((int **)xyzw))[0];

    for (cur_pcid = 0; (cur_pcid < numvec); cur_pcid++) {
      double *grid_r_0 = (host_data + (cur_pcid * (alllenoff * (6 * grid_cache_len))));

      int *xyzw_0 = (xyzw_data + (cur_pcid * (alllenoff * 4)));

      {
        long xyzz;

        for ((xyzz = 0); (xyzz < zlen); (xyzz = (xyzz + 1))) {
          {
            long xyzy;

            for ((xyzy = 0); (xyzy < ylen); (xyzy = (xyzy + 1))) {
              {
                long xyzx;

                for ((xyzx = 0); (xyzx < xlen); (xyzx = (xyzx + 1))) {
                  double *grid_r = (grid_r_0 + (0 + ((6 * grid_cache_len) * (xyzx + (xlen * (xyzy + (ylen * xyzz)))))));

                  int *grid_xyzw = (xyzw_0 + (0 + (4 * (xyzx + (xlen * (xyzy + (ylen * xyzz)))))));

                  long l = 0;

                  long grid_load = (call_GET_INIT_DENSITY_DIST(
                                        cur_sp, ((global_z_offset)[cur_pcid] + (xyzz + 5.00000000000000000e-01)),
                                        ((global_y_offset)[cur_pcid] + (xyzy + 5.00000000000000000e-01)),
                                        ((global_x_offset)[cur_pcid] + (xyzx + 5.00000000000000000e-01))) *
                                    tgrid_load);

                  if ((grid_load > grid_cache_len)) {
                    fprintf(stderr, "Error, gl=%ld gcl=%ld global_id=%ld cur_picid=%ld\n", grid_load, grid_cache_len,
                            (global_id)[cur_pcid], cur_pcid);
                  }

                  assert((grid_load <= grid_cache_len));
                  double vx_ijk = 0;

                  double vy_ijk = 0;

                  double vz_ijk = 0;

                  if (USE_INIT_V0) {
                    (vx_ijk =
                         call_GET_INIT_V0_x(cur_sp, ((global_z_offset)[cur_pcid] + (xyzz + 5.00000000000000000e-01)),
                                            ((global_y_offset)[cur_pcid] + (xyzy + 5.00000000000000000e-01)),
                                            ((global_x_offset)[cur_pcid] + (xyzx + 5.00000000000000000e-01))));
                    (vy_ijk =
                         call_GET_INIT_V0_y(cur_sp, ((global_z_offset)[cur_pcid] + (xyzz + 5.00000000000000000e-01)),
                                            ((global_y_offset)[cur_pcid] + (xyzy + 5.00000000000000000e-01)),
                                            ((global_x_offset)[cur_pcid] + (xyzx + 5.00000000000000000e-01))));
                    (vz_ijk =
                         call_GET_INIT_V0_z(cur_sp, ((global_z_offset)[cur_pcid] + (xyzz + 5.00000000000000000e-01)),
                                            ((global_y_offset)[cur_pcid] + (xyzy + 5.00000000000000000e-01)),
                                            ((global_x_offset)[cur_pcid] + (xyzx + 5.00000000000000000e-01))));
                  }

                  double tempx = 1;

                  double tempy = 1;

                  double tempz = 1;

                  if (USE_NON_UNI_TEMPERATURE) {
                    (tempx = call_GET_INIT_TEMPERATURE_DIST(
                         cur_sp, ((global_z_offset)[cur_pcid] + (xyzz + 5.00000000000000000e-01)),
                         ((global_y_offset)[cur_pcid] + (xyzy + 5.00000000000000000e-01)),
                         ((global_x_offset)[cur_pcid] + (xyzx + 5.00000000000000000e-01)), 0));
                    (tempy = call_GET_INIT_TEMPERATURE_DIST(
                         cur_sp, ((global_z_offset)[cur_pcid] + (xyzz + 5.00000000000000000e-01)),
                         ((global_y_offset)[cur_pcid] + (xyzy + 5.00000000000000000e-01)),
                         ((global_x_offset)[cur_pcid] + (xyzx + 5.00000000000000000e-01)), 1));
                    (tempz = call_GET_INIT_TEMPERATURE_DIST(
                         cur_sp, ((global_z_offset)[cur_pcid] + (xyzz + 5.00000000000000000e-01)),
                         ((global_y_offset)[cur_pcid] + (xyzy + 5.00000000000000000e-01)),
                         ((global_x_offset)[cur_pcid] + (xyzx + 5.00000000000000000e-01)), 2));
                  }

                  for (l; (l < grid_load); l++) {
                    ((grid_xyzw)[0] = grid_load);
                    double *xyzvs = (grid_r + (l * ptlen));

                    ((xyzvs)[0] = rand01(xyzx, (xyzx + 1)));
                    ((xyzvs)[1] = rand01(xyzy, (xyzy + 1)));
                    ((xyzvs)[2] = rand01(xyzz, (xyzz + 1)));
                  befmaxinit:

                    ((xyzvs)[3] = maxwell_dist(vx_ijk, (tempx * VT)));
                    ((xyzvs)[4] = maxwell_dist(vy_ijk, (tempy * VT)));
                    ((xyzvs)[5] = maxwell_dist(vz_ijk, (tempz * VT)));
                    double vx = (xyzvs)[3];

                    double vy = (xyzvs)[4];

                    double vz = (xyzvs)[5];

                    if (((((vx * vx) + (vy * vy)) + (vz * vz)) >= vmax)) {
                      goto befmaxinit;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  {

    // defined from class Field3D_Seq


    long numvec = (pfield)->numvec;


    //====================Field3D_Seq
    memset((((int **)cu_xyzw))[0], 0, (4 * (sizeof(int) * numvec)));
    cuda_pscmc_mem_sync_h2d(inoutput);

    cuda_pscmc_mem_sync_h2d(xyzw);

    cuda_pscmc_mem_sync_h2d(cu_xyzw);
  }
  return 0;
}
int init_non_uni_particle_fmpi(Field3D_MPI *pthis, double vmax) {

  // defined from class Field3D_MPI

  long num_runtime = (pthis)->num_runtime;


  int num_spec = (pthis)->num_spec;


  //====================Field3D_MPI
  int i;

  int j;

  for (i = 0; (i < num_spec); i++) {
    if (srand_seed) {
      srand(srand_seed);
    }

    int ptype = ((((Particle_in_Cell_MPI *)pthis))->o_particle_type)[i];

    int ptlen = (((ptype & 2)) ? (8) : (6));

    if ((((((Particle_in_Cell_MPI *)pthis))->o_particle_type)[i] != 1)) {
      fprintf(stderr, "info init_non_uni_particle_fmpi: spec=%d\n", i);
      for (j = 0; (j < num_runtime); j++) {
        init_non_uni_particle_opc(((pthis)->particles + ((i * num_runtime) + j)), call_GET_INIT_LOAD(i), i,
                                  call_GET_INIT_VT(i), vmax, ptlen);
      }
    }
  }
  return 0;
}

void init_global_particles(Particle_in_Cell_MPI *pthis, Field3D_MPI *fE, Field3D_MPI *fE2x, Field3D_MPI *fEN,
                           int use_small_num_grids, int pml_abc_dir, int pml_level, double pml_sigma_max, double deltat,
                           int num_spec, long *allxyzmax, double *massp, double *chargep, double *npm,
                           long *grid_cache_len, long *cu_cache_len, int *particle_types, int reduce_dim,
                           double r_x_rat, double r_y_rat, double r_z_rat, double random_rate, int use_vlo_o,
                           int use_rel_ncr1) {

  // defined from class Particle_in_Cell_MPI


  int use_rel_ncr = (pthis)->use_rel_ncr;


  //====================Particle_in_Cell_MPI
  init_Field3D_MPI_from(&((pthis)->MPI_fieldE), fE);
  init_Field3D_MPI_from(&((pthis)->MPI_fieldB), fE);
  init_Field3D_MPI_from(&((pthis)->MPI_fieldE_ext), fE);
  init_Field3D_MPI_from(&((pthis)->MPI_fieldB_ext), fE);
  init_Field3D_MPI_from(&((pthis)->MPI_fieldE_filter), fE);
  init_Field3D_MPI_from(&((pthis)->MPI_fieldB_filter), fE);
  init_Field3D_MPI_from(&((pthis)->MPI_fieldEtmp), fE);
  init_Field3D_MPI_from(&((pthis)->MPI_fieldEtmp1), fE);
  init_Field3D_MPI_from(&((pthis)->MPI_fieldE1), fE);
  init_Field3D_MPI_from(&((pthis)->MPI_fieldEtmp2), fE);
  init_Field3D_MPI_from(&((pthis)->MPI_fieldBtmp), fE);
  ((pthis)->use_rel_ncr = use_rel_ncr1);
  (use_rel_ncr = use_rel_ncr1);
  if (use_rel_ncr) {
    init_Field3D_MPI_from(&((pthis)->MPI_fieldE01_2x), fE2x);
    init_Field3D_MPI_from(&((pthis)->MPI_fieldB0_2x), fE2x);
  }

  ((pthis)->o_particle_type = particle_types);
  ((pthis)->use_vlo = use_vlo_o);
  int use_small_ts = 0;

  {
    long i;

    for ((i = 0); (i < num_spec); (i = (i + 1))) {
      (use_small_ts = (use_small_ts + (particle_types)[i]));
    }
  }
  ((pthis)->use_pml_abc_dir = pml_abc_dir);
  ((pthis)->use_pml_level = pml_level);
  ((pthis)->use_pml_sigma_max = pml_sigma_max);
  if (pml_abc_dir) {
    init_Field3D_MPI_from(&((pthis)->MPI_fieldPMLB), fE);
    init_Field3D_MPI_from(&((pthis)->MPI_fieldPMLE), fE);
    blas_yiszero_Field3D_MPI(&((pthis)->MPI_fieldPMLB), &((pthis)->MPI_fieldPMLB));
    blas_yiszero_Field3D_MPI(&((pthis)->MPI_fieldPMLE), &((pthis)->MPI_fieldPMLE));
    ((pthis)->allxmax = (allxyzmax)[0]);
    ((pthis)->allymax = (allxyzmax)[1]);
    ((pthis)->allzmax = (allxyzmax)[2]);
  }

  if (((USE_FILTER == 2) || use_small_ts)) {
    init_Field3D_MPI_from(&((pthis)->MPI_fieldBtmp1), fE);
  }

  init_Field3D_MPI_from(&((pthis)->MPI_fieldB1), fE);
  init_Field3D_MPI_from(&((pthis)->MPI_FoutJ), fE);
  init_Field3D_MPI_from(&((pthis)->MPI_FoutJtmp), fE);
  ((pthis)->use_small_grid = 0);
  if ((use_small_num_grids == 1)) {
    init_Field3D_MPI_from_new_num_ele(&((pthis)->MPI_LFoutJ), fE, 375);
    ((pthis)->use_small_grid = 1);

  } else {
    if ((use_small_num_grids == 2)) {
      build_Field_compute_unit_from_mpi_field(&((pthis)->MPI_LFoutJ), fE);
      ((pthis)->use_small_grid = 2);
    }
  }

  ((pthis)->pMPI_FoutEN = fEN);
  if (USE_FILTER) {
    init_external_field3d_FILTER_E(&((pthis)->MPI_fieldE_filter));
    init_external_field3d_FILTER_B(&((pthis)->MPI_fieldB_filter));
    sync_main_data_h2d(&((pthis)->MPI_fieldE_filter));
    sync_main_data_h2d(&((pthis)->MPI_fieldB_filter));
  }

  if (USE_INIT_EXT_EB) {
    init_external_field3d_E_2d_extend(&((pthis)->MPI_fieldE_ext), reduce_dim, r_x_rat, r_y_rat, r_z_rat);
    init_external_field3d_B_2d_extend(&((pthis)->MPI_fieldB_ext), reduce_dim, (r_y_rat * r_z_rat), (r_x_rat * r_z_rat),
                                      (r_x_rat * r_y_rat));
    sync_main_data_h2d(&((pthis)->MPI_fieldE_ext));
    sync_main_data_h2d(&((pthis)->MPI_fieldB_ext));
  }

  if (USE_INIT_EB0) {
    init_external_field3d_E0_2d_extend_rand(&((pthis)->MPI_fieldE), reduce_dim, r_x_rat, r_y_rat, r_z_rat, random_rate);
    init_external_field3d_B0_2d_extend_rand(&((pthis)->MPI_fieldB), reduce_dim, (r_y_rat * r_z_rat),
                                            (r_x_rat * r_z_rat), (r_x_rat * r_y_rat), random_rate);

  } else {
    test_set_mainland(&(pthis->MPI_fieldB), 0.00000000000000000e+00);
    test_set_mainland(&(pthis->MPI_fieldE), 0.00000000000000000e+00);
  }

  sync_main_data_h2d(&((pthis)->MPI_fieldE));
  sync_main_data_h2d(&((pthis)->MPI_fieldB));
  blas_yisax_Field3D_MPI(&((pthis)->MPI_fieldB1), &((pthis)->MPI_fieldB1), 1.00000000000000000e+00,
                         &((pthis)->MPI_fieldB));
  if (use_rel_ncr) {
    blas_yiszero_synced_Field3D_MPI(&((pthis)->MPI_fieldE01_2x), &((pthis)->MPI_fieldE01_2x));
    blas_yiszero_synced_Field3D_MPI(&((pthis)->MPI_fieldB0_2x), &((pthis)->MPI_fieldB0_2x));
    blas_yisax_enlarge_Field3D_MPI(&((pthis)->MPI_fieldE), &((pthis)->MPI_fieldE01_2x), 1.00000000000000000e+00,
                                   &((pthis)->MPI_fieldE));
    blas_yisax_enlarge_Field3D_MPI(&((pthis)->MPI_fieldB), &((pthis)->MPI_fieldB0_2x), 1, &((pthis)->MPI_fieldB));
  }

  ((pthis)->pMPI_FoutJ = &((pthis)->MPI_FoutJ));
  init_particle_mpi(&((pthis)->MPI_fieldE), num_spec, massp, chargep, npm, grid_cache_len, cu_cache_len);
  int num_runtime = ((pthis)->MPI_fieldE).num_runtime;

  {
    long i;

    for ((i = 0); (i < (num_spec * num_runtime)); (i = (i + 1))) {
      (((((pthis)->MPI_fieldE).particles + i))->pfieldE = (((pthis)->MPI_fieldE).data + (i % num_runtime)));
      (((((pthis)->MPI_fieldE).particles + i))->pfieldB = (((pthis)->MPI_fieldB).data + (i % num_runtime)));
      (((((pthis)->MPI_fieldE).particles + i))->pFoutJ = (((pthis)->MPI_FoutJ).data + (i % num_runtime)));
      (((((pthis)->MPI_fieldE).particles + i))->pLFoutJ =
           ((use_small_num_grids) ? ((((pthis)->MPI_LFoutJ).data + (i % num_runtime))) : (NULL)));
      (((((pthis)->MPI_fieldE).particles + i))->pFoutEN = (((pthis)->pMPI_FoutEN)->data + (i % num_runtime)));
    }
  }
  ((pthis)->dt = deltat);
}
