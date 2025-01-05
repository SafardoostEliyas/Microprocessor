# کار با صفحه کلید اعداد KEYPAD

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و KEYPAD و برد Arduino میخواهیم با زدن دکمه ها اعداد را به سیستم معرفی کنیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- ماژول مادون قرمز IR
- سیم رابط
- صفحه کلید عددی KEYPAD
- لامپ LED

## طریقه انجام آزمایش (اتصالات):
- کد را در نرم‌افزار Arduino IDE اجرا کرده و KEYPAD را به بورد متصل کرده و پس از آپلود کد ، با زدن دکمه ها نتیجه حاصل از فشردن ان دکمه مشاهده می کنیم.


## تصاویر:

![image](https://github.com/user-attachments/assets/79a4d690-6dae-47d9-922b-4d0420e04c10)
![1000269555](https://github.com/user-attachments/assets/01b0c876-27ba-4474-95c7-182b729c5acb)
![1000269554](https://github.com/user-attachments/assets/76d9a597-cbd6-44bf-b8f2-efc859273f97)






## کد پروژه:
```cpp
#include <Keypad.h>
const byte ROWS = 4; // four rows 
const byte COLS = 4; // four columns

float firstNumber = 0;
float secondNumber = 0;
float result = 0;
bool section = false;
int type = 0;

// Map the buttons to an array for the Keymap instance
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte colPins[ROWS] = {5, 4, 3, 2}; // Pins used for the rows of the keypad
byte rowPins[COLS] = {9, 8, 7, 6}; // Pins used for the columns of the keypad
// Initialise the Keypad
Keypad customKeypad = Keypad(BuildKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);   // Initialise the serial monitor
}

void loop() {
  // Read the pushed button
  int button = int(customKeypad.getKey()) - 48;
  if (0 <= button && button <= 10) {
    Serial.print(button);
    if (section == false) {
      firstNumber = firstNumber * 10 + button;
    } else {
      secondNumber = secondNumber * 10 + button;
    }
  } else {
    switch (button) {
      case 17://A

        section = true;
        type = 1;
        Serial.print('+');
        break;
      case 18://///B

        section = true;
        type = 2;
        Serial.print('-');
        break;
      case 19:////C

        section = true;
        type = 3;
        Serial.print('*');
        break;
      case 20:////D

        section = true;
        type = 4;
        Serial.print('/');
        break;
      case -6:////*

        section = false;
        type = 0;
        Serial.println(' ');
        break;

      case -13://///#
        Serial.print(" = ");
        switch (type) {
          case 1:
            result = (firstNumber + secondNumber);
            break;
          case 2:
            result = (firstNumber - secondNumber);
            break;
          case 3:
            result = (firstNumber * secondNumber);
            break;
          case 4:
            result = (firstNumber / secondNumber);
            break;
        }
        type = 0;
        Serial.println(result);
        firstNumber = 0;
        secondNumber = 0;
        section = false;
        break;

    }
  }
}
```
```cpp
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const String password = "1234";
String input = "";
const int ledPin = 10;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);

    if (key == '#') {
      if (input == password) {
        Serial.println("Password Correct!");
        digitalWrite(ledPin, HIGH);
      } else {
        Serial.println("Wrong Password!");
        digitalWrite(ledPin, LOW);
      }
      input = "";
    } else if (key == '*') {
      input = "";
      Serial.println("Input cleared!");
    } else {
      input += key;
    }
  }
}
```
## طرز کار:
با نصب KEYPAD و آپلود کد میتوانیم یک ماشین حساب ایجاد کرده و با کد دوم میتوانیم احراز هویت کرده و در صورت صحیح بودن لامپ LED روشن می شود و وضعیت آن را در Serial monitor مشاهده کنیم.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه میتوان با استفاده از KEYPAD یک ماشین حساب درست کرده و یا از آن برای احراز هویت استفاده کرد. همچنین انجام این دستورات از طریق کد نویسی در Arduino و مشاهده آن در Serial Monitor انجام شده است.
