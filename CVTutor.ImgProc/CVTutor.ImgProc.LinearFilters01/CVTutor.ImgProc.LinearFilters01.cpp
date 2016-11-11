// CVTutor.ImgProc.LinearFilters01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;


int main(int argc, char** argv)
{
	const string window_name = "filter2D Demo";

	Mat src, dst;

	Mat kernel;
	Point anchor;
	double delta;
	int ddepth;
	int kernel_size;

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

	namedWindow(window_name, WINDOW_AUTOSIZE);

	anchor = Point(-1, -1);
	delta = 0;
	ddepth = -1;

	int c, ind = 0;
	while (true)
	{
		c = waitKey(500);
		if ((char)c == 27)
		{
			break;
		}

		kernel_size = 3 + 2 * (ind % 5);
		kernel = Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size*kernel_size);

		filter2D(src, dst, ddepth, kernel, anchor, delta, BORDER_DEFAULT);
		imshow(window_name, dst);
		ind++;
	}
	
	system("pause");
	return 0;
}

