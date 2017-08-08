/* Program to retrieve images pre-AGC from
 * FLIR Boson camera using VPC/USB interface
 *
 * Initial code from
 * ChristIanPetrucci @
 * http://answers.opencv.org/question/93848/problem-black-image/
 *
 *
 *
 * */

#include "opencv2/opencv.hpp"
#include "libuvc/libuvc.h"
#include <libusb-1.0/libusb.h>

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;


//NOTE set these to appropriate values 320x256??
//what is kcurve data?
static const int kCaptureWidth = 640;  //resolution
static const int kCaptureHeight = 512;
static const int kCaptureFPS = 0;  //frame/s
static const char kCurveData[8] = {250, 0, 240, 0, 250, 0, 240, 0};

/* This callback function runs once per frame. Use it to perform any
 * quick processing you need, or have it put the frame into your application's
 * input queue. If this function takes too long, you'll start losing frames. */
void cb(uvc_frame_t *frame, void *stopPtr) {
  cv::Mat cvFrame(frame->height, frame->width, CV_16UC1, frame->data);
  cvFrame.convertTo(cvFrame, CV_16U, 100, 0);
  imshow("main", cvFrame);
}

void setLights(uvc_device_handle_t *devh, int lights) {
  uvc_set_ctrl(devh, 3, 3, (void*)(&lights), 2);
}

void setupParams(uvc_device_handle_t *devh) {
  uvc_set_ctrl(devh, 3, 4, (void*)(kCurveData), 8);
}
/*
uint8_t open_port(libusb_device_handle *devh){

    int rc;
     We only need to deal with the CDC data interface on Boson, it has sane control defaults
    if (libusb_kernel_driver_active(devh, IF_CDC_DATA)) {
        libusb_detach_kernel_driver(devh, IF_CDC_DATA);
    }
    rc = libusb_claim_interface(devh, IF_CDC_DATA);
    if (rc < 0) {
        fprintf(stderr, "Error claiming interface: %s\n",
                libusb_error_name(rc));
    }

    return (uint8_t) rc; // 0 == success.
}*/

int main()
{
    cout << "Hello World!" << endl;
    VideoCapture cap;
    uvc_context_t *ctx;
    uvc_device_t *dev;
    uvc_device_handle_t *devh;
    uvc_stream_ctrl_t ctrl;
    uvc_error_t res;
    uvc_device_descriptor_t *desc;
    //ask tom why this doesn't work
    //enum uvc_frame_format uvcFormat = UVC_FRAME_FORMAT_I420;

    enum uvc_frame_format uvcFormat = (uvc_frame_format) 5;


    res = uvc_init(&ctx, NULL);
    if (res < 0)
    {
        uvc_perror(res, "uvc_init");  //error initialize
        return res;
    }
    cv::namedWindow("main",CV_WINDOW_NORMAL);

    puts("UVC initialized");

    /* Locates the first attached UVC device, stores in dev */
    //NOTE find the device details for FLIR BOSON
    //func gives context and empty pointer for new device then info
    //NOTE add print statements to getthermal to find these? - uvc_print_diag(devh, stderr);
    res = uvc_find_device(
        ctx, &dev,
        0, 0, NULL); /* filter devices: vendor_id, product_id, "serial_num" */
    if (res < 0)
    {
        uvc_perror(res, "uvc_find_device"); /* no devices found */
    }
    else
    {
        puts("Device found");
        /* Try to open the device: requires exclusive access */
        res = uvc_open(dev, &devh);

        if (res < 0)
        {
            uvc_perror(res, "uvc_open"); /* unable to open device */
        }
        else
        {
            puts("Device opened");
                /* Print out a message containing all the information that libuvc
                * knows about the device */
            uvc_print_diag(devh, stderr);

            printf("Initializing Boson with UVC backend...\n");

            uvc_get_device_descriptor(dev, &desc);
            printf("Using %s %s with firmware %s\n", desc->manufacturer, desc->product, desc->serialNumber);

            //NOTE MIGHT need to try and get this working
            //open_port(devh);

            uvc_free_device_descriptor(desc);
                /* Try to negotiate a YUYV stream profile */
            uvc_stop_streaming(devh);
            //NOTE figure out what this does
            res = uvc_get_stream_ctrl_format_size(
                    devh, &ctrl,                /* result stored in ctrl */
                    UVC_FRAME_FORMAT_I420,      /* YUV 422, aka YUV 4:2:2. try _COMPRESSED */
                    kCaptureWidth, kCaptureHeight, kCaptureFPS /* width, height, fps */
                    );

            uvc_print_stream_ctrl(&ctrl, stderr);

            if (res < 0)
            {
                uvc_perror(res, "get_mode"); /* device doesn't provide a matching stream */
            }
            else
            {
                //setLights(devh, 0xb1111);
                int stop = 0;
                /* Start the video stream. The library will call user function cb:
                *   cb(frame, (void*) 0)
                */
                res = uvc_start_streaming(devh, &ctrl, cb, (void*)(&stop), 0);
                if (res < 0)
                {
                    uvc_perror(res, "start_streaming"); /* unable to start stream */
                }
                else
                {
                    puts("Streaming...");

                    // uvc_set_ae_mode(devh, 1); /* e.g., turn on auto exposure */
                    while(true)
                    {
                        int key = cv::waitKey(10);
                        if((char)key == 'q')
                        {
                            break;
                        }
                        if((char)key == 'o')
                        {
                            //setLights(devh, 0);
                        }
                        if((char)key == 'p')
                        {
                            setupParams(devh);
                        }
                        if((char)key == 'g')
                        {
                            uvc_set_gain(devh, 25);
                        }
                    }
                    //setLights(devh, 0);
                    //Sleep(1);
                    /* End the stream. Blocks until last callback is serviced */
                    uvc_stop_streaming(devh);
                    puts("Done streaming.");
                }
            }
            /* Release our handle on the device */
            uvc_close(devh);
            puts("Device closed");
        }
        /* Release the device descriptor */
        uvc_unref_device(dev);
    }
    /* Close the UVC context. This closes and cleans up any existing device handles,
     * and it closes the libusb context if one was not provided. */
    uvc_exit(ctx);
    puts("UVC exited");
    return 0;
}



