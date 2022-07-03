#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main(void)
{
	std::string path = "Resources\\test.jpg";
	
	cv::Mat img = cv::imread(path), imGray, imGauss, imCanny, imgDil, imgEro;
	cv::cvtColor(img, imGray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(img, imGauss, cv::Size(7, 7), 5, 0);
	cv::Canny(imGauss, imCanny, 25, 75);

	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::dilate(imCanny, imgDil, kernel);
	cv::erode(imgDil, imgEro, kernel);

	cv::imshow("Original", img);
	cv::imshow("Gray", imGray);
	cv::imshow("Blurred", imGauss);
	cv::imshow("Canny", imCanny);
	cv::imshow("Dilated", imgDil);
	cv::imshow("Eroded", imgEro);
	cv::waitKey(0);
	return 0;
}