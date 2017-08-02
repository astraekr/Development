import serial
import time
import random
from datetime import datetime
from datetime import timedelta
import numpy as np
import cv2
import os

def setServoPosition ():
    #chr function turns it into the ascii value
    position = random.randrange(1,1080)
    
    print('position = '+ str(position))
    print('position & 255 = ' + str(position & 255))
    
    sendPosition1 = chr(position & 255)    
    print(sendPosition1)

    print('position >>8 &7 =' + str((position >>8)&7))
    sendPosition2 = chr((position >> 8) & 7)
    
    print(sendPosition2)


    return sendPosition1, sendPosition2, position


position1, position2, pos = setServoPosition()

print(str(ord(position1)) + str(ord(position2)))

print('try pos = ' + str(pos))
