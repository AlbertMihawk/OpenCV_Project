//
// Created by lixiaoxu on 2019-10-15.
//

#include "PlateRecognize.h"


PlateRecognize::PlateRecognize(const char* svm_model) {
    sobelLocate = new SobelLocate();
    colorLocate = new ColorLocate();
    svmPredict = new SvmPredict(svm_model);
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
    if (svmPredict) {
        delete svmPredict;
        svmPredict = 0;
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
    vector<Mat> sobel_plates;
    sobelLocate->locate(src, sobel_plates);

    //2.HSV颜色定位
    vector<Mat> color_plates;
    colorLocate->locate(src, color_plates);

    //候选车牌2合1
    vector<Mat> plates;
    plates.insert(plates.begin(), sobel_plates.begin(), sobel_plates.end());
    plates.insert(plates.end(), color_plates.begin(), color_plates.end());

    for (Mat m:sobel_plates) {
        m.release();
    }
    for (Mat m:color_plates) {
        m.release();
    }
    char windowName[100];
    for (size_t i = 0; i < plates.size(); i++) {
        sprintf(windowName,"%zd 候选车牌", i);
        imshow(windowName, plates[i]);
        waitKey();
    }

    //候选车牌里面有两类车牌和非车牌
    //对候选车牌进行精选，SVM：用来分类
    Mat plate;
    //找到最有可能是车牌的图
    int index = svmPredict->doPredict(plates, plate);

    return string(" ");
}



