#include <Arduino.h>
#include <Encoder.h>

#define DEBUG
#define PWM_OUT 3
#define CODER_A 2
#define CODER_B 4
#define CODER_RESOLUTION 600.0
#define MIN_SPEED 81
#define CODER_DIAMETER 40.5


int delaySpeed = 2000;

void setupHardware();
float getCoderTurns();
float getCoderDistance();
int getSerialSpeed();
void setOrigin();
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
