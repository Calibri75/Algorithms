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
        LAB3/src/search/barier_search/barier.cpp
        LAB3/src/search/barier_search/barrier.hpp
)

add_executable(LAB4 LAB4/src/search/KMP/KMP.cpp
        LAB4/src/file_work/LAB4_file_work.cpp
        LAB4/LAB4.cpp
        LAB4/src/search/KMP/KMP.h
        LAB4/src/search/BMX/BMX.cpp)
