#include "main.h"


void setup()
{
  setupHardware();
  Serial.begin(115200);
}


void loop()
{
  analogWrite(PWM_OUT,0);
  DEBUG_PRINTLN(getCoderTurns());
  delay(delaySpeed);
  digitalWrite(LED_BUILTIN,ledState);
  ledState = ! ledState;
}

void setupHardware()
{
  pinMode(PWM_OUT,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  coder.write(0);
}

float getCoderTurns()
{
  return coder.read()/CODER_RESOLUTION/4.0;
}
