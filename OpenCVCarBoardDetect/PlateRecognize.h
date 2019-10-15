//
// Created by lixiaoxu on 2019-10-15.
//



#ifndef OPENCVCARBOARDDETECT_PLATERECOGNIZE_H
#define OPENCVCARBOARDDETECT_PLATERECOGNIZE_H

#include <string>
#include "common.h"
#include "SobelLocate.h"

class PlateRecognize {
public:
    PlateRecognize();

    //没有加入虚函数，因为没有作为父类
    ~PlateRecognize();

    string recognize(Mat src);
private:
    SobelLocate *sobelLocate = 0;
};


#endif //OPENCVCARBOARDDETECT_PLATERECOGNIZE_H