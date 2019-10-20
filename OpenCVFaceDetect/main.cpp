#include <iostream>
#include <opencv2/opencv.hpp>
#include "main.h"

using namespace std;
using namespace cv;

int main() {
//
//
//#ifdef DETECT
//    //opencv-4.1.1/build/etc/haarcascade_frontalface_alt.xml
//    //隐式转换
//    if (!face_CascadeClassifier.load("/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml")) {
//        cout << "级联分类器加载失败！\n" << endl;
//        return -1;
//    }
//#else
//    //人脸跟踪
//    Ptr<CascadeDetectorAdapter> mainDetector = makePtr<CascadeDetectorAdapter>(
//            makePtr<CascadeClassifier>("/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml"));
//    Ptr<CascadeDetectorAdapter> trackingDetector = makePtr<CascadeDetectorAdapter>(
//            makePtr<CascadeClassifier>("/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml"));
//    DetectionBasedTracker::Parameters DetectorParams;
//    tracker = makePtr<DetectionBasedTracker>(mainDetector, trackingDetector, DetectorParams);
//    tracker->run();
//
//
//#endif //DETECT
//    VideoCapture capture;
//    //如果摄像头开启不成功，尝试改为-1运行，有可能出现申请摄像头权限的提示，然后再改回open(0)
//    capture.open(0);
//    if (!capture.isOpened()) {
//        cout << "opencv打开摄像头失败\n" << endl;
//        return -1;
//    }
//    Mat frame;//摄像头原始图像
//    Mat gray;
//
//    while (true) {
//        capture >> frame;
//        if (frame.empty()) {
//            cout << "openCV读取摄像头失败！\n" << endl;
//            return -1;
//        }
//        //读取成功
////        imshow("摄像头", frame);
//
//        //灰度化处理
//        cvtColor(frame, gray, COLOR_BGR2GRAY);//opencv中为BGR顺序
////        imshow("灰度化", gray);
//
//        //直方图均衡化，达到目的，增强对比度
//        equalizeHist(gray, gray);
//        //gray是均衡化后的了
//
//        std::vector<Rect> faces;
//#ifdef DETECT
//        //人脸识别
//        face_CascadeClassifier.detectMultiScale(gray, faces);
//#else
//        //人脸跟踪
//        tracker->process(gray);
//        tracker->getObjects(faces);
//
//#endif
//        for (Rect face : faces) {
//            //1.在哪个上面画
//            //2.人脸框矩形
//            //3.画的矩形框
//            rectangle(frame, face, Scalar(0, 0, 255));//蓝，绿，红
//            //检测实时图像非常卡顿，适合静态图像
//        }
//
//        imshow("摄像头", frame);
//        if (waitKey(30) == 27) {//Esc键退出
//            break;
//        }
//    }
//#ifndef DETECT
//    tracker->stop();
//#endif

    Mat img = imread("/Users/xiaoxu/Pictures/RGB.jpeg", IMREAD_COLOR);
    if (img.empty()) {
        fprintf(stderr, "failed to load input image\n");
        return -1;
    }
    imshow("Display Image", img);
    waitKey(0);
    return 0;
}