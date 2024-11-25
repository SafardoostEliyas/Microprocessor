```cpp

#include <Wire.h>

#define SLAVE_ADDRESS 8
int potPin = A0;
int ledPin = 9;

void setup() {
  Wire.begin();
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin) / 4;
  analogWrite(ledPin, potValue);

  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(potValue);
  Wire.endTransmission();
  delay(100);
  
  Wire.requestFrom(SLAVE_ADDRESS, 1);
  if (Wire.available()) {
    int slaveValue = Wire.read();
    analogWrite(ledPin, slaveValue);
  }
}

```

### کد تنظیم روشنایی برای Slave:
```cpp

#include <Wire.h>

int potPin = A0;
int ledPin = 9;
int receivedValue = 0;

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin) / 4;
  analogWrite(ledPin, receivedValue);
  delay(100);
}

void receiveEvent(int howMany) {
  if (Wire.available()) {
    receivedValue = Wire.read();
  }
}

void requestEvent() {
  int potValue = analogRead(potPin) / 4;
  Wire.write(potValue);
}

```