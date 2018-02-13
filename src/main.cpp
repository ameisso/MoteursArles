#include "main.h"


void setup()
{
  setupHardware();
  Serial.begin(115200);
}


void loop()
{
  int speed = getSerialSpeed();
  if(speed >= 0)
  {
    DEBUG_PRINT("SPEED: ");
    DEBUG_PRINTLN_CAST (speed,DEC);
    DEBUG_PRINT("CODER: ");
    DEBUG_PRINTLN(getCoderDistance());
    analogWrite(PWM_OUT,speed);
  }
}

void setupHardware()
{
  pinMode(PWM_OUT,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  analogWrite(PWM_OUT,0);
  coder.write(0);
}

float getCoderTurns()
{
  return float(coder.read())/CODER_RESOLUTION/4.0;
}

int getSerialSpeed()
{
  if (Serial.available() > 0)
  {
    int incomingByte = 0;
    incomingByte = Serial.read();

    if(incomingByte == 9 )//TAB
    {
      DEBUG_PRINTLN("SET ORIGIN");
      setOrigin();
    }
    if (incomingByte != 97)
    {
      incomingByte  = map(incomingByte, 97, 122, MIN_SPEED, 255);
    }
    else
    {
      incomingByte = 0;
    }

    return incomingByte;
  }
  return -1;
}

float getCoderDistance()
{
  return getCoderTurns()*CODER_DIAMETER*PI/1000.0;
}

void setOrigin()
{
  coder.write(0);
}
