#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void getContours(Mat imgDil, Mat img)
{
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		//cout << area << endl;

		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());
		string objectType;

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02*peri, true);
			
			//cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);

			int objCor = (int)conPoly[i].size();
			
			if (objCor == 3) { objectType = "Triangle"; }
			else if (objCor == 4) 
			{ 
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				//cout << "aspRatio is: " << aspRatio << "\tRound is: " << round(aspRatio) << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05)
					objectType = "Square";
				else
					objectType = "Rectangle";
			}
			else { objectType = "Circle"; }
			
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, { boundRect[i].x, boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 1);
		}
	}
}

int main(void)
{
	string path = "Resources\\shapes.png";
	Mat img = imread(path), imgGray, imGauss, imCanny, imgDil;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imGauss, Size(3,3), 3, 0);
	Canny(imGauss, imCanny, 25, 75);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imCanny, imgDil, kernel);

	getContours(imgDil, img);

	imshow("Image", img);
	imshow("Dilated", imgDil);
	
	waitKey(0);
	return 0;
}