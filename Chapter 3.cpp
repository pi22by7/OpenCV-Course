#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void) 
{

	string path = "Resources/test.jpg";
	Mat img = imread(path);
	Mat imgResize, imgCrop;

	cout << img.size() << endl;
	resize(img, imgResize, Size(), 0.5, 0.5);
	cout << imgResize.size() << endl;


	Rect roi(200, 100, 300, 300);
	imgCrop = img(roi);
	cout << imgCrop.size() << endl;

	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);
	waitKey(0);

	return 0;
}