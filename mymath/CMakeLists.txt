cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "mymath")

# 声明项目
project(${PROJECT_NAME})

# 定义静态库
add_library(${PROJECT_NAME} STATIC mymath.cpp)
