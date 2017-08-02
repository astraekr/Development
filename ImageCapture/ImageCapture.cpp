#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>
#include <unistd.h>
#include <iostream>

using namespace cv;
using namespace std;

const string leftNames [11] = {"left01.jpg",
                            "left02.jpg",
                            "left03.jpg",
                            "left04.jpg",
                            "left05.jpg",
                            "left06.jpg",
                            "left07.jpg",
                            "left08.jpg",
                            "left09.jpg",
                            "left10.jpg",
                            "left11.jpg"};

const string rightNames [11] = {"right01.jpg",
                            "right02.jpg",
                            "right03.jpg",
                            "right04.jpg",
                            "right05.jpg",
                            "right06.jpg",
                            "right07.jpg",
                            "right08.jpg",
                            "right09.jpg",
                            "right10.jpg",
                            "right11.jpg"};


///Having issues with actually showing images from the two webcams - looks like I need
/// to change resolution or the compression.
/// TODO:
/// -try usb3 hub on the side of the laptop
/// -change the resolution of the vid streams
/// -change the compression
/// TOOLS:
/// v4l2-ctl -d /dev/video0 --list-formats

int main (int argc, char ** argv )
{

	Mat left, right;
        int i = 0;

        VideoCapture capture1 = VideoCapture(1);
        VideoCapture capture2 = VideoCapture(2);
        capture2.open(1);
        capture2.open(2);

        while(true)
        {
            namedWindow("Named Window", WINDOW_AUTOSIZE);
            int l = waitKey(0);
            while(l != 'x');

            capture1.read(left);
            if(!left.empty())
            {
                namedWindow("left", WINDOW_AUTOSIZE);
                imshow("left", left);

                int cc = waitKey(0);
                while(cc != 'x');
                cout << i <<'\n';
                imwrite(leftNames[i], left );
            }


            capture2.read(right);
            if(!right.empty())
            {
                namedWindow("right", WINDOW_AUTOSIZE);
                imshow("right", right);
                int c = waitKey(0);
                while(c != 'x');
                cout << i <<'\n';
                i++;
                imwrite(rightNames[i], right );
            }

            //make this wait for <= 0 to make it wait infinitely

            if(i >11)
            {
               destroyWindow("right");
               capture2.release();
               break;
            }
        }

	namedWindow("Display Image", WINDOW_AUTOSIZE);
        imshow("Display Image", right);



	waitKey(0);
	return 0;
	
}




