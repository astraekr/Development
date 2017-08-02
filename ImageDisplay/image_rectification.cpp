#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main (int argc, char ** argv )
{
	if (argc != 2)
	{
		printf("usage: displayimage.out <image_path>\n");
		return -1;
	}
	
	Mat image;
	image = imread( argv[1], 1);
	
	if (!image.data)
	{
		printf("No image data\n");
		return -1
	}
	
	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", image);
	
	waitKey(0);
	
	return 0;
	
}


/*
void goodFeaturesToTrack(InputArray image, OutputArray corners, int maxCorners, double qualityLevel, double minDistance, InputArray mask=noArray(), int blockSize=3, bool useHarrisDetector=false, double k=0.04 )

void cornerSubPix(InputArray image, InputOutputArray corners, Size winSize, Size zeroZone, TermCriteria criteria)

void calcOpticalFlowPyrLK(InputArray prevImg, InputArray nextImg, InputArray prevPts, InputOutputArray nextPts, OutputArray status, OutputArray err, Size winSize=Size(21,21), int maxLevel=3, TermCriteria criteria=TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 30, 0.01), int flags=0, double minEigThreshold=1e-4 )

Mat findFundamentalMat(InputArray points1, InputArray points2, int method=FM_RANSAC, double param1=3., double param2=0.99, OutputArray mask=noArray() )

bool stereoRectifyUncalibrated(InputArray points1, InputArray points2, InputArray F, Size imgSize, OutputArray H1, OutputArray H2, double threshold=5 )

void initUndistortRectifyMap(InputArray cameraMatrix, InputArray distCoeffs, InputArray R, InputArray newCameraMatrix, Size size, int m1type, OutputArray map1, OutputArray map2)

void remap(InputArray src, OutputArray dst, InputArray map1, InputArray map2, int interpolation, int borderMode=BORDER_CONSTANT, const Scalar& borderValue=Scalar())
*/
