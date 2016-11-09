// CVTutor.ImgProc.GrabCut01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;


int main(int argc, char** argv)
{
	// default image
	string imageName("../../sample-data/pic5.png");
	if (argc > 1)
	{
		imageName = argv[1];
	}

	namedWindow("Original Image", WINDOW_AUTOSIZE);
	namedWindow("After GrabCut", WINDOW_AUTOSIZE);

	Mat img = imread(imageName, IMREAD_COLOR);
	imshow("Original Image", img);


	// tbd:
	// how to use grabCut() ?????


	// ????
	InputOutputArray mask = Mat();

	int r = img.rows;
	int c = img.cols;
	auto p1 = Point((int)(c / 10), (int)(r / 10));
	// auto p1 = Point((int)(c / 2), (int)(r / 2));
	auto p2 = Point((int)(c - c / 10), (int)(r - r / 10));
	Rect rect(p1, p2);

	// ????
	InputOutputArray bgdModel = Mat();
	InputOutputArray fgdModel = Mat();

	int iterCount = 10;
	GrabCutModes mode = GrabCutModes::GC_INIT_WITH_RECT;
	grabCut(img, mask, rect, bgdModel, fgdModel, iterCount, mode);

	// imshow("After GrabCut", img);
	imshow("After GrabCut", mask);



	
	waitKey(0);
	destroyAllWindows();
	return 0;
}

