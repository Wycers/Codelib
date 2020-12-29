cmake_minimum_required(VERSION 3.10)

project(untitled5)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/node)
include_directories(${CMAKE_SOURCE_DIR}/src/error)
include_directories(${CMAKE_SOURCE_DIR}/src/ir)
include_directories(${CMAKE_SOURCE_DIR}/src/symbol_table)
include_directories(${CMAKE_SOURCE_DIR}/src/semantic_analysis)
include_directories(${CMAKE_SOURCE_DIR}/src/optimizer)


add_executable(splc
        main.cpp
        src/error/error.cpp
        src/node/node.cpp
        src/semantic_analysis/semantic_analysis.hpp
        src/semantic_analysis/basic.hpp
        src/ir/ir.hpp
        src/ir/ir_generator.hpp
        src/optimizer/optimizer.hpp
        src/optimizer/cfg.cpp
        src/optimizer/dag.cpp
    )
