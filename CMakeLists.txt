cmake_minimum_required(VERSION 3.28)
project(GraphColoringABC)

set(CMAKE_CXX_STANDARD 20)

add_executable(GraphColoringABC main.cpp
        Node/Node.h
        Node/Node.cpp
        Utils.h
        Graph/Graph.h
        Graph/Graph.cpp
        RandomGenerator/RandomGenerator.h
        RandomGenerator/RandomGenerator.cpp
        AlgorithmABC/AlgorithmABC.h
        AlgorithmABC/AlgorithmABC.cpp)
