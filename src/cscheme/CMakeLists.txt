add_library(cscheme STATIC cscheme.c)
target_compile_definitions(cscheme PRIVATE CSCHEME_MAIN_PROC)
target_compile_options(cscheme PRIVATE -O2 -fPIC)

target_link_libraries(cscheme PRIVATE m)
