
#include "stdafx.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "MorphParam.hpp"
#include "Erosion.h"

using namespace std;
using namespace cv;

void cvtutor::imgproc::try_erosion(int pos, void* arg)
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
	int erosion_type = MORPH_RECT;
	if (type == 0) { erosion_type = MORPH_RECT; }
	else if (type == 1) { erosion_type = MORPH_CROSS; }
	else if (type == 2) { erosion_type = MORPH_ELLIPSE; }

	//![kernel]
	// tbd:
	int& erosion_size = size;
	Mat element = getStructuringElement(erosion_type,
		Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		Point(erosion_size, erosion_size));
	//![kernel]

	/// Apply the erosion operation
	erode(src, dst, element);
	imshow("Erosion Demo", dst);
}
