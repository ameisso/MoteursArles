#include <Arduino.h>
#include <Encoder.h>

#define DEBUG
#define PWM_OUT 3
#define CODER_A 2
#define CODER_B 4
#define CODER_RESOLUTION 600


void setupHardware();
float getCoderTurns();
Encoder coder(CODER_A, CODER_B);
int delaySpeed = 300;
bool ledState = true;

#ifdef DEBUG
#define DEBUG_PRINT(x)  Serial.print (x)
#define DEBUG_PRINTLN(x)  Serial.println (x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#endif
