#!/usr/bin/env python

#Vaisala wxt520 
#Command format in ASCII:
#
# 		aXU<cr><lf>
#where:
#	a = Device address, 0..9 a..z A..Z
#	XU = Device settings command
#	<cr><lf> = Command terminator
#
#Example response:
#
# aXU,A=a,M=[M],T=[T],C=[C],I=[I],B=[B],D=[D],P=[P],S=[S],L=[L],N=[N],V=[V]<cr><lf>
# http://www.vaisala.com/Vaisala%20Documents/User%20Guides%20and%20Quick%20Ref%20Guides/M210906EN-C.pdf

"""
a = device address
XU = device settings command in ASCII
[A] = Address: 0 (default)
[M] = Communication protocol
[T] = Test parameter (not used)
[C] = Serial interface
[I] = Automatic repeat interfac for composite data message
[B] = Baud rate
[D] = Data bits
[P] = Parity
[S] = Stop bits
[L] = RS485 Line Delay
[N] = Name of the device
[V] = Software version

"""


import serial
import time
from datetime import datetime

#Define commands
DEVICE_RESET 				= "XZ"
PRECIPITATION_COUNTER_RESET 		= "XZRU"
PRECIPITATION_INTENSITY_RESET		= "XZRI"
MEASUREMENT_RESET 			= "XZM"
WIND_DATA_MESSAGE 			= "R1"
PRESSURE_TEMP_HUMIDITY_DATA_MESSAGE 	= "R2"
PRECIPITATION_DATA_MESSAGE		= "R3"


address = '0'

ser = serial.Serial(
	port='/dev/ttyUSB0',
	baudrate=19200,
	parity=serial.PARITY_NONE,
	stopbits=serial.STOPBITS_ONE,
	bytesize=serial.EIGHTBITS,
	timeout=1
)

def main():
	#default address of the vaisala weather station
	x = 0

	startTime = str(datetime.now())
	
	if ser.isOpen() != True:
		ser.open()
#	ser.isOpen()
	print 'Enter your commands below. \r\nInsert "exit" to leave the application'
	f = open(startTime + ".txt", 'w')

	while x < 100:
		timeToday = str(datetime.now())
		data = ''
		
		while ser.inWaiting() == 0:
			None

		while (ser.inWaiting() > 0):
			data += ser.read(1)
	
		f.write(timeToday + " , ")
		f.write(data)
		x = x + 1
	
	print 'Ending program'
	f.close()




def getWeatherStationSettings(address):
	"Function to get current state of settings"
	
	ser.write(address+"XU\r\n")	
	response = ser.read(40)
	print response
	return None


def configWeatherStation (address):
	"Function to configure the station at the start of operation"

	#First write the Serial interface: 1 = SDI-12, 2 = RS-232, 3= RS-485, 4 = RS-422
	address = "0"
	commsInterface = "C=2"
	message = address + "XU," + commsInterface + "\r\n" 
	ser.write(message)
	#wait for message to be accepted or whatever
	time.sleep(1)

	#address 0, protocol ascii polled, interface rs232, no automatic repeat interval
	#baud 19200, 8 data bits, no parity, 1 stop bit, no rs485 line delay
	message1 = "0XU,A=0,M=P,C=2,I=0\r\n"
	message2 = "0xU,B=19200,D=8,P=N,S=1,L=0\r\n"

	ser.write(message1)
	time.sleep(1)
	ser.write(message2)
	time.sleep(1)

	getWeatherStationSettings("0")

	return None

def getWeatherInfo(address, deviceSettingsCommand):
	"Function to retrieve the data from the Vaisala WXT520 Weather Station"
	#concatenate the message together
	message = "0" + deviceSettingsCommand + "\r\n" 
	ser.write(message)
	return None

if __name__ == "__main__": main()



