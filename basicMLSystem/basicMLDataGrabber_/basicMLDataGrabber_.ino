#include <Wire.h>
#include "Adafruit_VEML6070.h"
#include <Servo.h>
#include <VarSpeedServo.h>


//objects
Adafruit_VEML6070 uv = Adafruit_VEML6070();
Servo servo;

//pins
int temperPin = A0;
int servoPin = 9;

//global variables
int temperature = 0;
int uvLevel = 0;
byte message[2] = {0,0};
char terminator = 90;  //Z
int messageSize = 0;
const int getDataCommand = 65; //A
const int getDataCommand1 = 66;//B
const int setKnobCommand = 67; //C
const int temperatureMessage = 116;//s
const int uvMessage = 117; //u
const int outMessageLength = 6;

//functions
int getTemperature(void);
void setKnob(byte position);
void sendData(int temp, int uv);



void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    //Serial.println("Arduino starting up, getting ready to transmit data");
    
    uv.begin(VEML6070_1_T); // pass in the integration time constant
    
    servo.attach(servoPin); //analog pin 1

    if (servo.attached() == true)
    {
        //Serial.println("Servo ready");
    }
    //Serial.println("Ready");
}

void loop() {
    // put your main code here, to run repeatedly:
    while (Serial.available() == 0)
        ;
    
    messageSize = Serial.readBytesUntil(terminator, message, 2);

    if(message[0] == getDataCommand)
    {
        //Serial.println("Get data command recieved");
        //get 16 bit UV level reading
        uvLevel = uv.readUV();
        //Serial.println(uvLevel);
        temperature = getTemperature();     
        //Serial.println(temperature);
        sendData(temperature, uvLevel);
    }
    else if (message[0] == setKnobCommand)
    {
        //Serial.println("Set knob command recieved");
        byte setKnobPosition = message[1];
        //Serial.println(setKnobPosition);
        setKnob(setKnobPosition);
    }
}

void sendData(int temp, int uv)
{
        byte outMessage[6] = {0,0,0,0};
        //(send temperature value MSB first)
        outMessage[0] = temperatureMessage;
        outMessage[1] = (byte)((temp >> 8) & 0xFF);
        //Serial.println(outMessage[1]);
        outMessage[2] = (byte) (temp & 0xFF);
        //Serial.println(outMessage[2]);
        
        //send UV value MSB first)
        outMessage[3] = uvMessage;
        outMessage[4] = (byte)((uv >> 8) & 0xFF);
        outMessage[5] = (byte)(uv & 0xFF);
        Serial.write(outMessage, outMessageLength);
}
int getTemperature(void)
{
    int data = 0;
    data = analogRead(temperPin);
    return data;
}

void setKnob(byte position)
{
    servo.write(position);
}




