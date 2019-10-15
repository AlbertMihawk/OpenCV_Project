//
// Created by lixiaoxu on 2019-10-15.
//

#ifndef OPENCVCARBOARDDETECT_SOBELLOCATE_H
#define OPENCVCARBOARDDETECT_SOBELLOCATE_H

#include "PlateLocate.h"
#include "common.h"

class SobelLocate : public PlateLocate {
public:
    SobelLocate();

    ~SobelLocate();

    /**
     * 车牌定位：1.原图，2.输出候选车牌
     * @param src
     * @param dst_plates
     */
    void locate(Mat src, vector<Mat> &dst_plates);

};


#endif //OPENCVCARBOARDDETECT_SOBELLOCATE_H
