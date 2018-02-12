#include "main.h"

void setup()
 {
  //setupHardware();
  Serial.begin(115200);
  DEBUG_PRINTLN("INIT OK ");
}
void loop() {
  for (int pos = 0; pos <= maxSpeed; pos += 1)
  {
    analogWrite(PWM_OUT,pos);
    delay(delaySpeed);
    digitalWrite(LED_BUILTIN,ledState);
    ledState = ! ledState;
    DEBUG_PRINTLN(pos);
  }
}

void setupHardware()
{
  pinMode(PWM_OUT,OUTPUT);
}
