cmake_minimum_required(VERSION 3.16)

# 项目名称
project(learn-cmake)

add_executable(main main.cpp)

install(TARGETS main)

enable_testing()
add_test(NAME main COMMAND main)
