cmake_minimum_required(VERSION 3.13)
project(OpenCVCarBoardDetect)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories("/usr/local/Cellar/opencv/4.1.0_2/include/opencv4")
link_libraries("/usr/local/Cellar/opencv/4.1.0_2/lib")


add_executable(OpenCVCarBoardDetect main.cpp PlateRecognize.cpp PlateRecognize.h common.h PlateLocate.cpp PlateLocate.h SobelLocate.cpp SobelLocate.h)

target_link_libraries(OpenCVCarBoardDetect
        opencv_videoio
        opencv_core
        opencv_highgui
        opencv_video
        opencv_objdetect)
