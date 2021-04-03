#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat image; // 이미지 파일 배열 설정
	image = imread("C:/Users/ksq11/source/repos/OPEN_CV/girl.jpg", IMREAD_COLOR); // 이미지를 읽어 MAT에 대입
	if (image.empty())
	{
		cout << "Image Open Error!" << endl;
		return -1;
	}
	// Threshold.
   // Set values equal to or above 220 to 0.
   // Set values below 220 to 255.
	Mat im_th;
	threshold(image, im_th, 220, 255, THRESH_BINARY_INV);

	// Floodfill from point (0, 0)
	Mat im_floodfill = im_th.clone();
	floodFill(im_floodfill, cv::Point(0, 0), Scalar(255));

	// Invert floodfilled image
	Mat im_floodfill_inv;
	bitwise_not(im_floodfill, im_floodfill_inv);

	// Combine the two images to get the foreground.
	Mat im_out = (im_th | im_floodfill_inv);

	// Display images
	imshow("Thresholded Image", image);
	imshow("Floodfilled Image", im_floodfill);
	imshow("Inverted Floodfilled Image", im_floodfill_inv);
	imshow("Foreground", im_out);
	waitKey(0);

	return 0;
}
