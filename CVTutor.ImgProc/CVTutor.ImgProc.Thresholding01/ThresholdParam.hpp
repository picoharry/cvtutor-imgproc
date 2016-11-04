#pragma once

#include <opencv2/core/core.hpp>

namespace cvtutor
{
	namespace imgproc
	{
		// tbd ....
		class ThresholdParam
		{
		public:
			ThresholdParam(cv::Mat& src, cv::Mat& dst, int& value, int& maxValue, int& type);
		private:
			cv::Mat& srcMat;
			cv::Mat& dstMat;
			int& value;
			int& maxValue;
			int& thresholdType;
		public:
			cv::Mat& getSrcMat();
			cv::Mat& getDstMat();
			int& getValue() const;
			int& getMaxValue() const;
			int& getThresholdType() const;
		};
	}
}

