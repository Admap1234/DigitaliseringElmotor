int state = 0;

void isrR(){
  if(state != 1){
    state = 1;
    digitalWrite(4, HIGH);
  }
}

void isrF(){
  if(state != 0){
    state = 0;
    digitalWrite(4, LOW);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), isrR, RISING);
  attachInterrupt(digitalPinToInterrupt(2), isrF, FALLING);
  pinMode (4, OUTPUT);  //Probe pin OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
  while (true){
    
  }
  
}
