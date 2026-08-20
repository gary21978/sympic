/* SCALE compatibility shims for nvcc (Step 2: __DDR; Step 3: barrier/memcpy_async) */
#ifndef SCALE_COMPAT_H
#define SCALE_COMPAT_H

/* nvcc: empty macro — real SCALE toolchain supplies DDR address-space qualifier */
#ifndef __DDR
#define __DDR
#endif

#ifdef __CUDACC__
#include <cstddef>

#include <cuda/barrier>
#include <cooperative_groups.h>

namespace SCALE {
template <cuda::thread_scope Scope>
using barrier = cuda::barrier<Scope>;
}  // namespace SCALE

template <cuda::thread_scope Scope>
__device__ inline void init(cuda::barrier<Scope> *bar, std::size_t thread_count) {
  new (bar) cuda::barrier<Scope>(static_cast<std::ptrdiff_t>(thread_count));
}

using cuda::memcpy_async;
#endif /* __CUDACC__ */

#endif /* SCALE_COMPAT_H */
