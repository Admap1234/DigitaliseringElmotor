#include "Globals.h"
int oldHalfRev = 0;
int change = 0;


void coils(){
  if(stopCoils = true){
    long previousMillis = millis();
    long timer = 0;
    while(timer < 3000){
      long currentMillis = millis();
      timer = currentMillis - previousMillis;
    }
    if(rotationRight){
      change = 0;
    } else {
      change = 1;
    }
  }
  if (halfRev == oldHalfRev){
    //do nothing
    }
  else{
    // long avgDiff = averageTimeDiff(rpmQueue); // To be used for constant velocity
    if(change == 0){
      int timer = 0;
      long previousMillis = millis();
      digitalWrite(coil2, HIGH);
      while(timer < 100 * velocity){
        long currentMillis = millis();
        timer = currentMillis - previousMillis;
      }
      digitalWrite(coil2, LOW);
      change = 1;
      oldHalfRev = halfRev;
    }
    else if(change == 1){
      int timer = 0;
      long previousMillis = millis();
      digitalWrite(coil1, HIGH);
      while(timer < 100 * velocity){
        long currentMillis = millis();
        timer = currentMillis - previousMillis;
      }
      digitalWrite(coil1, LOW);
      change = 0;
      oldHalfRev = halfRev;
    }
  }
}
