#include <Arduino.h>

#define DEBUG
#define PWM_OUT 3

void setupHardware();

int delaySpeed = 300;
int maxSpeed = 100;
bool ledState = true;
int pos = 0; 

#ifdef DEBUG
#define DEBUG_PRINT(x)  Serial.print (x)
#define DEBUG_PRINTLN(x)  Serial.println (x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#endif
