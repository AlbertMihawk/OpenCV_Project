//
// Created by lixiaoxu on 2019-10-15.
//

#include "SobelLocate.h"

SobelLocate::SobelLocate() {

}

SobelLocate::~SobelLocate() {

}

/**
 * 车牌定位，1.原图，2.输出候选车牌
 * @param src
 * @param dst_plates
 */
void SobelLocate::locate(Mat src, vector<Mat> &dst_plates) {
    //图像预处理
    //1.高斯模糊
    Mat blur;
    //Ksize:both must be positive and odd,正数的奇数
    //半径越大越模糊
    GaussianBlur(src, blur, Size(5, 5), 0);
//    imshow("Gauss", blur);
    //2.灰度化
    Mat gray;
    cvtColor(blur, gray, COLOR_BGR2GRAY);
//    imshow("gray", gray);

    //3.sobel运算
    Mat sobel_16;
    //输入
    //Sobel函数求导后，导数可能得值会大于255，或小于0
    Sobel(gray, sobel_16, CV_16S, 1, 0);
//    imshow("sobel_16",sobel_16);//无法显示
    //转回8位
    Mat sobel;

    convertScaleAbs(sobel_16, sobel);
//    imshow("sobel", sobel);//无法显示,需要进行转换

    //4.二值化（非黑即白）
    Mat shold;
    //THRESH_OTSU 大律法 自适应阈值
    //THRESH_BINARY 正二值化（还有反）
    threshold(sobel, shold, 0, 255, THRESH_OTSU + THRESH_BINARY);
//    imshow("shold", shold);

    //5.形态学操作：闭操作
    Mat close;
//    Mat element = getStructuringElement(MORPH_RECT, Size(80, 30));//car4
    Mat element = getStructuringElement(MORPH_RECT, Size(19, 3));
    morphologyEx(shold, close, MORPH_CLOSE, element);
//    imshow("sobel_close", close);

    //6.找轮廓
    vector<vector<Point>> contours;
    findContours(close, contours,
                 RETR_EXTERNAL,//外轮廓
                 CHAIN_APPROX_NONE //轮廓上所有的像素点
    );
    RotatedRect rotatedRect;
    vector<RotatedRect> vec_sobel_rects;

    //7.遍历判断矩形
    Mat src_clone = src.clone();
/** 另一种方式的矩形遍历i
    vector<vector<Point>>::iterator it = contours.begin();
    while (it != contours.end()) {
        rotatedRect = minAreaRect(*it);//带角度的矩形
        rectangle(src_clone, rotatedRect.boundingRect(), Scalar(0, 0, 255));
        if (verifySizes(rotatedRect)) {
            vec_sobel_rects.push_back(rotatedRect);
            ++it;
        }else{
            it = contours.erase(it);
        }
    }
    return;*/

    for (vector<Point> points :contours) {
        rotatedRect = minAreaRect(points);//带角度的矩形
        rectangle(src_clone, rotatedRect.boundingRect(), Scalar(0, 0, 255));
        if (verifySizes(rotatedRect)) {
            vec_sobel_rects.push_back(rotatedRect);
        }
    }

    for (RotatedRect rect :vec_sobel_rects) {
        rectangle(src_clone, rect.boundingRect(), Scalar(0, 255, 0));
    }
//    imshow("sobel_bound", src_clone);
    //8.矩形矫正
    //角度判断，旋转，调整大小

    tortuosity(src, vec_sobel_rects, dst_plates);
    for (Mat m :dst_plates) {
//        imshow("plate", m);
//        waitKey();
    }


    blur.release();
    gray.release();
    sobel_16.release();
    sobel.release();
    shold.release();
    close.release();
}
