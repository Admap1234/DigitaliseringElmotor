#include "Globals.h"

void speedMenu(){
  while(true){
    int timer = 0;
    long previousMillis = millis();
    while(timer < 2000){
      coils();
      
      long currentMillis = millis();
      timer = currentMillis - previousMillis;
      int x = analogRead(0);    // have to update the value or else it will be the same value before I update

      if(x < 200 && x >= 60)
      {
        if(velocity < 4)
          velocity = velocity + 1;
      }
      if(x < 600 && x >= 400)
      {
        if(velocity > 1)
          velocity = velocity -1;
      }
      if(x >= 600 && x < 800){
        lcd.clear();
        delay(1000);    // need to have an delay or else the program will go into the other menys
        return;
      }
    }
    noInterrupts();
    timeIs = millis() - updateTimer; // how much time have gone by
    if(timeIs < 0)
      timeIs = 0;
    rpm = getLastEntries(rpmQueue, timeIs)/2;
    
    lamp();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.write(byte(0));
    lcd.print(" Higher");
    lcd.setCursor(0,1);
    lcd.write(byte(1));
    lcd.print(" Lower");
    lcd.setCursor(10,0);
    lcd.print("RPM");
    lcd.setCursor(10,1);
    lcd.print(rpm);
    interrupts();
  }
}
