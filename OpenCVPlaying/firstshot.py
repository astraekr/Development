import cv2
import numpy as np
import time

camera_port = 0

ramp_frames = 30
print("error now")
camera =cv2.VideoCapture(camera_port)

def getImage():
    retval, im = camera.read()
    return im

print("Taking image")
camera_capture = getImage()
print("Image taken")
#img = cv2.imread("/dev/video1")

file ="/home/d46/pic.png"
cv2.imwrite(file, camera_capture)

cv2.imshow("webcam", camera_capture)


px = camera_capture[100,100]

print px

while 1:
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
#cap.release()
cv2.destroyAllWindows()
