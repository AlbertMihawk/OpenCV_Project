//
// Created by lixiaoxu on 2019-10-20.
//

#include "ColorLocate.h"

ColorLocate::ColorLocate() {

}

ColorLocate::~ColorLocate() {

}

void ColorLocate::locate(Mat src, vector<Mat> &dst_plates) {
    //图像预处理
    //1.目前是BGR颜色空间，转换成HSV
    Mat hsv;
    cvtColor(src, hsv, COLOR_BGR2HSV);
    imshow("hsv", hsv);
    //2.找蓝色像素:h(100-124),s(43-255),v(46-255)
    int channels = hsv.channels();
    int width = hsv.rows;
    int height = hsv.cols * channels;

    //TODO 是否有必要
    //2.判断是否为连续存储
    if (hsv.isContinuous()) {
        width *= height;
        height = 1;
    }
    uchar *p;
    for (int i = 0; i < height; i++) {
        p = hsv.ptr<uchar>(i);
        for (int j = 0; j < width; j += channels) {
            //获取hsv分量
            int h = p[j];
            int s = p[j + 1];
            int v = p[j + 2];

            bool isBlue = false;
            if (h >= 100 && h <= 124 &&
                s >= 43 && s <= 255 &&
                v >= 46 && v <= 255) {
                isBlue = true;
            }
            if (isBlue) {
                //突显蓝色（v分量最大）
                p[j] = 0;
                p[j + 1] = 0;
                p[j + 2] = 255;
            } else {
                //变黑
                p[j] = 0;
                p[j + 1] = 0;
                p[j + 2] = 0;
            }
        }
    }
    //蓝色车漆不适合
//    imshow("蓝色", hsv);

    //3.提取V分量颜色
    vector<Mat> hsv_split;
    //对图像进行通道分离
    split(hsv, hsv_split);
//    imshow("splitV", hsv_split[2]);

    //5.形态学操作：闭操作
    Mat close;
//    Mat element = getStructuringElement(MORPH_RECT, Size(80, 30));//car4
    Mat element = getStructuringElement(MORPH_RECT, Size(19, 3));
    morphologyEx(hsv_split[2], close, MORPH_CLOSE, element);
    imshow("hsv_close", close);

    //6.找轮廓
    vector<vector<Point>> contours;
    findContours(close, contours,
                 RETR_EXTERNAL,//外轮廓
                 CHAIN_APPROX_NONE //轮廓上所有的像素点
    );
    RotatedRect rotatedRect;
    vector<RotatedRect> vec_sobel_rects;

    //7.遍历判断矩形
    for (vector<Point> points :contours) {
        rotatedRect = minAreaRect(points);//带角度的矩形
        rectangle(src, rotatedRect.boundingRect(), Scalar(0, 0, 255));
        if (verifySizes(rotatedRect)) {
            vec_sobel_rects.push_back(rotatedRect);
        }
    }

    for (RotatedRect rect :vec_sobel_rects) {
        rectangle(src, rect.boundingRect(), Scalar(0, 255, 0));
    }
    imshow("color_bound", src);
    //8.矩形矫正
    //角度判断，旋转，调整大小

    tortuosity(src, vec_sobel_rects, dst_plates);
    for (Mat m :dst_plates) {
        imshow("color_plate", m);
        waitKey();
    }

    for (Mat m:hsv_split) {
        m.release();
    }
    close.release();
    element.release();
    hsv.release();
}
