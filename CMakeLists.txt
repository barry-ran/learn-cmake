cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "all")

# 配置mymath
option(USE_MYMATH "Use mymath provided math implementation" ON)

# 声明项目
project(${PROJECT_NAME})

# 添加子项目
# https://cmake.org/cmake/help/latest/guide/tutorial/index.html#a-basic-starting-point-step-1
add_subdirectory(example)
add_subdirectory(version)

# mymath作为可选项
if(USE_MYMATH)
    add_subdirectory(mymath)
    # 指定example添加头文件路径（mymath内部已经指定）
    # target_include_directories(example PUBLIC "${PROJECT_SOURCE_DIR}/mymath")
    # 指定example链接mymath
    target_link_libraries(example mymath)
endif()

# 测试
enable_testing()
add_test(NAME example COMMAND example)
add_test(NAME version COMMAND version)
