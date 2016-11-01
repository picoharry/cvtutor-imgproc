// CVTutor.ImgProc.Erosion01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "MorphParam.hpp"
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
	// string imageName("../../sample-data/lena.jpg"); // by default
	string imageName("../../sample-data/shape_sample/7.png"); // by default
	if (argc > 1)
	{
		imageName = argv[1];
	}

	/// Load an image
	src = imread(imageName, IMREAD_COLOR);

	if (src.empty())
	{
		return -1;
	}


	/// Create windows
	namedWindow("Erosion Demo", WINDOW_AUTOSIZE);
	namedWindow("Dilation Demo", WINDOW_AUTOSIZE);
	moveWindow("Dilation Demo", src.cols, 0);

	// ????
	src.copyTo(erosion_dst);
	MorphParam erosion_param = MorphParam(src, erosion_dst);
	src.copyTo(dilation_dst);
	MorphParam dilation_param = MorphParam(src, dilation_dst);
	// ????

	/// Create Erosion Trackbar
	createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Demo",
		&erosion_elem, max_elem,
		try_erosion, &erosion_param);

	createTrackbar("Kernel size:\n 2n +1", "Erosion Demo",
		&erosion_size, max_kernel_size,
		try_erosion, &erosion_param);

	/// Create Dilation Trackbar
	createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation Demo",
		&dilation_elem, max_elem,
		try_dilation, &dilation_param);

	createTrackbar("Kernel size:\n 2n +1", "Dilation Demo",
		&dilation_size, max_kernel_size,
		try_dilation, &dilation_param);

	/// Default start
	try_erosion(0, &erosion_param);
	try_dilation(0, &dilation_param);

	waitKey(0);
	return 0;
}
