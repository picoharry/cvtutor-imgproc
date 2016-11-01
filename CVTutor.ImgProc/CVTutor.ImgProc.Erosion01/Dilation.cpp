
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
	Mat src = param->getSrcMat();
	Mat dst = param->getDstMat();

	// tbd:
	int dilation_type = MORPH_RECT;
	//if (dilation_elem == 0) { dilation_type = MORPH_RECT; }
	//else if (dilation_elem == 1) { dilation_type = MORPH_CROSS; }
	//else if (dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

	// tbd:
	int dilation_size = 10;
	Mat element = getStructuringElement(dilation_type,
		Size(2 * dilation_size + 1, 2 * dilation_size + 1),
		Point(dilation_size, dilation_size));

	/// Apply the dilation operation
	dilate(src, dst, element);
	imshow("Dilation Demo", dst);
}
