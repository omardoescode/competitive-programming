cmake_minimum_required(VERSION 3.29)
project(problem_solving)

set(CMAKE_CXX_STANDARD 14)

include_directories(algorithms)
include_directories(DataStructures)

add_executable(problem_solving
    algorithms/dijkstra.hpp
    algorithms/math.hpp
    algorithms/prim.hpp
    DataStructures/DSU.hpp
    DataStructures/MonotonicQueue.hpp
    DataStructures/MonotonicStack.hpp
    main.cpp)
