// CVTutor.ImgProc.CannyDetector01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;


const string window_name = "Canny Detector";

Mat src, src_gray;
Mat dst, detected_edges;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;

static void CannyThreshold(int, void*);


int main(int argc, char** argv)
{
	string imageName("../../sample-data/pic5.png");
	if (argc > 1)
	{
		imageName = argv[1];
	}

	src = imread(imageName);
	if (!src.data)
	{
		cerr << "Failed to load image: " << imageName << endl;
		system("pause");
		return -1;
	}
	

	dst.create(src.size(), src.type());

	cvtColor(src, src_gray, COLOR_BGR2GRAY);

	namedWindow(window_name, WINDOW_AUTOSIZE);

	createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);

	CannyThreshold(0, nullptr);

	waitKey(0);
	return 0;
}

static void CannyThreshold(int, void*)
{
	blur(src_gray, detected_edges, Size(3, 3));

	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);

	dst = Scalar::all(0);

	src.copyTo(dst, detected_edges);
	imshow(window_name, dst);
}
