// CVTutor.ImgProc.Laplace01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;


int main(int argc, char** argv)
{
	const string window_name = "Laplacian Demo";

	Mat src, src_gray, dst;
	int kernel_size = 3;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

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
	

	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);

	cvtColor(src, src_gray, COLOR_RGB2GRAY);

	namedWindow(window_name, WINDOW_AUTOSIZE);

	Mat abs_dst;

	Laplacian(src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(dst, abs_dst);

	imshow(window_name, abs_dst);

	waitKey(0);
	return 0;
}

