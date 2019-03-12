cmake_minimum_required(VERSION 2.8) 

project(Sort_lib)

set(SOURCE_LIB Sort_lib.cpp)		

set(HEADER_LIB Sort_lib.h)

set(SORT_LIB_DIR Sort_lib)

add_library(Sort_lib SHARED ${SOURCE_LIB} ${HEADER_LIB})