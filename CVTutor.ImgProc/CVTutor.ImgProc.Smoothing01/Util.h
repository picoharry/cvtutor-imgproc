#pragma once

namespace cvtutor
{
	namespace imgproc
	{
		int display_src(const std::string window_name, const cv::Mat src, const std::string caption, const int caption_delay);
		int display_dst(const std::string window_name, const cv::Mat dst, const int delay);
	}
}
