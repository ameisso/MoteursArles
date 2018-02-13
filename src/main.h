#include <Arduino.h>
#include <Encoder.h>
#include <PID.h>

#define DEBUG
#define PWM_OUT 3
#define CODER_A 2
#define CODER_B 4
#define MIN_SPEED 81
#define PRINT_INTERVAL_MS 500
float CODER_RESOLUTION = 600.0;
float CODER_DIAMETER = 40.5;
float CODER_CIRCUM_MM = 131.0;
long lastPrint = 0;

void setupHardware();
float getCoderTurns();
float getCoderDistance();
float getCoderAngle();
int getSerialSpeed();
void setOrigin();
void printStatus();
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
