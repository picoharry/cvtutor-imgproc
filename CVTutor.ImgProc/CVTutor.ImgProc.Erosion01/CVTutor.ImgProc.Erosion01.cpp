// CVTutor.ImgProc.Erosion01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "Erosion.h"
#include "Dilation.h"

using namespace std;
using namespace cv;
using namespace cvtutor::imgproc;

/// Global variables
Mat src, erosion_dst, dilation_dst;

int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;


int main(int argc, char** argv)
{
	/// Load an image
	src = imread(argv[1], IMREAD_COLOR);

	if (src.empty())
	{
		return -1;
	}

	/// Create windows
	namedWindow("Erosion Demo", WINDOW_AUTOSIZE);
	namedWindow("Dilation Demo", WINDOW_AUTOSIZE);
	moveWindow("Dilation Demo", src.cols, 0);

	/// Create Erosion Trackbar
	createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Demo",
		&erosion_elem, max_elem,
		try_erosion);

	createTrackbar("Kernel size:\n 2n +1", "Erosion Demo",
		&erosion_size, max_kernel_size,
		try_erosion);

	/// Create Dilation Trackbar
	createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation Demo",
		&dilation_elem, max_elem,
		try_dilation);

	createTrackbar("Kernel size:\n 2n +1", "Dilation Demo",
		&dilation_size, max_kernel_size,
		try_dilation);

	/// Default start
	try_erosion(0, 0);
	try_dilation(0, 0);

	waitKey(0);
	return 0;
}

