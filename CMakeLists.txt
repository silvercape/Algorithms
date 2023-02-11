cmake_minimum_required(VERSION 3.21)
project(Algorithms)
set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(main 基础算法/二分法/DeepInBinarySearch/main.cpp)
add_executable(math 基础数据结构/链表/约瑟夫问题/math.cpp)

