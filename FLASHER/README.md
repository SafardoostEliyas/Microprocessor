
# روشن و خاموش شدن تدریجی LED به صورت LOOP

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و برد Arduino و LED یک چراغ هشدار دهنده خاموش و روشن شونده خودکار میسازیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- لامپ های LED
- سیم‌های رابط
- مقاومت 220 اهم

## طریقه انجام آزمایش (اتصالات):
- یک مدار ساده با LED که به برد آردوینو هم متصل شده میبندیم.
## تصاویر:
![FLASHER0](https://github.com/user-attachments/assets/d3ca6cbe-3c20-484d-94ae-778c9ae8c403)
![FLASHER1](https://github.com/user-attachments/assets/5783a3fe-83c1-4960-b2c8-3c2d3c7e51b0)
![FLASHER2](https://github.com/user-attachments/assets/af919f80-fa2b-4005-a044-b2dcc122979a)
![FLASHER3](https://github.com/user-attachments/assets/89f10e44-5061-4a6e-8f00-08ac1676904a)
![schema_flasher](https://github.com/user-attachments/assets/6c7591e4-7a49-4a94-bc89-dbcd7831f5a3)
![code](https://github.com/user-attachments/assets/01583354-1703-4bd0-85a1-026dc47dc988)





## کد پروژه:
```cpp
int ledPin = 9; // پین دیجیتال

void setup() {
  pinMode(ledPin, OUTPUT); // خروجی
}

void loop() {
  // افزایش روشنایی
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);  // تنظیم روشنایی
    delay(10); 
  }

  // کاهش روشنایی
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);  // تنظیم روشنایی
    delay(10);
  }
}
```

## طرز کار:
بعد از متصل کردن مدار و نوشتن و اپلود برنامه ان در برنامه لامپ بطور خودکار روشن شده و از نور کم به نور زیاده رفته و برعکس تکرار میشود.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه میتوان یک چراغ هشدار دهنده ساخت. همچنین انجام این دستورات از طریق کد نویسی در Arduino انجام شده است.