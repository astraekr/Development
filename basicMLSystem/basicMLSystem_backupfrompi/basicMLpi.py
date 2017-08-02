import serial
import time
import random
from datetime import datetime
from datetime import timedelta
import numpy as np
import cv2
from pylepton import Lepton


getDataCommand = 10
getDataCommand1 = 0
getKnobCommand = 11
temperatureMessage = 12
uvMessage = 13
terminator = 254

runTime = timedelta(seconds = 20)
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
    f = open(startTime + ".txt", 'w')    

    #LOOP UNTIL THE PROGRAM HAS RUN FOR A NUMBER OF HOUR
    while ((datetime.now() - startTimeRaw) < runTime):
        timeToday = str(datetime.now())


        position = setServoPosition()     
        readData = grabData()

        with Lepton() as l:
            a,_ = l.capture()
            
        cv2.normalize(a,a,0,65535, cv2.NORM_MINMAX) #extends contrast
        np.right_shift(a,8,a) #fit data into 8 bits
        cv2.imwrite(timeToday+'.jpg', np.uint8(a)) #write to file


        #convert floats to strings for writing to file
        tempSTR = str(readData[0])
        uvSTR = str(readData[1])

        #write the data to file
        f.write(timeToday + " , ")
        f.write('Temp: ' + tempSTR + ', UV: '+ uvSTR +', Knob: '+ str(ord(position)))
        f.write('\r\n')
        time.sleep(1)

    print ('Ending program')
    f.close()

def grabData ():
    print('Grab data command ')
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
        print('Temperature = ', temperature)
        temperature = ((5.0/1023.0) * temperature)
        temperature = ((temperature * 100) - 273)
        temperature = round(temperature, 3)
        print('Temperature = ', temperature)    

    if (data[3] == 'u'):
        uv = (float)((ord(data[4]) << 8) | ord(data[5]))
        print('UV = ', uv)

    returnData = [temperature, uv]
    return returnData


def sendDataGrabCommand ():
    #65, 66 is the command to grab data
    #python3
    #ser.write(bytes("AB", "utf-8"))
    ser.write(bytes("AB"))


def setServoPosition ():
    #chr function turns it into the ascii value
    position = chr(random.randrange(1,180))
    ser.write("C"+position)
    return position
	


if __name__ == "__main__": main()
