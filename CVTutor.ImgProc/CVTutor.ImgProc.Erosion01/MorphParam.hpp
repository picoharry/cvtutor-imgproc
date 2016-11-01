#pragma once

#include <opencv2/core/core.hpp>

namespace cvtutor
{
	namespace imgproc
	{
		// tbd ....
		class MorphParam
		{
		public: 
			MorphParam(cv::Mat& src, cv::Mat& dst);
		private:
			cv::Mat& srcMat;
			cv::Mat& dstMat;
		public:
			//void setSrcMat(cv::Mat& src);
			//void setDstMat(cv::Mat& dst);
			cv::Mat& getSrcMat();
			cv::Mat& getDstMat();
		};
	}
}

