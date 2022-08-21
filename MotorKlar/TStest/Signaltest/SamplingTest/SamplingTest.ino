long count = 0;
long freq = 0;
long rpm = 0;
long previousMillis = 0;
long currentMillis = 0;

void isr(){
  count++;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), isr, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  previousMillis = millis();
  long timer = 0;
  while(timer < 20000){
    currentMillis = millis();
    timer = currentMillis - previousMillis;
  }
  freq = count/(timer/1000);
  Serial.print("Count is ");
  Serial.println(count);
  Serial.print("Timer is ");
  Serial.println(timer);
  count = 0;
  Serial.print("Current frequency is ");
  Serial.print(freq);
  Serial.println(" Hz");
  rpm = freq/60;
  Serial.print("Current rpm is ");
  Serial.println(rpm);
}
