cmake_minimum_required(VERSION 3.13)
project(OpenCVCarBoardDetect)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories("/usr/local/Cellar/opencv/4.1.2/include/opencv4")
#link_libraries("/usr/local/Cellar/opencv/4.1.2/lib")

file(GLOB src_files *.cpp)

add_executable(OpenCVCarBoardDetect ${src_files})

target_link_libraries(OpenCVCarBoardDetect
        opencv_videoio
        opencv_core
        opencv_highgui
        opencv_video
        opencv_objdetect)
