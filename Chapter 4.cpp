#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
	Mat img(512, 512, CV_8UC3, Scalar(125, 255, 225));

	circle(img, Point(256, 256), 155, Scalar(195, 125, 100), FILLED);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(155, 155, 155), 3);
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

	putText(img, "Testing shid out", Point(137, 262), FONT_HERSHEY_PLAIN, 1.70, Scalar(0, 69, 255), 2);

	imshow("Figure", img);
	waitKey(0);
	return 0;
}