#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


/*
 *
 *./ImageRectification ../ImageRectification/test_webcam_r.jpg ../ImageRectification/test_webcam_centre.jpg ../ImageRectification/test_infrared_flip.jpg ../../out_camera_data_0.xml ../../out_camera_data_1.xml
 *
 *
 */


int main (int argc, char ** argv )
{

    /*
     * Handle arguments
     *
     */

    if (argc != 6)
	{
        printf("usage: displayimage.out <image_right_path> <image_centre_path> <image_left_path> <left_camera_data> <centre_camera_data>\n");
		return -1;
	}

    //Get camera matrices and settings from settings file
    const string inputSettingsFile_camRight = argv[4];
    const string inputSettingsFile_camCentre = argv[5];

    FileStorage fs_Right(inputSettingsFile_camRight, FileStorage::READ);
    if(!fs_Right.isOpened())
    {
        cout << "Could not open the camera characteristic file:\"" << inputSettingsFile_camRight << "\"" << endl;
        return -1;
    }

    Mat cCameraMatrix, rCameraMatrix;
    Mat cDistMatrix, rDistMatrix;
    Mat cExtParams, rExtParams;


    fs_Right["camera_matrix"] >> rCameraMatrix;
    fs_Right["distortion_coefficients"] >> rDistMatrix;
    fs_Right["extrinsic_parameters"] >> rExtParams;

    fs_Right.release();

    FileStorage fs_Centre(inputSettingsFile_camCentre, FileStorage::READ);
    if(!fs_Centre.isOpened())
    {
        cout << "Could not open the camera characteristic file:\"" << inputSettingsFile_camCentre << "\"" << endl;
        return -1;
    }

    fs_Centre["camera_matrix"] >> cCameraMatrix;
    fs_Centre["distortion_coefficients"] >> cDistMatrix;
    fs_Centre["extrinsic_parameters"] >> cExtParams;

    fs_Centre.release();


    /*
     * Get images
     *
     */
	Mat leftImageTemp, leftImage, rightImage, centreImage;
	
	//Right webcam  image, 352x288 pixels
	rightImage = imread( argv[1], 0);	
	//Centre webcam  image, 352x288 pixels
	centreImage = imread( argv[2], 0);
	//IR camera, 80x60 pixels
	leftImageTemp = imread( argv[3], 0);
	
	if (!leftImageTemp.data | !rightImage.data | !centreImage.data)
	{
		printf("No image data in at least one image\n");
		return -1;
	}
	
	//scale the IR image to be of equal resolution to the other two
	resize(leftImageTemp, leftImage, Size(), 4.4, 4.8, INTER_LINEAR);
	
	
	namedWindow("Display Image Left", WINDOW_AUTOSIZE);
	namedWindow("Display Image Centre", WINDOW_AUTOSIZE);
	namedWindow("Display Image Right", WINDOW_AUTOSIZE);
	
	imshow("Display Image Left", leftImage);
	imshow("Display Image Centre", centreImage);
    imshow("Display Image Right", rightImage);

    /****************************************************
     *
     *
     *      CALIBRATED METHOD
     *
     *
     ****************************************************/
   Size imgSize = Size(352,288);
   OutputArray R1 = noArray();
   OutputArray R2 = noArray();
   OutputArray P2 = noArray();
   OutputArray P1 = noArray();
   OutputArray Q = noArray();
   int flags=CALIB_ZERO_DISPARITY;
   double alpha=-1;
   Rect* validPixROI1=0;
   Rect* validPixROI2=0



   stereoRectify(rCameraMatrix, cCameraMatrix, rDistMatrix, cDistMatrix, imgSize
                  InputArray R, InputArray T, R1, R2,
                   P1, P2, Q, flags,
                  alpha, imgSize, validPixROI1, validPixROI2);

	
    /****************************************************
     *
     *
     *      UNCALIBRATED METHOD
     *
     *
     ****************************************************/

     /*
	//Find features in the image to track 
	vector< Point2f > cornersCentre;
	vector< Point2f > cornersRight;
	int maxCorners = 10;
	double qualityLevel = 0.01;
	double minDistance = 10.;
	Mat mask;
	int blockSize = 3;
	bool useHarrisDetector = false;
	double k = 0.04;	
	
	goodFeaturesToTrack(centreImage, cornersCentre, maxCorners, qualityLevel, minDistance, mask, blockSize, useHarrisDetector, k);
	goodFeaturesToTrack(rightImage, cornersRight, maxCorners, qualityLevel, minDistance, mask, blockSize, useHarrisDetector, k);
	
	for( size_t i = 0; i < cornersCentre.size(); i++ )
    {
		circle( centreImage, cornersCentre[i], 10, Scalar( 255. ), -1 );
		circle( rightImage, cornersRight[i], 10, Scalar( 255. ), -1 );
	}
	
	//Find the sub-pixel locations of the features
	Size winSize = Size(5,5);
	Size zeroZone = Size(-1,-1);
	TermCriteria criteria = TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 40, 0.001);
	
	
	cornerSubPix(centreImage, cornersCentre, winSize, zeroZone, criteria);
	cornerSubPix(rightImage, cornersRight, winSize, zeroZone, criteria);

	winSize = Size(21,21);
	int maxLevel=3;
	criteria=TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 30, 0.01);
	int flags=0;
	double minEigThreshold=1e-4;
	vector< uchar > status;
	vector< float > err;
	
	calcOpticalFlowPyrLK(centreImage, rightImage, cornersCentre, cornersRight,
						status, err, winSize, maxLevel, criteria, flags, minEigThreshold);

	//get the fundamental matrix (related to the epipolar geometry) 3x3 matrix
	Mat fundamentalMatrix;
	int method=FM_RANSAC;
	double param1=3.;
	double param2=0.99;
    OutputArray outMask = noArray();
	
    fundamentalMatrix = findFundamentalMat(cornersCentre, cornersRight, method,  param1, param2, outMask );
	

	//Get the homography matrices, which allow the images to be rectified
	Size imgSize = Size(352,288);
	bool result = false;
//	OutputArray H1 = noArray();		//output homography matrix for the first image
//	OutputArray H2 = noArray();		//output homography matrix for the second image
	double threshold = 5;
	
    //result = stereoRectifyUncalibrated(cornersCentre, cornersRight, fundamentalMatrix, imgSize, H1, H2, threshold);
	
	//R1 = inv(CamMatrix1)*H1*CamMatrix1 R2 = inv(CamMatrix2)*H2*CamMatrix2
	//R1 and R2 - these are rotation matrices - different to R
	//Get remap matrix - ready to actually rectify the images
	
    InputArray cameraMatrix = noArray();		//this is the matrix of the camera which is to be rectified
    InputArray distCoeffs = noArray();			//input vector of distortion coefficients - need to find where this actually is
    InputArray R = noArray();                   //Rectification transformation - optional (identity matrix is assumed if left zero)
    InputArray newCameraMatrix = noArray();		//this is the matrix of the camera in the centre
	int m1type = CV_16SC2;
//	OutputArray map1 = noArray();
//	OutputArray map2 = noArray();
	
//	initUndistortRectifyMap(cameraMatrix, distCoeffs, R, newCameraMatrix, imgSize, m1type, map1, map2);
    */
	


	namedWindow("Display Image Centre", WINDOW_AUTOSIZE);
	imshow("Display Image Centre", centreImage);
	

	waitKey(0);
	
	return 0;
	
}
//http://www.bogotobogo.com/cplusplus/files/OReilly%20Learning%20OpenCV.pdf
//http://www.ece.ucsb.edu/~manj/ece181bS04/ECE_181b_HW2/rectification_key.pdf good homework class

