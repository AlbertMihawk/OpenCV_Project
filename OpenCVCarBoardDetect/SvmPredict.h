//
// Created by lixiaoxu on 2019-10-23.
//

#ifndef OPENCVCARBOARDDETECT_SVMPREDICT_H
#define OPENCVCARBOARDDETECT_SVMPREDICT_H

#include "common.h"
//机器学习 machine learning


class SvmPredict {
public:
    SvmPredict(const char *svm_model);

    ~SvmPredict();

    /**
     * svm评测
     *
     * @param candi_plates
     * @param plate
     * @return
     */
    int doPredict(vector<Mat> candi_plates, Mat &plate);
private:
    Ptr<SVM> svm;

    HOGDescriptor *svmHog = 0;

    void getHogFeatures(HOGDescriptor *svmHog, Mat src, Mat &dst);
};


#endif //OPENCVCARBOARDDETECT_SVMPREDICT_H
