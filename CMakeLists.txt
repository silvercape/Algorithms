cmake_minimum_required(VERSION 3.21)
project(Algorithms)
set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_subdirectory(基础数据结构/堆/小根堆)
add_executable(math 基础数据结构/链表/约瑟夫问题/math.cpp)



add_executable(main 图论/最短路径/Dijkstra/main.cpp)

add_executable(test "图论/拓扑排序/基于BFS/Following order/test.cpp")
