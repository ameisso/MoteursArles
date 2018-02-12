#include "main.h"


void setup()
{
  setupHardware();
  Serial.begin(115200);

}


void loop()
{
  for (pos = 0; pos <= 180; pos += 1)
  {
    analogWrite(PWM_OUT,pos);
    DEBUG_PRINTLN(pos);
    delay(delaySpeed);
    digitalWrite(LED_BUILTIN,ledState);
    ledState = ! ledState;
  }
  for (pos = 180; pos >= 0; pos -= 1)
  {
    analogWrite(PWM_OUT,pos);
    DEBUG_PRINTLN(pos);
    delay(delaySpeed);
    digitalWrite(LED_BUILTIN,ledState);
    ledState = ! ledState;
  }
}

void setupHardware()
{
  pinMode(PWM_OUT,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}
