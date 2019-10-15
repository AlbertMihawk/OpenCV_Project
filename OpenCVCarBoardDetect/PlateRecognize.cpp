//
// Created by lixiaoxu on 2019-10-15.
//

#include "PlateRecognize.h"


PlateRecognize::PlateRecognize() {
    sobelLocate = new SobelLocate();
}

PlateRecognize::~PlateRecognize() {
    if (sobelLocate) {
        delete sobelLocate;
        sobelLocate = 0;
    }
}

/**
 * 车牌识别：车牌定位+检测+字符识别
 * @param src
 * @return
 */
string PlateRecognize::recognize(Mat src) {
    //1.车牌定位
    //sobel定位
    vector<Mat> dst_plates;
    sobelLocate->locate(src, dst_plates);

    return string("12345");
}


