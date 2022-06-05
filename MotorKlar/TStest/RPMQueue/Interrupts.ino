#include "Globals.h"

void isr1(){ //increments revolutions
  // add timestamp to queue
 long timeQueue = millis();
 long limit = timeQueue - updateTimer;
 if(limit < 0)
  limit = 0;
 enqueueAndUpdate(rpmQueue, timeQueue, limit);
 isr1OldTime = isr1Time;
 isr1Time = millis();
 halfRev++;
 if(toStop = true){
  stopCoils = true;
  toStop = false;
  }
}

void isr2(){ //increments revolutions
 isr2OldTime = isr2Time;
 isr2Time = millis();
}
