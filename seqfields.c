#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <assert.h>

#include "pubdefs.h"

#include "cuda_/cuda_pscmc_inc.h"

#include "cuda_/inner_split_pass.kernel_inc.h"



#include "cuda_/mergefields.kernel_inc.h"

#include "cuda_/miniblas.kernel_inc.h"

#include "cuda_/general_partial_sort.kernel_inc.h"

#include "cuda_/move_back.kernel_inc.h"

#include "cuda_/particle_iter.kernel_inc.h"


#include "cuda_/geo_yeefdtd.kernel_inc.h"

#include "cuda_yeefdtd.h"

#include "seqfields.h"

int build_Field_compute_unit_from_seq_field(Field3D_Seq *pthis, Field3D_Seq *input_E) {

  // defined from class Field3D_Seq


  //====================Field3D_Seq
  int num_cu = (cuda_blas_sum_get_num_compute_units(NULL));

  int new_num_ele = (num_cu * (input_E)->num_ele);

  fprintf(stderr, "newnumele=%d numcu=%d\n", new_num_ele, num_cu);
  ((pthis)[0] = (input_E)[0]);
  ((pthis)->num_ele = new_num_ele);
  return 0;
}
int build_Field_compute_unit_from_mpi_field(Field3D_MPI *pthis, Field3D_MPI *input_E) {

  // defined from class Field3D_MPI


  //====================Field3D_MPI
  ((pthis)[0] = (input_E)[0]);
  ((pthis)->data = malloc((sizeof(Field3D_Seq) * (input_E)->num_runtime)));
  {
    long i;

    for ((i = 0); (i < (input_E)->num_runtime); (i = (i + 1))) {
      build_Field_compute_unit_from_seq_field((pthis->data + i), (input_E->data + i));
    }
  }
}
