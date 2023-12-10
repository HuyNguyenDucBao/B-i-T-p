cmake_minimum_required(VERSION 3.26)
project(untitled2 CUDA)

set(CMAKE_CUDA_STANDARD 17)

add_executable(untitled2 main.cu)

set_target_properties(untitled2 PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
