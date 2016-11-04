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
			// ThresholdParam(cv::Mat& src, cv::Mat& dst);
			ThresholdParam(cv::Mat& src, cv::Mat& dst, double& value, double& maxValue, int& type);
			ThresholdParam(cv::Mat& src, cv::Mat& dst, int& value, int& maxValue, int& type);
		private:
			cv::Mat& srcMat;
			cv::Mat& dstMat;
			double& value;
			double& maxValue;
			int& thresholdType;
		public:
			cv::Mat& getSrcMat();
			cv::Mat& getDstMat();
			double& getValue() const;
			double& getMaxValue() const;
			int& getThresholdType() const;
		};
	}
}

