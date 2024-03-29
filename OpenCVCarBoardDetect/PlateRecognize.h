//
// Created by lixiaoxu on 2019-10-15.
//



#ifndef OPENCVCARBOARDDETECT_PLATERECOGNIZE_H
#define OPENCVCARBOARDDETECT_PLATERECOGNIZE_H

#include <string>
#include "common.h"
#include "SobelLocate.h"
#include "ColorLocate.h"
#include "SvmPredict.h"
#include "AnnPredict.h"

class PlateRecognize {
public:
    PlateRecognize(const char *svm_model, const char *ann_model, const char *ann_model_zh);

    //没有加入虚函数，因为没有作为父类
    ~PlateRecognize();

    string recognize(Mat src);

private:
    SobelLocate *sobelLocate = 0;
    ColorLocate *colorLocate = 0;
    SvmPredict *svmPredict = 0;
    AnnPredict *annPredict = 0;
};


#endif //OPENCVCARBOARDDETECT_PLATERECOGNIZE_H
