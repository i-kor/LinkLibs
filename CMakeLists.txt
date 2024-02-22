cmake_minimum_required(VERSION 3.11)
project(LinkLibs)
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

# # Google Logging Library

# # Add as a subdirectory
# add_subdirectory(c:/dev/glog c:/dev/glog/build)
# target_link_libraries(${PROJECT_NAME} glog)

# set(BUILD_SHARED_LIBS OFF)
# set(BUILD_TESTING OFF)
# set(WITH_FUZZING OFF)
# set(WITH_GFLAGS OFF)
# set(WITH_GTEST OFF)
# set(WITH_PKGCONFIG OFF)
# set(WITH_SYMBOLIZE OFF)
# set(WITH_TLS OFF)
# set(WITH_UNWIND OFF)

# Add as library installed to c:/libs/glog
set(glog_DIR C:/libs/glog/lib/cmake/glog) #contains glog-config.cmake for find_package config mode
find_package (glog 0.7.0 REQUIRED)
target_link_libraries (${PROJECT_NAME} PRIVATE glog::glog)

# Google Test Library
# Fetch as a remote repository
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG main
)
FetchContent_MakeAvailable(googletest)
include_directories(${googletest_SOURCE_DIR}/googletest/include)
target_link_libraries(${PROJECT_NAME} PRIVATE gtest)




