cmake_minimum_required(VERSION 3.5)

add_executable(untitled main.cpp ${MY_INCLUDE_DIR}/telephone.h telephone.cpp)
target_include_directories(untitled PUBLIC ${MY_INCLUDE_DIR})
