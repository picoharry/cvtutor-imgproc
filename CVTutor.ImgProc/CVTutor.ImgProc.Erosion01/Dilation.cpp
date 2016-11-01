
#include "stdafx.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "MorphParam.hpp"
#include "Dilation.h"

using namespace std;
using namespace cv;

void cvtutor::imgproc::try_dilation(int pos, void* arg)
{
	MorphParam* param = (MorphParam*)arg;
	if (param == nullptr) {
		// ????
		return;
	}
	Mat& src = param->getSrcMat();
	Mat& dst = param->getDstMat();
	int& type = param->getMorphType();
	int& size = param->getMorphSize();

	// tbd:
	int dilation_type = MORPH_RECT;
	if (type == 0) { dilation_type = MORPH_RECT; }
	else if (type == 1) { dilation_type = MORPH_CROSS; }
	else if (type == 2) { dilation_type = MORPH_ELLIPSE; }

	// tbd:
	int& dilation_size = size;
	Mat element = getStructuringElement(dilation_type,
		Size(2 * dilation_size + 1, 2 * dilation_size + 1),
		Point(dilation_size, dilation_size));

	/// Apply the dilation operation
	dilate(src, dst, element);
	imshow("Dilation Demo", dst);
}
