cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "mymath")

# 声明项目
project(${PROJECT_NAME})

# 定义静态库
add_library(${PROJECT_NAME} STATIC mymath.cpp)

# 指定要求依赖当前库的库都添加此包含目录
# INTERFACE是指消费者需要的东西，而生产者则不需要
target_include_directories(${PROJECT_NAME}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
