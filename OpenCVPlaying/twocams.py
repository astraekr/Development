import cv2
#import cv2.cv as cv
import numpy as np

FRAME_WIDTH = 3
FRAME_HEIGHT = 4
CV_CAP_PROP_CONVERT_RGB = 16
CV_CAP_PROP_FORMAT = 8

def nothing(x):
    pass

# create trackbars for color change
cv2.namedWindow('parameters')
cv2.createTrackbar('R_min','parameters',0,255,nothing)
cv2.createTrackbar('R_max','parameters',0,255,nothing)
cv2.createTrackbar('B_min','parameters',0,255,nothing)
cv2.createTrackbar('B_max','parameters',0,255,nothing)
cv2.createTrackbar('G_min','parameters',0,255,nothing)
cv2.createTrackbar('G_max','parameters',0,255,nothing)

#start video capture 0-> integrated webcam 1-> usb webcam//
cap = cv2.VideoCapture(0)
#cap2 = cv2.VideoCapture(1)

#set the camera resolution
cap.set(FRAME_WIDTH,1280)
cap.set(FRAME_HEIGHT,720)
#cap.set(CV_CAP_PROP_FORMAT, 1)

#cap2.set(FRAME_WIDTH,1280)
#cap2.set(FRAME_HEIGHT,720)
#cap2.set(CV_CAP_PROP_FORMAT, 1)

x=1

while(True):
    x=0
    # Capture frame-by-frame
    ret, frame = cap.read()
    #ret2, frame2 = cap2.read()

    #gray = cv2.cvtColor(frame2, cv2.COLOR_BGR2GRAY)

    rbg = [4]
    rbg = cv2.split(frame)

    #print(rbg[0])

    #(frame_b,frame_g,frame_r) = cv2.split(frame)

    # define range of blue color in HSV from the trackbar positions
    Rtt=cv2.getTrackbarPos('R_min','parameters')
    Rut=cv2.getTrackbarPos('R_max','parameters')
    Btt=cv2.getTrackbarPos('B_min','parameters')
    But=cv2.getTrackbarPos('B_max','parameters')
    Gtt=cv2.getTrackbarPos('G_min','parameters')
    Gut=cv2.getTrackbarPos('G_max','parameters')

    minColour = np.array([Btt,Gtt,Rtt])
    maxColour = np.array([But,Gut,Rut])

    mask = cv2.inRange(frame, minColour, maxColour)
    out = cv2.bitwise_and(frame, frame, mask = mask)


    # Display the resulting frame
    cv2.imshow('frame',frame)
    cv2.imshow('rbg', out)
    #cv2.imshow('frame_2_gray',gray)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()
