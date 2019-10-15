#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc,char* argv[])
{
	 Mat img = imread("/Users/xiaoxu/Pictures/RGB.jpeg",IMREAD_COLOR );
      if(img.empty()) {
          fprintf(stderr, "failed to load input image\n");
          return -1;
      }
    imshow("Display Image", img);
    waitKey(0);
	return 0;
}


