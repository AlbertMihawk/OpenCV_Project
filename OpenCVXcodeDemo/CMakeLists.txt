cmake_minimum_required(VERSION 3.13)
project(OpenCVDemo)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

message("Version:  ${OpenCV_VERSIOIN}")

include_directories("/usr/local/Cellar/opencv/4.1.0_2/include/opencv4")
link_libraries("/usr/local/Cellar/opencv/4.1.0_2/lib")

add_executable(OpenCVDemo main.cpp)

target_link_libraries(OpenCVDemo
        opencv_videoio
        opencv_core
        opencv_highgui
        opencv_video)
