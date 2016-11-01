#include "stdafx.h"
#include "MorphParam.hpp"

using namespace cv;
using namespace std;


cvtutor::imgproc::MorphParam::MorphParam(cv::Mat& src, cv::Mat& dst)
	: srcMat(src), dstMat(dst)
{
}

Mat& cvtutor::imgproc::MorphParam::getSrcMat()
{
	return srcMat;
}

Mat& cvtutor::imgproc::MorphParam::getDstMat()
{
	return dstMat;
}
