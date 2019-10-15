

//VLPR :vehicle license plate recognize

#include <iostream>
#include "common.h"
#include <string>
#include "PlateRecognize.h"

#define PROJECT_SRC "/Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/"


int main() {
    Mat src = imread("/Users/xiaoxu/Documents/OpenCV_Project/OpenCVCarBoardDetect/car5.jpg", IMREAD_COLOR);
//    imshow("src", src);

    PlateRecognize pr;
    string str_plate = pr.recognize(src);
    cout << "车牌：" << str_plate <<endl;

    waitKey(0);

    return 0;
}