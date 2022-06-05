#include "Globals.h"

void lowerSpeed(){
     int previousMillis = millis();
     int timer = 0;
     if(velocity == 4){
     velocity = 1;               //// Lower the speed
     while(timer < 4000){
        long currentMillis = millis();
        timer = currentMillis - previousMillis;
      }
     }
     if(velocity == 3){
     velocity = 1;               //// Lower the speed
     while(timer < 3000){
        long currentMillis = millis();
        timer = currentMillis - previousMillis;
      }
     }
     if(velocity == 2){
     velocity = 1;               //// Lower the speed
     while(timer < 2000){
        long currentMillis = millis();
        timer = currentMillis - previousMillis;
      }
     }
     if(velocity == 1){
     return;
     }
  }
  
void changeRotation(){
  if(isr2Time > isr1Time){
    if(isr2Time - isr1Time > isr1Time - isr2OldTime){
      // left, up
      rotationRight = true;
      } else {
      // rotationRight, down
      rotationRight = false;
      }
    }
    else{
      if(isr1Time - isr2Time > isr2Time - isr1OldTime){
        // rotationRight, down
        rotationRight = false;
        } else {
        // left, up
        rotationRight = true;
        }
    }
    lowerSpeed();
    toStop = true;
}
