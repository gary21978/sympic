#ifndef KERNEL_INCLUDES_H
#define KERNEL_INCLUDES_H

#ifdef SYMPIC_CUDA
#include "cuda_/cuda_pscmc_inc.h"
#include "cuda_/general_partial_sort.kernel_inc.h"
#include "cuda_/geo_yeefdtd.kernel_inc.h"
#include "cuda_/inner_split_pass.kernel_inc.h"
#include "cuda_/mergefields.kernel_inc.h"
#include "cuda_/miniblas.kernel_inc.h"
#include "cuda_/move_back.kernel_inc.h"
#include "cuda_/particle_iter.kernel_inc.h"
#include "cuda_yeefdtd.h"
#endif

#ifdef SYMPIC_MAPU
#include "mapu_/mapu_pscmc.h"
#include "mapu_/inner_split_pass.kernel_runtime.h"
#include "mapu_/general_partial_sort.kernel_runtime.h"
#include "mapu_/geo_yeefdtd.kernel_runtime.h"
#include "mapu_/mergefields.kernel_runtime.h"
#include "mapu_/miniblas.kernel_runtime.h"
#include "mapu_/move_back.kernel_runtime.h"
#include "mapu_/particle_iter.kernel_runtime.h"
#endif

#endif