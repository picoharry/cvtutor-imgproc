#include "stdafx.h"
#include "MorphParam.hpp"

using namespace cv;
using namespace std;


//cvtutor::imgproc::MorphParam::MorphParam(cv::Mat& src, cv::Mat& dst)
//	: srcMat(src), dstMat(dst)
//{
//}
cvtutor::imgproc::MorphParam::MorphParam(cv::Mat& src, cv::Mat& dst, int& type, int& size)
	: srcMat(src), dstMat(dst), morphType(type), morphSize(size)
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

int& cvtutor::imgproc::MorphParam::getMorphType() const
{
	return morphType;
}

int& cvtutor::imgproc::MorphParam::getMorphSize() const
{
	return morphSize;
}

