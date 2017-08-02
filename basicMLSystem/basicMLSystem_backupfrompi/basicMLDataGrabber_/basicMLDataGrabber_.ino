#include <Wire.h>
#include "Adafruit_VEML6070.h"
#include <Servo.h>

//objects
Adafruit_VEML6070 uv = Adafruit_VEML6070();
Servo servo;

//pins
int temperPin = 3;
int servoPin = 15;

//global variables
int temperature = 0;
int uvLevel = 0;
byte message[2] = {0,0};
char terminator = 254;
int messageSize = 0;
const int getDataCommand = 10;
const int getDataCommand1 = 0;
const int setKnobCommand = 11;
const int temperatureMessage = 12;
const int uvMessage = 13;
const int outMessageLength = 6;

//functions
float getTemperature(void);
void setKnob(int position);
void sendData(int temp, int uv);



void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Arduino starting up, getting ready to transmit data");
    
    uv.begin(VEML6070_1_T); // pass in the integration time constant
    
    servo.attach(servoPin); //analog pin 1
    Serial.begin(19200);
    Serial.println("Ready");
}

void loop() {
    // put your main code here, to run repeatedly:
    while (Serial.available() == 0)
        ;
    
    messageSize = Serial.readBytesUntil(terminator, message, 3);

    if(message[0] = getDataCommand)
    {
        //get 16 bit UV level reading
        uvLevel = uv.readUV();
        temperature = getTemperature();     
        sendData(temperature, uvLevel);
    }
    else if (message[0] = setKnobCommand)
    {
        int setKnobPosition = message[1];
        setKnob(setKnobPosition);
    }
}

void sendData(int temp, int uv)
{
        byte outMessage[6] = {0,0,0,0};
        //(send temperature value MSB first)
        outMessage[0] = temperatureMessage;
        outMessage[1] = (byte)((temp >> 8) & 0xFF);
        outMessage[2] = (byte) (temp & 0xFF);
        //send UV value MSB first)
        outMessage[3] = uvMessage;
        outMessage[4] = (byte)((uv >> 8) & 0xFF);
        outMessage[5] = (byte)(uv & 0xFF);
        Serial.write(outMessage, outMessageLength);
}
float getTemperature(void)
{
    int data = 0;
    data = analogRead(temperPin);
}

void setKnob(int position)
{
    
    servo.write(position);
}




