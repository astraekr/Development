cmake_minimum_required(VERSION 2.8)
project(GetBosonOneShot)
add_executable(${PROJECT_NAME} "getbosononeshot.cpp")

message("${CMAKE_MODULE_PATH}")

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/libuvc")

message("${CMAKE_MODULE_PATH}")

find_package (OpenCV REQUIRED)
find_package (libuvc REQUIRED)
if (NOT libuvc_FOUND)
    message(FATAL_ERROR "libuvc not found")
endif (NOT libuvc_FOUND)

message("${libuvc_LIBRARIES}")
message("${libuvc_FOUND}")
message("${OpenCV_LIBS}")

target_link_libraries ( GetBosonOneShot ${OpenCV_LIBS} ${libuvc_LIBRARIES})
