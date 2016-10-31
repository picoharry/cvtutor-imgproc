
#include "stdafx.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "Dilation.h"

using namespace std;
using namespace cv;

void cvtutor::imgproc::try_dilation(const Mat src, Mat dst, int, void*)
{
	int dilation_type = 0;
	if (dilation_elem == 0) { dilation_type = MORPH_RECT; }
	else if (dilation_elem == 1) { dilation_type = MORPH_CROSS; }
	else if (dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement(dilation_type,
		Size(2 * dilation_size + 1, 2 * dilation_size + 1),
		Point(dilation_size, dilation_size));

	/// Apply the dilation operation
	dilate(src, dst, element);
	imshow("Dilation Demo", dst);
}
