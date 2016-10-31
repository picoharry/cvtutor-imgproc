// CVTutor.ImgProc.Smoothing01.cpp : Defines the entry point for the console application.
//

// Tutorial:
// http://docs.opencv.org/3.1.0/dc/dd3/tutorial_gausian_median_blur_bilateral_filter.html


#include "stdafx.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "Util.h"

using namespace std;
using namespace cv;
using namespace cvtutor::imgproc;


int main(int argc, char** argv)
{
	const string window_name = "Smoothing Demo";
	const int DELAY_CAPTION = 1500;
	const int DELAY_BLUR = 100;
	const int MAX_KERNEL_LENGTH = 31;

	string imageName("../../sample-data/lena.jpg"); // by default
	if (argc > 1)
	{
		imageName = argv[1];
	}

	namedWindow(window_name, WINDOW_AUTOSIZE);

	Mat src; Mat dst;

	/// Load the source image
	src = imread(imageName, IMREAD_COLOR);

	if (display_src(window_name, src, "Original Image", DELAY_CAPTION) != 0)
	{
		return 0; 
	}

	dst = src.clone();
	if (display_dst(window_name, dst, DELAY_CAPTION) != 0) 
	{ 
		return 0; 
	}


	/// Applying Homogeneous blur
	if (display_src(window_name, src, "Homogeneous Blur", DELAY_CAPTION) != 0)
	{
		return 0; 
	}

	//![blur]
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		blur(src, dst, Size(i, i), Point(-1, -1));
		if (display_dst(window_name, dst, DELAY_BLUR) != 0)
		{ 
			return 0; 
		}
	}
	//![blur]


	/// Applying Gaussian blur
	if (display_src(window_name, src, "Gaussian Blur", DELAY_CAPTION) != 0) 
	{
		return 0;
	}

	//![gaussianblur]
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		GaussianBlur(src, dst, Size(i, i), 0, 0);
		if (display_dst(window_name, dst, DELAY_BLUR) != 0)
		{ 
			return 0; 
		}
	}
	//![gaussianblur]


	/// Applying Median blur
	if (display_src(window_name, src, "Median Blur", DELAY_CAPTION) != 0)
	{ 
		return 0; 
	}

	//![medianblur]
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		medianBlur(src, dst, i);
		if (display_dst(window_name, dst, DELAY_BLUR) != 0)
		{ 
			return 0; 
		}
	}
	//![medianblur]


	/// Applying Bilateral Filter
	if (display_src(window_name, src, "Bilateral Blur", DELAY_CAPTION) != 0)
	{ 
		return 0;
	}

	//![bilateralfilter]
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		bilateralFilter(src, dst, i, i * 2, i / 2);
		if (display_dst(window_name, dst, DELAY_BLUR) != 0)
		{ 
			return 0; 
		}
	}
	//![bilateralfilter]


	/// Wait until user press a key
	display_src(window_name, src, "End: Press a key!", 0);

	//waitKey(0);
	// return 0;
}
