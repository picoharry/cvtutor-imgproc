
#include "stdafx.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "Erosion.h"

using namespace std;
using namespace cv;

void cvtutor::imgproc::try_erosion(const Mat src, Mat dst, int, void*)
{
	int erosion_type = 0;
	if (erosion_elem == 0) { erosion_type = MORPH_RECT; }
	else if (erosion_elem == 1) { erosion_type = MORPH_CROSS; }
	else if (erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

	//![kernel]
	Mat element = getStructuringElement(erosion_type,
		Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		Point(erosion_size, erosion_size));
	//![kernel]

	/// Apply the erosion operation
	erode(src, dst, element);
	imshow("Erosion Demo", dst);
}
