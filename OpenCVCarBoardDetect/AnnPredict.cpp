//
// Created by lixiaoxu on 2019-10-26.
//

#include "AnnPredict.h"


string AnnPredict::ZHCHARS[] = {"川", "鄂", "赣", "甘", "贵", "桂", "黑", "沪", "冀", "津", "京", "吉", "辽", "鲁", "蒙", "闽", "宁",
                                "青", "琼", "陕", "苏", "晋", "皖", "湘", "新", "豫", "渝", "粤", "云", "藏", "浙"};
char AnnPredict::CHARS[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                            'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

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
//    waitKey();

//    Mat close;
////    Mat element = getStructuringElement(MORPH_RECT, Size(80, 30));//car4
//    Mat element = getStructuringElement(MORPH_RECT, Size(2, 2));
//    morphologyEx(shold, close, MORPH_ERODE, element);
//    imshow("close", close);


    if (!clearMaoDing(shold)) {
        return string("未识别出车牌");
    }
    imshow("clear", shold);

    //字符分割
    //找轮廓
    vector<vector<Point>> contours;
    findContours(shold,//输入
                 contours,//输出轮廓
                 RETR_EXTERNAL,//外轮廓
                 CHAIN_APPROX_NONE //轮廓上所有的像素点
    );
    vector<Rect> vec_ann_rects;
    //遍历并判断矩形尺寸
    Mat shold_clone = plate.clone();
    for (vector<Point> points :contours) {
        Rect rect = boundingRect(points);
        rectangle(shold_clone, rect, Scalar(0, 0, 255));
        Mat roi = shold(rect);
        if (verifyCharSize(roi)) {
            vec_ann_rects.push_back(rect);
        }
    }
    imshow("rect", shold_clone);

    for (Rect rect:vec_ann_rects) {
        imshow("ann_char", shold_clone(rect));
//        waitKey();
    }

    //对字符矩形轮廓排序，从左到右
    sort(vec_ann_rects.begin(), vec_ann_rects.end(),
         [](const Rect &rect1, const Rect &rect2) {
             return rect1.x < rect2.x;
         });
    //获取城市字符轮廓的索引
    int cityIndex = getCityIndex(vec_ann_rects);

    //推导汉字字符的轮廓
    Rect chineseRect;
    getChineseRect(vec_ann_rects[cityIndex], chineseRect);

    vector<Mat> plateCharMats;
    plateCharMats.push_back(shold_clone(chineseRect));
    //取汉字后面的字符
    int count = 6;
    if (vec_ann_rects.size() < 6) {
        return string("未识别到车牌");
    }
    for (int i = cityIndex; i < vec_ann_rects.size() && count; i++, count--) {
        plateCharMats.push_back(shold(vec_ann_rects[i]));
    }
    //字符识别
    string str_plate;
    predict(plateCharMats, str_plate);
    for (Mat m: plateCharMats) {
        m.release();
    }
    waitKey();
    return str_plate;
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

//字符行：最小跳变次数12，最大跳变次数60
//计算每一行像素的跳变，如果小于指定最大阈值，认为改行是铆钉行
bool AnnPredict::clearMaoDing(Mat plate) {
    const int minChangeCount = 12;
    const int maxChangeCount = 45;
    int changeCount = 0;
    vector<int> changes;
    for (int i = 0; i <= plate.rows; i++) {
        if (changeCount < minChangeCount || changeCount >= maxChangeCount) {
            for (int j = 0; j < plate.cols; j++) {
                plate.at<char>(i - 1, j) = static_cast<char>(0);
            }
        }
        changeCount = 0;
        if (plate.cols < 1 || plate.rows == i) break;
        for (int j = 1; j < plate.cols; j++) {
            if (plate.at<char>(i, j) != plate.at<char>(i, j - 1)) {
                changeCount++;
            }
        }
        changes.push_back(changeCount);
    }

    //车牌字符跳变条件
    //满足字符像素跳变条件的行数 == 字符的高度
    int charRows = 0;
    for (int i = 0; i < plate.rows; i++) {
        if (changes[i] >= minChangeCount && changes[i] <= maxChangeCount) {
            charRows++;
        }
    }
    //判断字符高度占整个车牌的百分比
    float heightPercent = charRows * 1.0 / plate.rows;
    if (heightPercent <= 0.4) {
        printf("字符高度百分比为%f\n", heightPercent);
        return false;
    }

    //判断字符区域的面积占车牌面积的百分比
    int plate_area = plate.rows * plate.cols;//所有像素点

    //字符区域=白点像素的个数
    //1.循环遍历白色点个数
    //2.countNonZero
    int white_area = countNonZero(plate);
    float areaPercent = white_area * 1.0 / plate_area;
    if (areaPercent <= 0.10 || areaPercent >= 0.5) {
        printf("面积百分比为%f\n", areaPercent);
        return false;
    }

    return true;
}

bool AnnPredict::verifyCharSize(Mat plate) {

    //容错率
    float error = 0.7f;
    //理想宽高比
    float aspect = 0.5f;
    //真实宽高比
    float realAspect = float(plate.cols) / float(plate.rows);
    float minHeight = 10.0f;
    float maxHeight = 35.0f;
    //真实面积
    float area = plate.cols * plate.rows;

    //比例浮动 error认为也满足
    //最小宽高比
    float aspectMin = 0.05f;
    //最大宽高比
    float aspectMax = aspect + aspect * error;

    int zeroArea = countNonZero(plate);
    float areaPercent = zeroArea * 1.0 / area;

    if (areaPercent <= 0.8 && realAspect >= aspectMin &&
        realAspect <= aspectMax && plate.rows >= minHeight &&
        plate.rows <= maxHeight) {
        return true;
    }
    return false;
}

//找城市轮廓索引
int AnnPredict::getCityIndex(vector<Rect> rects) {
    int cityIndex = 0;
    for (int i = 0; i < rects.size(); i++) {
        Rect rect = rects[i];
        int midX = rect.x + rect.width / 2;
        if (midX < 136 / 7 * 2 && midX > 136 / 7) {
            cityIndex = i;
            break;
        }
    }
    return cityIndex;
}

void AnnPredict::getChineseRect(Rect city, Rect &chineseRect) {
    //把宽度邵伟扩大一点
    float width = city.width * 1.15f;
    //城市轮廓的x坐标
    int x = city.x;

    //x:当前汉子后面城市轮廓的x坐标
    //减去城市的宽
    int newX = x - width;
    chineseRect.x = newX >= 0 ? newX : 0;
    chineseRect.y = city.y;
    chineseRect.width = width;
    chineseRect.height = city.height;
}

void AnnPredict::predict(vector<Mat> vec, string &result) {
    for (int i = 0; i < vec.size(); i++) {
        Mat plate_char = vec[i];
        //提取HOG特征
        Mat features;
        getHogFeatures(annHog, plate_char, features);

        Mat sample = features.reshape(1, 1);
        Mat response;
        Point maxLoc;
        Point minLoc;
        if (i) {
            //字母和数字
            ann->predict(sample, response);
            minMaxLoc(response, 0, 0, &minLoc, &maxLoc);
            int index = maxLoc.x;
            result += CHARS[index];
        } else {
            ann_zh->predict(sample, response);
            minMaxLoc(response, 0, 0, &minLoc, &maxLoc);
            int index = maxLoc.x;
            result += ZHCHARS[index];
        }
    }
}
