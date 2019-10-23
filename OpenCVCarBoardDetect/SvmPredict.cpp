//
// Created by lixiaoxu on 2019-10-23.
//

#include "SvmPredict.h"

SvmPredict::SvmPredict(const char *svm_model) {
    svm = SVM::load(svm_model);
    svmHog = new HOGDescriptor(Size(128, 64), Size(16, 16), Size(8, 8), Size(8, 8), 3);

}

SvmPredict::~SvmPredict() {
    svm->clear();
    svm.release();
    if (svmHog) {
        delete svmHog;
        svmHog = 0;
    }
}

int SvmPredict::doPredict(vector<Mat> candi_plates, Mat &plate) {

    Mat p;
    for (int i = 0; i < candi_plates.size(); ++i) {
        p = candi_plates[i];
        //获取车牌图片的特征：HOG
        //预处理
        Mat gray;
        cvtColor(p, gray, COLOR_BGR2GRAY);
        //二值化
        Mat shold;
        threshold(gray, shold, 0, 255, THRESH_BINARY + THRESH_OTSU);

        Mat features;
        getHogFeatures(svmHog, shold, features);

        Mat sample = features.reshape(1, 1);
//        svm->predict(sample,)
    }

    return 0;
}

void SvmPredict::getHogFeatures(HOGDescriptor *svmHog, Mat src, Mat &dst) {
    //归一化处理
    Mat trainImg = Mat(svmHog->winSize, CV_32S);
//    convertScaleAbs(trainImg, trainImg);
//    imshow("trainImg", trainImg);
//    waitKey();
    resize(src, trainImg, svmHog->winSize);

    //计算特征
    vector<float> desc;
    svmHog->compute(trainImg, desc, svmHog->winSize);

    Mat feature(desc);

    feature.copyTo(dst);

    feature.release();
    trainImg.release();
}