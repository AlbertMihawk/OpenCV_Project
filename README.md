# OpenCV_Project

1.brew install opencv

2.CLion Create project

3.Edit CmakeLists.txt

```
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
```


## Compile On Xcode
Run: cmake -G "Xcode" .

- OpenCVXcodeDemo : run OpenCV on Xcode
- OpenCVDemoCli : run OpenCV on Command Line
- OpenCVFaceDetect
  1.Detect Faces
  2.Tracking Faces
  

