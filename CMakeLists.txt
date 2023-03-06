cmake_minimum_required(VERSION 3.21)
project(Algorithms)
set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_subdirectory(基础数据结构/堆/小根堆)
add_executable(math 基础数据结构/链表/约瑟夫问题/math.cpp)



add_executable(main 动态规划/背包问题/宝物筛选/main.cpp)