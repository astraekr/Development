#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


/*
 *
 *./SuperImpose ../test_webcam_r.jpg ../test_webcam_centre.jpg ../test_infrared_flip.jpg
 *
 *
 */

const string name = "superimposed.jpeg";

int main (int argc, char ** argv )
{

    /*
    * Handle arguments
    *
    */

    if (argc != 4)
    {
        printf("usage: displayimage.out <image_right_path> <image_centre_path> <image_left_path> \n");
            return -1;
    }

    /*
    * Get images
    *
    */
    Mat leftImageTemp, leftImage, rightImage, centreImage, dst, leftImageThresh;
    double input = 0.0;
    double beta;
    double alpha = 0.5;
    double maxValue = 0.0;

    //Right webcam  image, 352x288 pixels
    rightImage = imread( argv[1], 0);
    //Centre webcam  image, 352x288 pixels
    centreImage = imread( argv[2], 0);
    //IR camera, 80x60 pixels
    leftImageTemp = imread( argv[3], 0);

    //cout << leftImageTemp << "\n";

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

    std::cout<<"* Enter Threshold [0-255]: ";
    std::cin>>input;


    threshold(leftImage, leftImageThresh, input, maxValue, THRESH_TOZERO);

    namedWindow("Display Image Left Thresh", WINDOW_AUTOSIZE);
    imshow("Display Image Left Thresh", leftImageThresh);


    std::cout<<"* Enter alpha [0-1]: ";
    std::cin>>input;

    /// We use the alpha provided by the user if it is between 0 and 1
    if( input >= 0.0 && input <= 1.0 )
    {
        alpha = input;
    }

    namedWindow("Linear Blend", 1);
    beta = (1.0 - alpha);

    addWeighted( centreImage, alpha, leftImageThresh, beta, 0.0, dst);

    imshow("Linear Blend", dst);

    imwrite(name, dst);

    waitKey(0);
    return 0;


}
