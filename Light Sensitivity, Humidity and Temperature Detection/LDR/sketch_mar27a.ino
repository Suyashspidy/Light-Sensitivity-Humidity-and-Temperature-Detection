const int ledPin = 13;

const int ldrPin = 0;

void setup() {

Serial.begin(9600);

pinMode(ledPin, OUTPUT);

}

void loop() {

//int ldrStatus = digitalRead(ldrPin);

Serial.println(digitalRead(ldrPin));

if (ldrStatus ==1) {

digitalWrite(ledPin, HIGH);

Serial.println("LDR is DARK, LED is ON");

}

else {

digitalWrite(ledPin, LOW);

Serial.println("LDR is BRIGHT,LED is OFF");

}

}
