cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "mymath")

# 声明项目
project(${PROJECT_NAME})

# 定义静态库
add_library(${PROJECT_NAME} STATIC mymath.cpp)

# 检查log/exp函数是否可用
include(CheckSymbolExists)
set(CMAKE_REQUIRED_LIBRARIES "m")
check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)

# 如果存在则添加相应的宏定义
if(HAVE_LOG AND HAVE_EXP)
    target_compile_definitions(${PROJECT_NAME}
        PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()

# 指定要求依赖当前库的库都添加此包含目录
# INTERFACE是指消费者需要的东西，而生产者则不需要
target_include_directories(${PROJECT_NAME}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# 安装当前库到lib目录
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
# 安装头文件到include目录
install(FILES mymath.h DESTINATION include)
