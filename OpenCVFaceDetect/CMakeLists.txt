cmake_minimum_required(VERSION 3.13)
project(OpenCVDemo)

set(CMAKE_CXX_STANDARD 14)

#find_package(OpenCV REQUIRED)

message("Version:  ${OpenCV}")
message("module: ${CMAKE_MODULE_PATH}")

include_directories("/usr/local/Cellar/opencv/4.1.2/include/opencv4")

#add_library(libopencv_imgcodecs STATIC IMPORTED )
#set_target_properties(libopencv_imgcodecs PROPERTIES
#          IMPORTED_LOCATION "/usr/local/Cellar/opencv/4.1.2/lib/libopencv_imgcodecs.dylib")

link_libraries(usr/local/Cellar/opencv/4.1.2/lib/libopencv_imgcodecs.dylib)

add_executable(OpenCVDemo main.cpp main.h)

target_link_libraries(OpenCVDemo
#        opencv_videoio
        /usr/local/Cellar/opencv/4.1.2/lib/libopencv_imgcodecs.dylib
        /usr/local/Cellar/opencv/4.1.2/lib/libopencv_core.dylib
        /usr/local/Cellar/opencv/4.1.2/lib/libopencv_highgui.dylib
#        opencv_video
#        opencv_objdetect
        )
