cmake_minimum_required(VERSION 2.8)
project(SuperImpose)
find_package (OpenCV REQUIRED)
add_executable( SuperImpose superimpose.cpp )
target_link_libraries ( SuperImpose ${OpenCV_LIBS} )
