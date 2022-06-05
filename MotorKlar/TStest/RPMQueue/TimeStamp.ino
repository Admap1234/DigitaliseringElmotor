#include "Globals.h"

void lamp(){
  int statusSensor = digitalRead(IRSensor1);
  if(statusSensor == 0)
  {
    statusSensor = digitalRead(IRSensor2);
  }
    if(statusSensor == 1){
      digitalWrite(LED, HIGH);  //LED LOW, lamp turns on
    }
  else{
    digitalWrite(LED, LOW);
  }
}

void rpmCalc() {
  while(true){
    int timer = 0;
    long previousMillis = millis();
  while(timer < 2000){
    coils();
    long currentMillis = millis();
    timer = currentMillis - previousMillis;
    int x = analogRead(0);    // have to update the value or else it will be the same value before I update
    
    if(x >= 600 && x < 800){
      lcd.clear();
      delay(1000);    // need to have an delay or else the program will go into the other menys
      return;
    }
  }
  noInterrupts(); // disables the interrupts
  timeIs = millis() - updateTimer; // how much time have gone
  if(timeIs < 0)
    timeIs = 0;
  rpm = getLastEntries(rpmQueue, timeIs)/2;
  
  lamp();
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("RPM");
  lcd.setCursor(4,1);
  lcd.print(rpm);
  interrupts(); // enable the interrupts
}
}
