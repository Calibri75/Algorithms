cmake_minimum_required(VERSION 3.29)
project(ASD)

set(CMAKE_CXX_STANDARD 20)

add_executable(ASD main.cpp)
add_executable(LAB1 ASD/LAB1/LAB1.cpp)
add_executable(LAB1_save ASD/LAB1/LAB1_last_save.cpp)
add_executable(LAB1_edited ASD/LAB1/LAB1_edited.cpp)
add_executable(ASD_lecture ASD/ASD_lecture.cpp)
add_executable(LAB1_R ASD/asdpractice1.cpp)
add_executable(LAB2 ASD/LAB2.cpp
)