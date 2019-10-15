//
// Created by lixiaoxu on 2019-10-15.
//

#include "PlateLocate.h"

PlateLocate::PlateLocate() {

}

PlateLocate::~PlateLocate() {

}

/**
 * 尺寸校验（宽高比&面积）
 * @param rotatedRect
 * @return
 */
int PlateLocate::verifySizes(RotatedRect rotatedRect) {
    //容错率
    float error = 0.75f;
    //理想宽高比
    float aspect = float(136) / float(36);
    //真实宽高比
    float realAspect = float(rotatedRect.size.width) / float(rotatedRect.size.height);
    if (realAspect < 1)
        realAspect = float(rotatedRect.size.height) / float(rotatedRect.size.width);
    //真实面积
    float area = rotatedRect.size.height * rotatedRect.size.width;
    //最小最大面积 不符合的丢弃
    //给个大概就行，随时调整
    //初步筛选
    int areaMin = 44 * aspect * 14;
    int areaMax = 440 * aspect * 140;

    //比例浮动 error认为也满足
    //最小宽高比
    float aspectMin = aspect - aspect * error;
    //最大宽高比
    float aspectMax = aspect + aspect * error;

    if ((area < areaMin || area > areaMax) || (realAspect < aspectMin || realAspect > aspectMax)) {
        return 0;
    }
    return 1;
}

/**
 * 矩形矫正
 * @param src
 * @param rects
 * @param dst_plates
 */
void PlateLocate::tortuosity(Mat src, vector<RotatedRect> &rects, vector<Mat> &dst_plates) {
    //循环要处理的矩形
    for (RotatedRect roi_rect:rects) {
        //矩形角度
        float roi_angle = roi_rect.angle;
        float r = (float) roi_rect.size.width / (float) roi_rect.size.height;
        if (r < 1) {
            roi_angle = 90 + roi_angle;
        }

        //矩形大小
        Size roi_rect_size = roi_rect.size;

        //让rect在一个安全范围内
        Rect2f safe_rect;
        safeRect(src, roi_rect, safe_rect);

        //候选车牌
        //抠图 这里不是产生一张新图片 而是在src上定位到一个Mat，来处理
        //数据和src是同一份
        Mat src_rect = src(safe_rect);
        //真正的候选车牌
        Mat dst;
        //不需要旋转的 旋转角度小没必要旋转了
        if (roi_angle - 5 < 0 && roi_angle + 5 > 0) {
            dst = src_rect.clone();
        } else {
            //相对于roi的中心点，不见去左上角坐标是相对于整个图的
            //减去左上角则是相对于候选车牌的中心点 坐标
            Point2f roi_ref_center = roi_rect.center - safe_rect.tl();
            Mat rotated_mat;
            //矫正 rotated_mat 矫正后的图片
            rotation(src_rect, rotated_mat, roi_rect_size, roi_ref_center, roi_angle);
            dst = rotated_mat;
        }

        //调整大小
        Mat plate_mat;
        //高和宽
        plate_mat.create(36, 136, CV_8UC3);
        resize(dst, plate_mat, plate_mat.size());

        dst_plates.push_back(plate_mat);
        dst.release();
    }
}

/**
 * 转换安全矩形
 * @param src
 * @param rect
 * @param safa_rect
 */
void PlateLocate::safeRect(Mat src, RotatedRect rect, Rect2f &safe_rect) {
    //RotatedRect 没有坐标
    //转为正常的带坐标的边框
    Rect2f boundRect = rect.boundingRect2f();

    //左上角x,y
    float tl_x = boundRect.x > 0 ? boundRect.x : 0;
    float tl_y = boundRect.y > 0 ? boundRect.y : 0;

    //这里是拿坐标x,y从0开始的所以 - 1
    //比如宽长度是10，x坐标最大是9，所以src.cols - 1
    //右下角
    float br_x = boundRect.x + boundRect.width < src.cols ? boundRect.x + boundRect.width - 1 : src.cols - 1;
    float br_y = boundRect.y + boundRect.height < src.rows ? boundRect.y + boundRect.height - 1 : src.rows - 1;

    float w = br_x - tl_x;
    float h = br_y - tl_y;
    if (w <= 0 || h <= 0) return;
    safe_rect = Rect2f(tl_x, tl_y, w, h);
}


/**
 * 旋转
 * @param src
 * @param dst
 * @param rect_size
 * @param center
 * @param angle
 */
void PlateLocate::rotation(Mat src, Mat &dst, Size rect_size, Point2f center, double angle) {
    //获得旋转矩阵
    Mat rot_mat = getRotationMatrix2D(center, angle, 1);

    //运用放射变换
    Mat mat_rotated;
    //矫正后 大小会不一样，但是对角线肯定能容纳
    int max = sqrt(pow(src.rows, 2) + pow(src.cols, 2));
    warpAffine(src, mat_rotated, rot_mat, Size(max, max), INTER_CUBIC);
//    imshow("before rotate",src);
//    imshow("after rotate",mat_rotated);
    //截取 尽量吧车牌多余的区域截取掉
    getRectSubPix(mat_rotated, Size(rect_size.width, rect_size.height), center, dst);
//    imshow("cut" ,dst);
//    waitKey();

    mat_rotated.release();
    rot_mat.release();
}



