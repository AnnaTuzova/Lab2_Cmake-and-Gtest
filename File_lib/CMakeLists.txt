cmake_minimum_required(VERSION 2.8) 

project(File_lib)				

set(SOURCE_LIB File_lib.cpp)	
set(HEADER_LIB File_lib.h)

set(FILE_LIB_DIR File_lib)

add_library(File_lib STATIC ${SOURCE_LIB} ${HEADER_LIB})

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MTd")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")