const int led = 13;
const int pushbtn = 2;
int pinstate = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(pushbtn, INPUT);
}

void loop() {
  digitalWrite(led, LOW);
  pinstate = digitalRead(pushbtn);
  if (pinstate == HIGH)
  {digitalWrite(led, HIGH);
  delay(500);
  }
  else {
    digitalWrite(led, LOW);
  }

}