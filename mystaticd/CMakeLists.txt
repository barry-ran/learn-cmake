cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "mystaticd")

# 声明项目
project(${PROJECT_NAME})

# GNU编译器 静态库想让动态库依赖的话，需要增加-fPIC编译选项
if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
endif()

# 定义动态库
add_library(${PROJECT_NAME} STATIC mystaticd.cpp)

# 指定要求依赖当前库的库都添加此包含目录
# INTERFACE是指消费者需要的东西，而生产者则不需要
target_include_directories(${PROJECT_NAME}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# 安装当前库动态库到bin目录，静态库到lib目录
install(TARGETS ${PROJECT_NAME} 
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
)
# 安装头文件到include目录
install(FILES mystaticd.h DESTINATION include)
