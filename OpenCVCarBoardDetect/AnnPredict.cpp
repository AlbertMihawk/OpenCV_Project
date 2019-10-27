//
// Created by lixiaoxu on 2019-10-26.
//

#include "AnnPredict.h"

AnnPredict::AnnPredict(const char *ann_model, const char *ann_model_zh) {
    ann = ANN_MLP::load(ann_model);
    ann_zh = ANN_MLP::load(ann_model_zh);

    annHog = new HOGDescriptor(Size(32, 32), Size(16, 16), Size(8, 8), Size(8, 8), 3);
}

AnnPredict::~AnnPredict() {
    ann->clear();
    ann.release();
    ann_zh->clear();
    ann_zh.release();
    if (annHog) {
        delete annHog;
        annHog = 0;
    }
}

string AnnPredict::doPredict(Mat plate) {

    //预处理
    Mat gray;
    cvtColor(plate, gray, COLOR_BGR2GRAY);

    //二值化
    Mat shold;
    threshold(gray, shold, 0, 255, THRESH_OTSU + THRESH_BINARY);

    showAndWrite("shold", shold);
    waitKey();

    if (!clearMaoDing(shold)) {
        return string("未识别出车牌");
    }

    return std::string();
}

void AnnPredict::getHogFeatures(HOGDescriptor *annHog, Mat src, Mat &dst) {
    //归一化处理
    Mat trainImg = Mat(annHog->winSize, CV_32S);
//    convertScaleAbs(trainImg, trainImg);
//    showAndWrite("trainImg", trainImg);
//    waitKey();
    resize(src, trainImg, annHog->winSize);

    //计算特征
    vector<float> desc;
    annHog->compute(trainImg, desc, annHog->winSize);

    Mat feature(desc);

    feature.copyTo(dst);

    feature.release();
    trainImg.release();


}

bool AnnPredict::clearMaoDing(Mat shold) {

    return 0;
}
