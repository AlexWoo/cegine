cmake_minimum_required(VERSION 3.10)

project(ce_base_test)

##################################################
# 预设置
##################################################
set(cmake_cxx_standard 11)
set(cmake_c_compiler gcc)
set(cmake_cxx_compiler g++)

set(ROOT_DIR ../../)

include_directories(${ROOT_DIR}/tester ../)
include_directories(${ROOT_DIR}/base ../)

##################################################
# 源文件
##################################################
aux_source_directory(${ROOT_DIR}/tester CETESTER_DIR)
message("cetester directory ${CETESTER_DIR}")

aux_source_directory(${ROOT_DIR}/base CEBASE_DIR)
message("base directory ${BASE_DIR}")

##################################################
# 目标文件
##################################################
add_library(cetester ${CETESTER_DIR})
add_library(cebase ${CEBASE_DIR})

add_executable(files ce_files_test.cpp)
target_link_libraries(files cetester cebase)
