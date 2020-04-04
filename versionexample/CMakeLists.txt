cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "versionexample")

# 声明项目
project(${PROJECT_NAME})

set(VERSION_MAJOR 1)
set(VERSION_MINOR 3)
set(VERSION_PATCH 10)
 
# Config.h.in中可以访问cmake变量VERSION_MAJOR
# 编译的时候自动在编译目录生成Config.h
# to the source code
# PROJECT_SOURCE_DIR 当前工程目录
# CMAKE_CURRENT_SOURCE_DIR 当前CMakeLists.txt目录
# CMAKE_SOURCE_DIR 整个项目顶级目录
# PROJECT_BINARY_DIR 工程编译目录
configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
)

message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
 
# Config.h自动生成在编译目录，所以需要将编译目录增加到头文件包含路径
include_directories("${PROJECT_BINARY_DIR}")

# 定义可执行程序
add_executable(${PROJECT_NAME} main.cpp)
