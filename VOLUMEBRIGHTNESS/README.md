
# تنظیم نور LED

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و برد Arduino و پتانسیومتر نور لامپ LED را تنظیم کنیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- لامپ های LED
- سیم‌های رابط
- مقاومت 220 اهم
- پتانسیومتر

## طریقه انجام آزمایش (اتصالات):
- پتانسیومتر و لامپ را روی برد بورد قرار داده و به برد اردوینو نیز متصل میکنیم.
## تصاویر:
![FLASHER0](https://github.com/user-attachments/assets/25e596f2-fa45-40a0-810f-e976f0a84c2d)
![FLASHER1](https://github.com/user-attachments/assets/0e1bc181-b070-40b9-b49c-6a3c0e8b327a)
![FLASHER2](https://github.com/user-attachments/assets/953f1c8e-2ef5-4650-9f15-ae651a38596f)
![FLASHER3](https://github.com/user-attachments/assets/50df2870-9758-40eb-a99d-f27a7c4ea8b1)
![code](https://github.com/user-attachments/assets/d235a127-4b00-4bfa-8369-e366fcf3a910)
![LED](https://github.com/user-attachments/assets/cdd543de-1533-42ae-b3dd-5930f5333e21)


## کد پروژه:
```cpp
int ledPin = 9;    // پایه دیجیتال
int potPin = A0;   // پایه آنالوگ پتانسیومتر
int potValue = 0;  // خوانده شده از پتانسیومتر

void setup() {
  pinMode(ledPin, OUTPUT);  // خروجی
}

void loop() {
  potValue = analogRead(potPin);                       // خواندن پتانسیومتر
  int ledBrightness = map(potValue, 0, 1023, 0, 255);  //تبدیل
  analogWrite(ledPin, ledBrightness);                  // تنظیم روشنایی
  delay(10);
}
```

## طرز کار:
بعد از متصل کردن مدار و نوشتن و اپلود برنامه ان در برنامه با چرخاندن پیچ پتانسیومتر شدت نور تنظیم میشود.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه میتوان با یک لامپ و مقاومت متغیر یک لامپ با روشنایی قابل تنظیم ساخت. همچنین انجام این دستورات از طریق کد نویسی در Arduino انجام شده است.