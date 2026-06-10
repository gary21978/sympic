##清空再一键编
cd ~/symPIC
export CPATH=$CPATH:./
# 根目录生成物
make clean_all    # 删 SOURCES 里那些 .c

shopt -s extglob
# Delete generated headers, def files, static libraries
# Note: use ./ prefix to avoid --help.c.def.ss trap
rm -f ./!(cfgcst).h ./*.c.def.ss ./*.kernel.def.ss
rm -f ./c_yeefdtd.* ./openmp_yeefdtd.* ./cuda_yeefdtd.*
# Delete dependency cache
rm -rf .deps
# git checkout --  cfgcst.h   # 若有 git；或从备份 cp 回来

# 三个 backend（修复后的 cleanall）
make -C c_ cleanall
make -C openmp_ cleanall
make -C cuda_ cleanall
cd cuda_
rm -f ./*.kernel.scmc ./*.kernel_*.scmc ./*.kernel_runtime.* \
      ./*.kernel_inc.scmc ./cuda_pscmc.c.def.ss ./2
# DO NOT delete: RUNTIME_SPEC.mk  local_header.h
#                cuda_pscmc_cuda.scmc  cuda_pscmc_inc.scmc
cd ..

# 辅助库
make -C smallmpi clean
make -C cgapsio clean
# make -C cscheme clean    # 一般不必，除非改过 cscheme



# 1) smallmpi 先产出 small_mpi.c.def.ss
make -C smallmpi -j8
./gen_scmc_defs.sh smallmpi/small_mpi.c.def.ss
# 2) libsmallmpi.h：仅 MPI 原型，不含 pubdefs.h（由 libsmallmpi_header.scmc 生成）
make libsmallmpi.h
# 3) 公共类型头（Field3D_MPI 等，依赖 libsmallmpi.h）
scmc_compile_passes paravec.scmc C host pubdefs.h
# 4) 其余辅助库
make -C cgapsio -j8
make -C cscheme -j8

./compile.sh
