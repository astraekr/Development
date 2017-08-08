cmake_minimum_required(VERSION 2.8)
project(GetBoson)
add_executable(${PROJECT_NAME} "main.cpp")

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

target_link_libraries ( GetBoson ${OpenCV_LIBS} ${libuvc_LIBRARIES})
