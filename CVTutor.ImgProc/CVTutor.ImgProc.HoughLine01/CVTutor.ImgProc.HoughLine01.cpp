// CVTutor.ImgProc.HoughLine01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;


int main(int argc, char** argv)
{
	string imageName("../../sample-data/pic5.png");
	if (argc > 1)
	{
		imageName = argv[1];
	}

	Mat src = imread(imageName);
	if (!src.data)
	{
		cerr << "Failed to load image: " << imageName << endl;
		system("pause");
		return -1;
	}

	Mat dst, cdst;
	Canny(src, dst, 50, 200, 3);
	cvtColor(dst, cdst, COLOR_GRAY2BGR);

	int threshold = 100;
	if (argc > 2) {
		threshold = stoi(argv[2]);
	}

	auto useP = true;
	// auto useP = false;
	if (argc > 3) {
		if (argv[3] == "p" || argv[3] == "P") {
			useP = true;
		}
	}

	if (useP)
	{
		vector<Vec4i> lines;
		HoughLinesP(dst, lines, 1, CV_PI / 180, threshold, 50, 10);
		for (size_t i = 0; i < lines.size(); i++)
		{
			Vec4i l = lines[i];
			line(cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, LINE_AA);
		}
	}
	else {
		vector<Vec2f> lines;
		HoughLines(dst, lines, 1, CV_PI / 180, threshold, 0, 0);

		for (size_t i = 0; i < lines.size(); i++)
		{
			float rho = lines[i][0], theta = lines[i][1];
			Point pt1, pt2;
			double a = cos(theta), b = sin(theta);
			double x0 = a*rho, y0 = b*rho;
			pt1.x = cvRound(x0 + 1000 * (-b));
			pt1.y = cvRound(y0 + 1000 * (a));
			pt2.x = cvRound(x0 - 1000 * (-b));
			pt2.y = cvRound(y0 - 1000 * (a));
			line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, CV_AA);
		}
	}

	imshow("source", src);
	imshow("detected lines", cdst);

	waitKey();
	return 0;
}

