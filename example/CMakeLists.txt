cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "example")

# 声明项目
project(${PROJECT_NAME})

configure_file (
    "${PROJECT_SOURCE_DIR}/Config.h.in"
    "${PROJECT_BINARY_DIR}/Config.h"
)

# Config.h自动生成在编译目录，所以需要将编译目录增加到头文件包含路径
include_directories("${PROJECT_BINARY_DIR}")

# 定义可执行程序
add_executable(${PROJECT_NAME} main.cpp)

# 执行install命令时要安装的文件
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/Config.h"
        DESTINATION include)
