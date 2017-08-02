import cv2
import cv2.cv as cv
import numpy as np

FRAME_WIDTH = 3
FRAME_HEIGHT = 4

def nothing(x):
    pass

# create trackbars for color change
cv2.namedWindow('parameters')
cv2.createTrackbar('H_l','parameters',0,255,nothing)
cv2.createTrackbar('H_u','parameters',0,255,nothing)
cv2.createTrackbar('S_l','parameters',0,255,nothing)
cv2.createTrackbar('S_u','parameters',0,255,nothing)
cv2.createTrackbar('V_l','parameters',0,255,nothing)
cv2.createTrackbar('V_u','parameters',0,255,nothing)
cv2.createTrackbar('Min_diam','parameters',0,255,nothing)
cv2.createTrackbar('Max_diam','parameters',10,255,nothing)


#start video capture 0-> integrated webcam 1-> usb webcam//
cap = cv2.VideoCapture(0)

cap2 = cv2.VideoCapture(1)
#set the camera resolution
cap.set(FRAME_WIDTH,1280)
cap.set(FRAME_HEIGHT,720)

cap2.set(FRAME_WIDTH,1280)
cap2.set(FRAME_HEIGHT,720)


while(True):
    # Capture frame-by-frame
    ret, frame = cap.read()
    ret2, frame2 = cap2.read()
    (frame_b,frame_g,frame_r) = cv2.split(frame)

    # transform the image to gray scale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    #blur the image to make easier the circle detection
    img = cv2.medianBlur(gray,5)

    # define range of blue color in HSV from the trackbar positions
    Hlt=cv2.getTrackbarPos('H_l','parameters')
    Hut=cv2.getTrackbarPos('H_t','parameters')
    Slt=cv2.getTrackbarPos('S_l','parameters')
    Sut=cv2.getTrackbarPos('S_t','parameters')
    Vlt=cv2.getTrackbarPos('V_l','parameters')
    Vut=cv2.getTrackbarPos('V_t','parameters')

    lower_tresh = np.array([Hlt,Slt,Vlt])
    upper_tresh = np.array([Hut,Sut,Vut])
    #lower_tresh = np.array([110,50,50])
    upper_tresh = np.array([255,255,255])

    # Threshold the HSV image to get only blue colors
    mask = cv2.inRange(hsv, lower_tresh, upper_tresh)
    # Bitwise-AND mask and original image
    res = cv2.bitwise_and(frame,frame, mask= mask)

    MinD=cv2.getTrackbarPos('Min_diam','parameters')
    MaxD=cv2.getTrackbarPos('Max_diam','parameters')

    if MaxD<5:
        MaxD=5;
    #look for circles in the image
    circles = cv2.HoughCircles(img,cv.CV_HOUGH_GRADIENT,1,20,param1=50,param2=30,minRadius=MinD,maxRadius=MaxD)
    if circles != None:
        circles = np.uint16(np.around(circles))

        #mark all the cricles
        for i in circles[0,:]:
            # draw the outer circlecv2.imshow('frame',graycv2.imshow('frame',gray)cv2.imshow('frame',gray))
            cv2.circle(img,(i[0],i[1]),i[2],(0,255,0),2)
            # draw the center of the circle
            cv2.circle(img,(i[0],i[1]),2,(0,0,255),3)

    cv2.imshow('detected circles',img)
    # Display the resulting frame
    cv2.imshow('frame',frame)
    cv2.imshow('res',res)
    cv2.imshow('frame_gray',gray)

    cv2.imshow('frame2',frame2)
    #cv2.imshow('frame_r',frame_r)
    #cv2.imshow('frame_g',frame_g)
    #cv2.imshow('frame_b',frame_b)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()
