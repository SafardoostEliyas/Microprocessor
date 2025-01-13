
# کنترل LED با دستورات رشته ای در Serial Monitor

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و برد Arduino یک LED را کنترل میکنیم. با ارسال رشته "ROSHAN" با LED , Serial Monitor روشن و با ارسال رشته "LED "KHAMOOSH میشود.

## لوازم مورد نیاز:
-  برد Arduino Uno
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
    String value = Serial.readString();

    if (value == "ROSHAN") {
      digitalWrite(ledpin, HIGH);
    } else if (value == "KHAMOOSH") {
      digitalWrite(ledpin, LOW);
    }
  }
}
```

## طرز کار:
با آپلود کردن برنامه می‌توان با تایپ کلمات "ROSHAN" و "KHAMOOSH" در Serial Monitor و ارسال آن ها با رشته "ROSHAN" لامپ روشن و با رشته "KHAMOOSH" لامپ خاموش میشود.

## تصاویر:
![تصویر مدار]![pick](https://github.com/user-attachments/assets/025f8c2d-b4fa-4cd5-bf7d-7a031ebbd0da)


![images](https://github.com/user-attachments/assets/15213bd1-2b2e-42bf-beb9-d76b6cda25ad)

## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه کنترل یک LED را با استفاده از رشته های خاص بدست بگیریم. همچنین انجام این دستورات از طریق Serial Monitor در Arduino انجام شده است.
