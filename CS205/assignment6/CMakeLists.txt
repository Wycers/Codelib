cmake_minimum_required(VERSION 3.10)

project(assignment6)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_SRCS)

add_executable(assignment6 ${DIR_SRCS})