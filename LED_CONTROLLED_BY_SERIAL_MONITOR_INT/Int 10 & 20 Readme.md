
# کنترل LED با دستورات عددی در Serial Monitor

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و برد Arduino یک LED را کنترل میکنیم. با ارسال عدد 10 LED روشن و با ارسال عدد 20 LED خاموش می‌شود.

## لوازم مورد نیاز:
- برد Arduino Uno
- نرم‌افزار Arduino IDE
- لامپ LED
- سیم‌های رابط
- مقاومت 220 اهم
## طریقه انجام آزمایش (اتصالات):
- پایه منفی LED به مقاومت 220 اهم و سپس به GND همچنین پایه مثبت LED به پین 12 بر روی برد Arduino متصل می‌شود.

## کد برنامه :

```cpp
const int ledpin = 12;

void setup() {
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int value = Serial.parseInt();
    if (value == 10) {
      digitalWrite(ledpin, HIGH);
    } else if (value == 20) {
      digitalWrite(ledpin, LOW);
    }
  }
}
```


## تصاویر:
![images](https://github.com/user-attachments/assets/4ad6c932-8026-4d4b-9644-78524004332b)

![pick](https://github.com/user-attachments/assets/7bb7637b-6d6e-438b-8cfd-43faead49f52)


## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه کنترل یک LED را با استفاده از ارسال اعداد خاص 10 و 20 بدست بگیریم. همچنین انجام این دستورات از طریق Serial Monitor در Arduino انجام شده است.