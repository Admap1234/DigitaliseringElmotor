#include "Globals.h"
#include "Symbols.h"

void setup(){
  pinMode (coil1, OUTPUT);
  pinMode (coil2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(IRSensor1), isr1, RISING); //attachInterrupt(what pin to interrupt, what function, what mode)
  attachInterrupt(digitalPinToInterrupt(IRSensor2), isr2, RISING); //attachInterrupt(what pin to interrupt, what function, what mode)
  pinMode (LED, OUTPUT);  //Led pin OUTPUT
  lcd.createChar(0,upArrow);
  lcd.createChar(1,downArrow);
  lcd.createChar(2,leftArrow);
  lcd.createChar(3,rightArrow);
  lcd.begin(16, 2);   //set the dimensions of the screen(cols,rows);
}

void loop(){
  coils();
  lamp();
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.print(" RPM");
  lcd.setCursor(8,0);
  lcd.write(byte(1));
  lcd.print(" Speed");
  lcd.setCursor(0,1);
  lcd.write(byte(2));
  lcd.print(" Rotate");
  int x;
 x = analogRead (0);    //turn on up,down,left,right.
 lcd.setCursor(10,1);
 if (x < 60) {
   //lcd.print ("Right ");
 }
 else if (x < 200) {
   //lcd.print ("Up    ");
   lcd.clear();
   rpmCalc();
 }
 else if (x < 400){
   //lcd.print ("Down  ");
   lcd.clear();
   speedMenu();
 }
 else if (x < 600){
   //lcd.print ("Left  ");
   changeRotation();
 }
 else if (x < 800){
   //lcd.print ("Select");
 }
}
