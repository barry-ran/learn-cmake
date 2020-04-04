cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "helloworld")

# 声明项目
project(${PROJECT_NAME})

# 定义可执行程序
add_executable(${PROJECT_NAME} main.cpp)
