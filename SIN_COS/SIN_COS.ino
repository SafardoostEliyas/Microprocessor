
void setup() {
Serial.begin(9600);
}

void loop() {
  digitalWrite(led, LOW);
  pinSate = digitalRead(pushbtn);
  if (float i = 0; i< 360.00; i = i+2) {
    Serial.print(sin(i* PI /180.00));
    Serial.print(" ");
    Serial.println(cos(i* PI /180.00));
  } 
}