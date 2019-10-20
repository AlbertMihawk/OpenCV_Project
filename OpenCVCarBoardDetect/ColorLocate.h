//
// Created by lixiaoxu on 2019-10-20.
//

#ifndef OPENCVCARBOARDDETECT_COLORLOCATE_H
#define OPENCVCARBOARDDETECT_COLORLOCATE_H


#include "PlateLocate.h"

class ColorLocate : PlateLocate {
public:
    ColorLocate();

    ~ColorLocate();

    void locate(Mat src, vector<Mat> &dst_plates);

private:

protected:


};


#endif //OPENCVCARBOARDDETECT_COLORLOCATE_H
