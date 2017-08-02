#include <Wire.h>
#include "Adafruit_VEML6070.h"
#include <Stepper.h>

#define STEPS_PER_MOTOR_REVOLUTION 32   
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048  

//objects
Adafruit_VEML6070 uv = Adafruit_VEML6070();

Stepper smallStepper(STEPS_PER_MOTOR_REVOLUTION, 8, 10, 9, 11);


//pins
int temperPin = A0;
int servoPin = 9;

//global variables
int temperature = 0;
int uvLevel = 0;
byte message[2] = {0,0};
char terminator = 90;  //Z
int messageSize = 0;
int oldPosition = 0;
const int getDataCommand = 65; //A
const int getDataCommand1 = 66;//B
const int setKnobCommand = 67; //C
const int initialiseCommand = 68;
const int temperatureMessage = 116;//s
const int uvMessage = 117; //u
const int outMessageLength = 6;

//functions
int getTemperature(void);
void setKnob(int newPosition);
void sendData(int temp, int uv);

int Steps2Take;


void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);    
    uv.begin(VEML6070_1_T); // pass in the integration time constant
    smallStepper.setSpeed(1024);    
}

void loop() {
    // put your main code here, to run repeatedly:
    while (Serial.available() == 0)
        ;
        
    messageSize = Serial.readBytesUntil(terminator, message, 3);

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
        //int setKnobPosition1 = message[1];
        //int setKnobPosition2 = message[2];
        int setKnobPosition = (message[1] | (message[2] << 8));
        //Serial.println(setKnobPosition);
        setKnob(setKnobPosition);
    }
    else if (message[0] == initialiseCommand)
    {
        smallStepper.step(8000);
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

void setKnob(int newPosition)
{
    //a rough approximation of 'degrees' here
    //negative steps = clockwise rotation
    int moveSteps = ((oldPosition - newPosition) * 6);
    smallStepper.step(moveSteps);
    oldPosition = newPosition;    
}




