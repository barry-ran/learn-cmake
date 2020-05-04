cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "all")

# https://cmake.org/cmake/help/latest/guide/tutorial/index.html#a-basic-starting-point-step-1
# https://github.com/Kitware/CMake/tree/master/Help/guide/tutorial/Complete

# 配置mymath
option(USE_MYMATH "Use mymath provided math implementation" ON)

# 声明项目
project(${PROJECT_NAME})

# 设置可执行程序、静态库、动态库都生成在同一个目录
# 以便在windows上不需要修改运行可执行文件的路径（windows上exe要和依赖的dll在同一目录）
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

# 添加子项目
add_subdirectory(example)
add_subdirectory(version)
add_subdirectory(myshared)

target_link_libraries(example myshared)

# 打印CMAKE_CXX_FLAGS
message(STATUS "all - CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

# mymath作为可选项
if(USE_MYMATH)
    add_subdirectory(mymath)
    # 指定example添加头文件路径（mymath内部已经指定）
    # target_include_directories(example PUBLIC "${PROJECT_SOURCE_DIR}/mymath")
    # 指定example链接mymath
    target_link_libraries(example mymath)
endif()

# 启用测试
enable_testing()

# 测试程序运行正常
add_test(NAME Runs COMMAND example 25)
add_test(NAME version COMMAND version)

# 测试usage消息是否正常
add_test(NAME Usage COMMAND example)
# 判断测试用例Usage的输出中是否包含"Usage:.*number"
set_tests_properties(Usage
    PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
)

# 定义一个简单的测试函数测试输出是否正常
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# 测试example的一些case
do_test(example 4 "4 is 2")
do_test(example 9 "9 is 3")
do_test(example 5 "5 is 2.236")
do_test(example 7 "7 is 2.645")
do_test(example 25 "25 is 5")
do_test(example -25 "-25 is [-nan|nan|0]")
do_test(example 0.0001 "0.0001 is 0.01")
