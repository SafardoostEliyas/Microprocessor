
# کنترل LED با دستورات حروف در Serial Monitor

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و برد Arduino یک LED را کنترل میکنیم. با ارسال حرف 'L' لامپ خاموش و با ارسال حرف 'H' لامپ روشن میشود.

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
    if (value == 'H') {
      digitalWrite(ledpin, HIGH);
    } else if (value == 'L') {
      digitalWrite(ledpin, LOW);
    }
  }
}
```

## طرز کار:
با بستن مدار نوشتن برنامه و آپلود آن روی مدار شما میتوانید با نوشتن 'H' لامپ را روشن و با نوشتن 'L' لامپ را خاموش کنید.

## تصاویر:
![images](https://github.com/user-attachments/assets/4ad6c932-8026-4d4b-9644-78524004332b)

![pick](https://github.com/user-attachments/assets/7bb7637b-6d6e-438b-8cfd-43faead49f52)



## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه کنترل یک LED را با استفاده از ارسال حروف خاص 'L' و 'H' بدست بگیریم. همچنین انجام این دستورات از طریق Serial Monitor در Arduino انجام شده است.