/*UNCALIBRATED METHOD FROM http://stackoverflow.com/questions/4260594/image-rectification
 * 
void goodFeaturesToTrack(InputArray image, OutputArray corners, int maxCorners, double qualityLevel, double minDistance, InputArray mask=noArray(), int blockSize=3, bool useHarrisDetector=false, double k=0.04 )

void cornerSubPix(InputArray image, InputOutputArray corners, Size winSize, Size zeroZone, TermCriteria criteria)

void calcOpticalFlowPyrLK(InputArray prevImg, InputArray nextImg, InputArray prevPts, InputOutputArray nextPts, OutputArray status, OutputArray err, Size winSize=Size(21,21), int maxLevel=3, TermCriteria criteria=TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 30, 0.01), int flags=0, double minEigThreshold=1e-4 )

Mat findFundamentalMat(InputArray points1, InputArray points2, int method=FM_RANSAC, double param1=3., double param2=0.99, OutputArray mask=noArray() )

bool stereoRectifyUncalibrated(InputArray points1, InputArray points2, InputArray F, Size imgSize, OutputArray H1, OutputArray H2, double threshold=5 )

void initUndistortRectifyMap(InputArray cameraMatrix, InputArray distCoeffs, InputArray R, InputArray newCameraMatrix, Size size, int m1type, OutputArray map1, OutputArray map2)

void remap(InputArray src, OutputArray dst, InputArray map1, InputArray map2, int interpolation, int borderMode=BORDER_CONSTANT, const Scalar& borderValue=Scalar())
*/

/* ANOTHER METHOD
 * 
 * stereoCalibrate()
 * stereoRectify()
 * 
 */
