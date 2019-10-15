//
// Created by lixiaoxu on 2019-10-15.
//

#ifndef OPENCVCARBOARDDETECT_PLATELOCATE_H
#define OPENCVCARBOARDDETECT_PLATELOCATE_H


#include "common.h"

class PlateLocate {
public:
    PlateLocate();

    //作为父类加入虚构函数
    virtual ~PlateLocate();

    /**
   * 车牌定位：1.原图，2.输出候选车牌
   * @param src
   * @param dst_plates
   * @return
   */
    virtual void locate(Mat src, vector<Mat> &dst_plates) = 0;

protected:
    int verifySizes(RotatedRect rotatedRect);

    void tortuosity(Mat src, vector<RotatedRect> &rect, vector<Mat> &dst_plates);

    void safeRect(Mat src, RotatedRect rotatedRect, Rect2f& rect2f);

    void rotation(Mat src, Mat &dst, Size rect_size, Point2f center, double angle);
};


#endif //OPENCVCARBOARDDETECT_PLATELOCATE_H
