
### کد ارسال و دریافت دستورات برای Master:

```cpp
#include <Wire.h>
#define SLAVE_ADDRESS 8
#define MASTER_LED_PIN 13
String receivedCommand = "";
String inputCommand = "";

void setup() {
  Wire.begin();
  pinMode(MASTER_LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    inputCommand = Serial.readStringUntil('\n');
    inputCommand.trim();
    Wire.beginTransmission(SLAVE_ADDRESS);
    Wire.write(inputCommand.c_str());
    Wire.endTransmission();
    Serial.println("Sent to Slave: " + inputCommand);
  }

  Wire.requestFrom(SLAVE_ADDRESS, 32);
  if (Wire.available()) {
    receivedCommand = "";
    while (Wire.available()) {
      char c = Wire.read();
      receivedCommand += c;
    }
    receivedCommand.trim();
    Serial.println("Received from Slave: " + receivedCommand);
    if (receivedCommand == "on") {
      digitalWrite(MASTER_LED_PIN, HIGH);
    } else if (receivedCommand == "off") {
      digitalWrite(MASTER_LED_PIN, LOW);
    }
  }
  delay(200);
}
```
### کد ارسال و دریافت دستورات برای Slave:
```cpp
#include <Wire.h>
#define SLAVE_ADDRESS 8
#define SLAVE_LED_PIN 13
String receivedCommand = "";

void setup() {
  Wire.begin(SLAVE_ADDRESS);
  pinMode(SLAVE_LED_PIN, OUTPUT);
  Wire.onReceive(receiveData);
}

void loop() {
}

void receiveData(int byteCount) {
  receivedCommand = "";
  while (Wire.available()) {
    char c = Wire.read();
    receivedCommand += c;
  }
  if (receivedCommand == "on") {
    digitalWrite(SLAVE_LED_PIN, HIGH);
  } else if (receivedCommand == "off") {
    digitalWrite(SLAVE_LED_PIN, LOW);
  }
}
```