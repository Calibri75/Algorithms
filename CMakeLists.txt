cmake_minimum_required(VERSION 3.29)
project(ASD)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB3
        LAB3/src/struct/struct.h
        LAB3/src/search/search.cpp
        LAB3/LAB3.cpp
        LAB3/src/search/search.h
        LAB3/src/file_work/LAB3_file_work.cpp
        LAB3/src/file_work/LAB3_file_work.h
        LAB3/src/file_generation/file_generetion.cpp
        LAB3/src/file_generation/file_generation.h
)

