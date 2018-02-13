#include <Arduino.h>
#include <Encoder.h>

#define DEBUG
#define PWM_OUT 3
#define CODER_A 2
#define CODER_B 4
#define CODER_RESOLUTION 600
#define MIN_SPEED 81


int delaySpeed = 2000;

void setupHardware();
float getCoderTurns();
int getSerialSpeed();
Encoder coder(CODER_A, CODER_B);

bool ledState = true;

#ifdef DEBUG
#define DEBUG_PRINT(x)  Serial.print (x)
#define DEBUG_PRINTLN(x)  Serial.println (x)
#define DEBUG_PRINTLN_CAST(x,y)  Serial.println (x,y)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#define DEBUG_PRINTLN_CAST(x,y)
#endif
