//
// Created by lixiaoxu on 2019-10-27.
//
#include "common.h"

void showAndWrite(const string winName, Mat mat) {
    cv::imshow(winName, mat);
    string path = "/Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/sample/";
    string absPath = path + winName + ".jpg";
    cv::imwrite(absPath, mat);
}
