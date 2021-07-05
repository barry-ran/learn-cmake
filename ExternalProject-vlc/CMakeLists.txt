cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "ExternalProject-vlc")

# 声明项目
project(${PROJECT_NAME})

# 定义可执行程序
add_executable(${PROJECT_NAME} main.cpp)

# 执行install命令时要安装的文件
# 为执行install时指定的--prefix目录
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# cmake第三方依赖管理 https://github.com/xizhibei/blog/issues/134
# CMake FetchContent vs. ExternalProject https://www.scivision.dev/cmake-fetchcontent-vs-external-project/

# 下载vlc

# https://cmake.org/cmake/help/latest/module/ExternalProject.html
include(ExternalProject)
# 设置所有ExternalProject的base/PREFIX路径，优先级小于ExternalProject_Add内部指定的PREFIX
# set_property(DIRECTORY PROPERTY EP_BASE ${CMAKE_SOURCE_DIR}/third_party)
# set_property(DIRECTORY PROPERTY EP_PREFIX ${CMAKE_SOURCE_DIR}/third_party)


set(LIBVLC_DOWNLOAD_PATH "${CMAKE_SOURCE_DIR}/third_party/libvlc")
set(LIBVLC_VERSION "3.0.16")
set(LIBVLC_PLANTFORM "win32") # win32/win64/macosx
set(LIBVLC_CPU "win32") # win32/win64/arm64/intel64

ExternalProject_Add(libvlc
    PREFIX "libvlc" # 设置当前ExternalProject项目的前缀路径（默认下载/解压都在此目录下）
    URL http://download.videolan.org/pub/videolan/vlc/${LIBVLC_VERSION}/${LIBVLC_PLANTFORM}/vlc-${LIBVLC_VERSION}-${LIBVLC_CPU}.7z
    #URL http://download.videolan.org/pub/videolan/vlc/3.0.16/macosx/vlc-3.0.16-arm64.dmg # dmg直接改后缀名zip解压
    #URL_HASH MD5=32e4899c8302b61174fe925f65d2a3f1
    #DOWNLOAD_DIR "" # url下载路径    
    SOURCE_DIR ${LIBVLC_DOWNLOAD_PATH} # url下载解压路径/git clone路径
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

#add_custom_target(demo tar -xzf ${CMAKE_BINARY_DIR}/demo/src/bunny.tar.gz -C ${CMAKE_BINARY_DIR}/demo)

#add_dependencies(demo bunny)
