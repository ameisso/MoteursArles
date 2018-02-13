#include "main.h"


void setup()
{
  setupHardware();
  Serial.begin(115200);
}


void loop()
{
  char speed = getSerialSpeed();
  if(speed >= 0)
  {
    DEBUG_PRINT("SPEED: ");
    DEBUG_PRINTLN_CAST (speed,DEC);
    analogWrite(PWM_OUT,speed);
    delay(delaySpeed);
    DEBUG_PRINTLN(getCoderTurns());
    digitalWrite(LED_BUILTIN,ledState);
    ledState = ! ledState;
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
  return coder.read()/CODER_RESOLUTION/4.0;
}

int getSerialSpeed()
{
  if (Serial.available() > 0)
  {
    int incomingByte = 0;
    incomingByte = Serial.read();
    if (incomingByte != 97)
    {
      incomingByte  = map(incomingByte, 97, 122, MIN_SPEED, 255);
    }
    else
    {
      incomingByte = 0;
    }
    DEBUG_PRINT("I received: ");
    DEBUG_PRINTLN_CAST (incomingByte,DEC);
    return incomingByte;
  }
  return -1;
}
