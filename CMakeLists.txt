cmake_minimum_required(VERSION 3.29)
project(ASD)

set(CMAKE_CXX_STANDARD 20)


add_executable(LAB2 LAB2/LAB2.cpp
        LAB2/src/file_work/file_work.cpp
        LAB2/src/file_work/file_work.h
        LAB2/src/sorts/sorts.cpp
        LAB2/src/sorts/sorts.h
        LAB2/src/structs/structs.h
)

add_executable(LAB3
        LAB3/src/struct/struct.h
        LAB3/src/search/search.hpp
        LAB3/src/search/search.cpp
        LAB3/LAB3.cpp
)
