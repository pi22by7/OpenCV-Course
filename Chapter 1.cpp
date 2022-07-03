#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


// image

int image() 
{
	string path = "Resources\\test.jpg";
	Mat img = imread(path);
	imshow("Image", img);
	waitKey(0);

	return 0;
}


// Video

int video() 
{
	string path = "Resources\\test.mp4";
	VideoCapture cap(path);
	Mat img;

	while (true) 
	{
		cap.read(img);
		imshow("Image", img);
		waitKey(20);
	}
	return 0;
}


//Camera

int camera() 
{
	VideoCapture cap(0);
	Mat img;

	while (true) 
	{
		cap.read(img);
		imshow("Image", img);
		waitKey(1);
	}
	return 0;
}

int main(void)
{
	image();
	//video();
	//camera();

	return 0;
}