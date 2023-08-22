cmake_minimum_required(VERSION 3.14)

project(assignment4)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_SRCS)

add_executable(assignment4 ${DIR_SRCS})