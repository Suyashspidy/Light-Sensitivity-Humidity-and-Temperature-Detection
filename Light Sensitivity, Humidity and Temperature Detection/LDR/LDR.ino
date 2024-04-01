void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  
  //int light=analogRead(A0);
  //Serial.println(light);
  int black=digitalRead(2);
  Serial.println(black);
  if(black==0)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
  delay(1000);
}
