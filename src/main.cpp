#include "main.h"


void setup()
{
  setupHardware();
  Serial.begin(115200);
  while(! Serial)
  {
    digitalWrite(LED_BUILTIN,ledState);
    ledState = ! ledState;
    delay(500);
  }
  DEBUG_PRINTLN("INIT_OK");
}


void loop()
{
  printStatus();
  int speed = getSerialSpeed();
  if(speed >= 0)
  {
    DEBUG_PRINT("SPEED: ");
    DEBUG_PRINTLN_CAST (speed,DEC);
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
  return getCoderTurns()*CODER_CIRCUM_MM/1000.0;
}

float getCoderAngle()
{
  return coder.read()/CODER_RESOLUTION/4.0*360.0;
}

void setOrigin()
{
  coder.write(0);
}

void printStatus()
{
  if(millis()-lastPrint > PRINT_INTERVAL_MS)
  {
    lastPrint = millis();
    DEBUG_PRINT("VALUE: ");
    DEBUG_PRINT(coder.read()/4.0);
    // DEBUG_PRINT("CODER: ");
    // DEBUG_PRINT(getCoderTurns());
    DEBUG_PRINT(" ANGLE: ");
    DEBUG_PRINT(getCoderAngle());
    DEBUG_PRINT(" DISTANCE: ");
    DEBUG_PRINTLN(getCoderDistance());

  }
}
