
# کنترل LED با حروف کوچک و بزرگ در Serial Monitor

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و برد Arduino یک LED را کنترل میکنیم. با ارسال هریک از حروف 'l , L' لامپ خاموش و با ارسال هریک از حروف 'h , H' لامپ روشن میشود.

## لوازم مورد نیاز:
- برد Arduino Uno
- نرم‌افزار Arduino IDE
- لامپ LED
- سیم‌های رابط
- مقاومت 220 اهم

## طریقه انجام آزمایش (اتصالات):
- پایه منفی LED به مقاومت 220 اهم و سپس به GND همچنین پایه مثبت LED به پین 12 بر روی برد Arduino متصل می‌شود.

## کد پروژه:

```cpp
const int ledpin = 12;

void setup() {
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char value = Serial.read();
    if (value == 'L' || value == 'l') {
      digitalWrite(ledpin, HIGH);
    } else if (value == 'H' || value == 'h') {
      digitalWrite(ledpin, LOW);
    }
  }
}
```
## تصاویر:

![pick](https://github.com/user-attachments/assets/87930665-dff9-4504-bcec-41369fa5a3fa)

![images](https://github.com/user-attachments/assets/f4067d81-a754-40e9-8c0e-35e750d0024e)

## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه کنترل یک LED را با استفاده از حروف خاص 'l,L' و 'h,H' بدست بگیریم. همچنین انجام این دستورات از طریق Serial Monitor در Arduino انجام شده است.
