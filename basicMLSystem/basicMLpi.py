import serial
import time
import random
from datetime import datetime
from datetime import timedelta
import numpy as np
import cv2
from pylepton import Lepton
import os


getDataCommand = 10
getDataCommand1 = 0
getKnobCommand = 11
temperatureMessage = 12
uvMessage = 13
terminator = 254

runTime = timedelta(minutes = 60)
dataSampleTime = timedelta(seconds = 10)
servoSetTime = timedelta(minutes = 1)



ser = serial.Serial(
	port='/dev/ttyS0',
	baudrate=9600,
	parity=serial.PARITY_NONE,
	stopbits=serial.STOPBITS_ONE,
	bytesize=serial.EIGHTBITS,
	timeout=1
)

def main():
    startTimeRaw = datetime.now()
    startTime = str(startTimeRaw)
    
    if ser.isOpen() != True:
    	ser.open()    
    print ('Beginning Program')
    
    dirName = startTime
    if not os.path.exists(dirName):
        os.makedirs(dirName)
    
    f = open(dirName + '/' + startTime + ".txt", 'w')
    f.write(startTime + " , ")
    f.write('Temp:  ' + ',UV: '+',Knob: ')
    f.write('\r\n')

    sendInitialiseCommand()
    time.sleep(15)

    loop = 0
    #LOOP UNTIL THE PROGRAM HAS RUN FOR A NUMBER OF HOUR
    while ((datetime.now() - startTimeRaw) < runTime):
        loop = loop +1
        
        if (loop % 12 == 0) or (loop == 1):
            pos = setServoPosition()
            
        time.sleep(10)    
        timeToday = str(datetime.now())    
        readData = grabData()

        with Lepton() as l:
            a,_ = l.capture()
            
        cv2.normalize(a,a,0,65535, cv2.NORM_MINMAX) #extends contrast
        np.right_shift(a,8,a) #fit data into 8 bits
        cv2.imwrite(dirName+ '/' +timeToday+'.jpg', np.uint8(a)) #write to file

        #convert floats to strings for writing to file
        tempSTR = str(readData[0])
        uvSTR = str(readData[1])

        #write the data to file
        f.write(timeToday + " , ")
        f.write(tempSTR + ' ,'+ uvSTR +' ,'+ str(pos))
        f.write('\r\n')
        

    print ('Ending program')
    f.close()
    

def grabData ():
    #print('Grab data command\r\n')
    sendDataGrabCommand()
    data = ''
    while ser.inWaiting() == 0:
        None

    while (ser.inWaiting() > 0):
        data += ser.read(6)


    #temp = 0-1023 = 0-5V =0.01V/degree
    #if (data[0] == temperatureMessage):
    if (data[0] == 't'):
        temperature = (float)((ord(data[1]) << 8) | ord(data[2]))
        #print('Temperature = ', temperature)
        temperature = ((5.0/1023.0) * temperature)
        temperature = ((temperature * 100) - 273)
        temperature = round(temperature, 3)
        #print('Temperature = ', temperature)    

    if (data[3] == 'u'):
        uv = (float)((ord(data[4]) << 8) | ord(data[5]))
        #print('UV = ', uv)

    returnData = [temperature, uv]
    return returnData

def sendInitialiseCommand ():
    ser.write(bytes("DBB"))

def sendDataGrabCommand ():
    #65, 66 is the command to grab data
    #python3
    #ser.write(bytes("AB", "utf-8"))
    ser.write(bytes("ABB"))


def setServoPosition ():
    #chr function turns it into the ascii value
    position = random.randrange(1,1080)
    sendPosition1 = chr(position & 255)
    sendPosition2 = chr((position >> 8) & 7)
    #position2 = chr(random.randrange(1,4)
    ser.write("C"+sendPosition1+sendPosition2)

    return position
	


if __name__ == "__main__": main()
