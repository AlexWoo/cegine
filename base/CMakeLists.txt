cmake_minimum_required(VERSION 3.10)

project(ce_base)

##################################################
# 预设置
##################################################
set(cmake_cxx_standard 11)
set(cmake_c_compiler gcc)
set(cmake_cxx_compiler g++)

##################################################
# 源文件
##################################################
aux_source_directory(. SRC_DIR)
message("source directory ${SRC_DIR}")

##################################################
# 目标文件
##################################################
add_library(cebase ${SRC_DIR})

##################################################
# 安装目录
##################################################
# set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../)
install(TARGETS cebase DESTINATION lib)
file(GLOB INC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
install(FILES ${INC_FILES} DESTINATION include/base)
