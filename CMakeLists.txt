cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "all")

# 声明项目
project(${PROJECT_NAME})

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/mymath")

# 添加子项目
add_subdirectory(mymath)
add_subdirectory(helloworld)
add_subdirectory(version)

# helloworld 链接math
target_link_libraries(helloworld mymath)

# 安装
install(TARGETS helloworld)
install(TARGETS version)

# 测试
enable_testing()
add_test(NAME helloworld COMMAND helloworld)
add_test(NAME version COMMAND version)
