#include "stdafx.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "Util.h"

using namespace std;
using namespace cv;


int cvtutor::imgproc::display_src(const string window_name, const Mat src, const string caption, const int caption_delay)
{
	Mat dst = Mat::zeros(src.size(), src.type());
	putText(dst, caption,
		Point(src.cols / 4, src.rows / 2),
		FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));

	imshow(window_name, dst);
	int c = waitKey(caption_delay);
	if (c >= 0)
	{ 
		return -1;
	}
	return 0;
}

int cvtutor::imgproc::display_dst(const string window_name, const Mat dst, const int delay)
{
	imshow(window_name, dst);
	int c = waitKey(delay);
	if (c >= 0) {
		return -1;
	}
	return 0;
}
