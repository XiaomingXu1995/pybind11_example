cmake_minimum_required(VERSION 3.18)
project(example LANGUAGES CXX CUDA)

find_package(Python3 COMPONENTS Development REQUIRED)
find_package(pybind11 REQUIRED)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include_directories(/home/user_home/xiaomingxu/mambaforge/envs/ccdl/include/python3.10)

# 编译 CUDA 文件
add_library(cuda_lib example.cu)
target_include_directories(cuda_lib PRIVATE /home/user_home/xiaomingxu/mambaforge/envs/ccdl/lib/python3.10/site-packages/pybind11/include)

# 编译 pybind11 绑定文件
pybind11_add_module(example example.cpp)
target_link_libraries(example PRIVATE cuda_lib)
set_target_properties(cuda_lib PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

