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
			// MorphParam(cv::Mat& src, cv::Mat& dst);
			MorphParam(cv::Mat& src, cv::Mat& dst, int& type, int& size);
		private:
			cv::Mat& srcMat;
			cv::Mat& dstMat;
			int& morphType;
			int& morphSize;
		public:
			//void setSrcMat(cv::Mat& src);
			//void setDstMat(cv::Mat& dst);
			cv::Mat& getSrcMat();
			cv::Mat& getDstMat();
			int& getMorphType() const;
			int& getMorphSize() const;
		};
	}
}

