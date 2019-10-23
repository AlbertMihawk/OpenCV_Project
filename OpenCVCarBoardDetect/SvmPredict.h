//
// Created by lixiaoxu on 2019-10-23.
//

#ifndef OPENCVCARBOARDDETECT_SVMPREDICT_H
#define OPENCVCARBOARDDETECT_SVMPREDICT_H

#include "common.h"


class SvmPredict {
public:
    SvmPredict();

    ~SvmPredict();

    /**
     * svm评测
     *
     * @param candi_plates
     * @param plate
     * @return
     */
    int doPredict(vector<Mat> candi_plates, Mat &plate);

};


#endif //OPENCVCARBOARDDETECT_SVMPREDICT_H
