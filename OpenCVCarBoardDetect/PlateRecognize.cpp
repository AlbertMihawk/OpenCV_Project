//
// Created by lixiaoxu on 2019-10-15.
//

#include "PlateRecognize.h"


PlateRecognize::PlateRecognize() {
    sobelLocate = new SobelLocate();
    colorLocate = new ColorLocate();
}

PlateRecognize::~PlateRecognize() {
    if (sobelLocate) {
        delete sobelLocate;
        sobelLocate = 0;
    }
    if (colorLocate) {
        delete colorLocate;
        colorLocate = 0;
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
    imshow("origin", src);
//    vector<Mat> sobel_plates;
//    sobelLocate->locate(src, sobel_plates);

    //2.HSV颜色定位
    vector<Mat> color_plates;
    colorLocate->locate(src, color_plates);

    return string(" ");
}



