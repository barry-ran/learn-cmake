cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "math")

# 声明项目
project(${PROJECT_NAME})

# 定义静态库
add_library(math STATIC math.cpp)
