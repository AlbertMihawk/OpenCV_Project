#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    std::cout << "Hello, World!" << std::endl;


    VideoCapture capture;
    capture.open(0);
    if (!capture.isOpened()) {
        cout << "opencv打开摄像头失败\n" << endl;
        return -1;
    }
    Mat frame;//摄像头原始图像
    Mat gray;

    while (true) {
        capture >> frame;
        if (frame.empty()) {
            cout << "openCV读取摄像头失败！\n" << endl;
            return -1;
        }
        //读取成功
        imshow("摄像头", frame);

        //灰度化处理
        cvtColor(frame, gray, COLOR_BGR2GRAY);//opencv中为BGR顺序

        if (waitKey(30) == 27) {//Esc键退出
            break;
        }
    }

    Mat img = imread("/Users/xiaoxu/Pictures/RGB.jpeg",IMREAD_COLOR );
      if(img.empty()) {
          fprintf(stderr, "failed to load input image\n");
          return -1;
      }
    imshow("Display Image", img);
    waitKey(0);
    return 0;
}