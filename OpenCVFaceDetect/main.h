//
// Created by lixiaoxu on 2019-10-07.
//


#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/video/tracking.hpp>


using namespace std;
using namespace cv;
//#define DETECT

class OpenCV_Face {

};

//级联分类器
//CascadeClassifier face_CascadeClassifier;
//
//cv::Ptr<DetectionBasedTracker> tracker;
//
//class CascadeDetectorAdapter : public DetectionBasedTracker::IDetector {
//public:
//    CascadeDetectorAdapter(cv::Ptr<cv::CascadeClassifier> detector) :
//            IDetector(),
//            Detector(detector) {
//        CV_Assert(detector);
//    }
//
//    void detect(const cv::Mat &Image, std::vector<Rect> &objects) {
//        Detector->detectMultiScale(Image, objects, scaleFactor, minNeighbours, 0, minObjSize,
//                                   maxObjSize);
//    }
//
//    virtual ~CascadeDetectorAdapter() {
//    }
//
//private:
//    CascadeDetectorAdapter();
//
//    cv::Ptr<cv::CascadeClassifier> Detector;
//};