//
// Created by lixiaoxu on 2019-10-26.
//

#ifndef OPENCVCARBOARDDETECT_ANNPREDICT_H
#define OPENCVCARBOARDDETECT_ANNPREDICT_H

#include "common.h"

class AnnPredict {

public:
    AnnPredict(const char *ann_model, const char *ann_model_zh);

    ~AnnPredict();

    /**
     * ann测评
     *
     * @param plate
     * @return
     */
    string doPredict(Mat plate);

private:
    Ptr<ANN_MLP> ann;
    Ptr<ANN_MLP> ann_zh;
    HOGDescriptor *annHog = 0;

    void getHogFeatures(HOGDescriptor *hog, Mat src, Mat &dst);

    bool clearMaoDing(Mat shold);
};


#endif //OPENCVCARBOARDDETECT_ANNPREDICT_H
