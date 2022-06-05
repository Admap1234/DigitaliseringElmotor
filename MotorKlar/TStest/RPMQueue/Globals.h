#ifndef GLOBALS
#define GLOBALS
#include<LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // (rs(8), enable(9), databus(4,5,6,7)) KOLLA VILKEN PIN

int LED = 12;                        // LED is connected to pin 12
int coil1 = 13, coil2 = 11;          // coils connected to pins 11 and 13
int IRSensor1 = 2, IRSensor2 = 3;    // connect ir sensor to arduino pin 2 and 3

int halfRev = 0;                     // Number of revolutions completed
long timeIs = 0;                     // Current time in milliseconds
double rpm = 0;                      // Revs per minute
Queue* rpmQueue = createQueue(400);  // Create a queue with room for 400 timestamps
long updateTimer = 60000;            // Update-timer for rpmQueue
int velocity = 1;                    // Speed of the engine 
boolean toStop = false;              // Used to stop the coils when next passing over the sensors
boolean stopCoils = false;           // Stopping the coils

long isr1Time = 0;                   // Latest time for IR sensor 1
long isr1OldTime = 0;                // Previous time for IR sensor 1
long isr2Time = 0;                   // Latest time for IR sensor 2
long isr2OldTime = 0;                // Previous time for IR sensor 2
boolean rotationRight;               // Used to indicate whether rotation direction is to the right



#endif
