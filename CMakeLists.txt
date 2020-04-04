cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "all")
project(${PROJECT_NAME})

# ---------- 应用程序 ----------
add_subdirectory(HelloWorld)

# 安装
install(TARGETS HelloWorld)

# 测试
enable_testing()
add_test(NAME HelloWorld COMMAND HelloWorld)
