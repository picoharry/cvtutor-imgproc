#include "stdafx.h"
#include "ThresholdParam.hpp"

using namespace cv;
using namespace std;

cvtutor::imgproc::ThresholdParam::ThresholdParam(cv::Mat& src, cv::Mat& dst, int& val, int& maxVal, int& type)
	: srcMat(src), dstMat(dst), thresholdType(type), value(val), maxValue(maxVal)
{
}

Mat& cvtutor::imgproc::ThresholdParam::getSrcMat()
{
	return srcMat;
}

Mat& cvtutor::imgproc::ThresholdParam::getDstMat()
{
	return dstMat;
}

int& cvtutor::imgproc::ThresholdParam::getValue() const
{
	return value;
}

int& cvtutor::imgproc::ThresholdParam::getMaxValue() const
{
	return maxValue;
}

int& cvtutor::imgproc::ThresholdParam::getThresholdType() const
{
	return thresholdType;
}

