cmake_minimum_required(VERSION 3.10)

project(ce_tester)

##################################################
# 预设置
##################################################
set(cmake_cxx_standard 11)
set(cmake_c_compiler gcc)
set(cmake_cxx_compiler g++)

include_directories(../)

##################################################
# 源文件
##################################################
aux_source_directory(../ CETESTER_DIR)
message("cetester directory ${CETESTER_DIR}")

aux_source_directory(./ SRC_DIR)
message("source directory ${SRC_DIR}")

##################################################
# 目标文件
##################################################
add_library(cetester ${CETESTER_DIR})

add_executable(test ${SRC_DIR})
target_link_libraries(test cetester)
