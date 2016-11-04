// CVTutor.ImgProc.Thresholding01.cpp : Defines the entry point for the console application.
//

// Tutorial:
// http://docs.opencv.org/3.1.0/db/d8e/tutorial_threshold.html


#include "stdafx.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "ThresholdParam.hpp"

using namespace cv;
using namespace std;
using namespace cvtutor::imgproc;


/// Function headers
void thresholdCallback(int, void*);

// Global variables
const string window_name = "Threshold Demo";


int main(int argc, char** argv)
{
	const string trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
	const string trackbar_value = "Value";

	int threshold_value = 0;
	int threshold_type = 2;
	int const max_value = 255;
	int const max_type = 4;
	int const max_BINARY_value = 255;

	Mat src, src_gray, dst;

	string imageName("../../sample-data/lena.jpg");
	// string imageName("../../sample-data/shape_sample/7.png");
	// string imageName("../../sample-data/pic3.png");
	// string imageName("../../sample-data/pic5.png");
	if (argc > 1)
	{
		imageName = argv[1];
	}

	// Load the image
	src = imread(imageName, IMREAD_COLOR);
	if (src.empty())
	{
		cout << "Failed to load the image: " + imageName << endl;
		system("pause");
		return -1;
	}

	// Convert the image to Gray
	cvtColor(src, src_gray, COLOR_BGR2GRAY); 
	// Create a window to display results
	namedWindow(window_name, WINDOW_AUTOSIZE);

	// ????? What is all this weird cast????
	// ThresholdParam param = ThresholdParam(src_gray, dst, *((double*)&threshold_value), *((double*)&max_BINARY_value), threshold_type);
	ThresholdParam typeParam = ThresholdParam(src_gray, dst, threshold_value, const_cast<int&>(max_BINARY_value), threshold_type);
	ThresholdParam valueParam = ThresholdParam(src_gray, dst, threshold_value, const_cast<int&>(max_BINARY_value), threshold_type);

	//createTrackbar(trackbar_type,
	//	window_name, &threshold_type,
	//	max_type, thresholdCallback, &typeParam);

	createTrackbar(trackbar_value,
		window_name, &threshold_value,
		max_value, thresholdCallback, &valueParam);

	// Call the function to initialize
	thresholdCallback(0, nullptr);

	// Why not just waitKey(0)???
	for (;;)
	{
		int c;
		c = waitKey(20);
		if ((char)c == 27 || (char)c == 113)   // Escape || 'q'.
		{
			break;
		}
	}
}


/* 0: Binary
1: Binary Inverted
2: Threshold Truncated
3: Threshold to Zero
4: Threshold to Zero Inverted
*/
void thresholdCallback(int pos, void* arg)
{
	ThresholdParam* param = (ThresholdParam*)arg;
	if (param == nullptr) {
		// ????
		return;
	}
	Mat& src = param->getSrcMat();
	Mat& dst = param->getDstMat();
	double& value = param->getValue();
	double& maxValue = param->getMaxValue();
	int& type = param->getThresholdType();

	cout << "value = " + to_string(value) << endl;

	threshold(src, dst, value, maxValue, type);

	imshow(window_name, dst);
}
