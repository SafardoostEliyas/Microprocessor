
# روشن و خاموش کردن LED با دکمه فشاری

## شرح مختصر پروژه
در این پروژه ما با استفاده از دکمه فشاری و برد Arduino یک LED را کنترل میکنیم. تحت تاثیر فشار دکمه لامپ LED روشن و خاموش میشود.
## لوازم مورد نیاز
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- لامپ LED
- کلید فشاری چهار پایه (Pushbutton)
- سیم‌های رابط

 ![push](https://github.com/user-attachments/assets/0949230e-33c3-492a-9cac-c7ac6c83e36a)

## کد پروژه
```cpp
const int led = 13;  // LED پایه
const int pushbtn = 2;  // پایه دکمه فشاری
int pinstate = 0;  // ذخیره وضعیت دکمه

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pushbtn, INPUT);
}

void loop() {
  digitalWrite(led, LOW);  // خاموشی پیش فرض لامپ
  pinstate = digitalRead(pushbtn);  // خواندن وضعیت دکمه
  
  // بررسی آزادی یا فشردن دکمه
  if (pinstate == HIGH) {
    digitalWrite(led, HIGH);  // روشن شدن لامپ با فشردن دکمه
    delay(500);  // ms تاخیر روشن ماندن به
  } else {
    digitalWrite(led, LOW);  // خاموشی لامپ با آزاد بودن دکمه
  }
}