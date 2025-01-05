const int joystickX = A1;
const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT); 
  pinMode(joystickX, INPUT);
}

void loop() {
  int xValue = analogRead(joystickX);
  int brightness = map(xValue, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
}