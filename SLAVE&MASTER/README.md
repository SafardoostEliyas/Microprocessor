
# اتصال دو برد آردوینو به یکدیگر از طریق رابطه ارباب و برده

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و سیم های رابط میخواهیم بین دو برد آردوینو اتصال ایجاد کرده و دستوراتی را بین آن ها منتقل کنیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- لامپ LED
- مقاومت متغیر (پتانسیومتر)
- سیم رابط
## طریقه انجام آزمایش (اتصالات):
- طبق شمای داده شده دو برد را به یکدیگر متصل کرده و بقیه اتصالات را نیز انجام میدهیم. پس از کد برنامه را نوشته و روی نرم افزار آپلود میکنیم. برای ایجاد رابطه Master-Slave بین دو برد Arduino که هر دو دارای LED و پتانسیومتر هستند، می‌توانید از پروتکل ارتباطی I2C استفاده میکنیم. در این سناریو، Master مقادیر خوانده‌شده از پتانسیومتر خود را به Slave ارسال می‌کند تا روشنایی LED آن را کنترل کند و بالعکس.همچنین یک پروژه دیگر را در قالب روشن و خاموش کردن لامپ یکدیگر توسط ارسال دستور در Serial Monitor را نیز در همین پروژه انجام میدهیم.
## تصاویر:
![MasterProj](https://github.com/user-attachments/assets/6cf46a6e-d04d-47c7-8280-a08a71174e84)
![SchemaMaster Slave](https://github.com/user-attachments/assets/93279215-45c1-4d8b-aa97-e89b384e843b)



## کد پروژه:
### کد تنظیم روشنایی برای Master:
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
## طرز کار:
این کدها ارتباط I2C را برقرار کرده و دستورات تنظیم روشنایی یا روشن/خاموش کردن LED را منتقل می‌کند.
## نتیجه‌ پروژه:
1. کنترل از راه دور روشنایی: با استفاده از پتانسیومتر که به یک آردوینو متصل است، می‌توان روشنایی لامپ متصل به آردوینو دیگری را تنظیم کرد. این نشان‌دهنده نحوه تعامل میان دو آردوینو است.
2. برقراری ارتباط دو طرفه: ارتباط میان دو آردوینو باید به گونه‌ای برقرار شود که اطلاعات (مقدار خوانده شده از پتانسیومتر) از آردوینو اول به آردوینو دوم ارسال شود تا روشنایی لامپ تغییر کند.
3. آموزش نحوه استفاده از پتانسیومتر: استفاده از پتانسیومتر برای تنظیم مقادیر آنالوگ و تبدیل آن به فرمان‌های دیجیتال یا PWM برای کنترل لامپ.
4. فهم نحوه تعامل با پروتکل‌های ارتباطی: از جمله ارتباط سریال یا I2C برای ارسال داده‌ها میان دو آردوینو.
همچنین انجام این دستورات از طریق کد نویسی در Arduino انجام شده است.همچنین ارسال دستورات و نمایش نتایج آن بصورت log در Serial Monitor انجام میشود.