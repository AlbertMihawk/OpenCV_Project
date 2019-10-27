

//VLPR :vehicle license plate recognize

#include <iostream>
#include "common.h"
#include <string>
#include "PlateRecognize.h"

#define PROJECT_SRC "/Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/"


int main() {
    Mat src = imread("/Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/pic/car5.jpg", IMREAD_COLOR);
    showAndWrite("src", src);

    PlateRecognize pr("/Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/train/svm.xml",
            "/Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/ann/ann.xml",
            "/Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/ann/ann_zh.xml");
    string str_plate = pr.recognize(src);
    cout << "车牌：" << str_plate << endl;

    return 0;
}