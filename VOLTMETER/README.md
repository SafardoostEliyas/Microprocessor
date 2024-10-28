
# نمایش ولتاژ دو سر پتانسیومتر

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و برد Arduino و پتانسیومتر ولتاژ دو سر آن را محاسبه میکنیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- لامپ های LED
- سیم‌های رابط
- مقاومت 220 اهم
- پتانسیومتر

## طریقه انجام آزمایش (اتصالات):
- پتانسیومتر را روی برد بورد قرار داده و به برد اردوینو نیز متصل میکنیم.
## تصاویر:
![voltmeter](https://github.com/user-attachments/assets/bab2e2c3-217a-4111-8cba-fa66aea0ac6d)
![volt_meter](https://github.com/user-attachments/assets/70809063-da84-4dd1-9c5a-ab007798dad5)
![code](https://github.com/user-attachments/assets/e22f65e3-f18c-470e-b50a-12bff6dfad44)



## کد پروژه:
```cpp
int potPin = A0;    // پین آنالوگ پتانسیومتر
int potValue = 0;   // متغیر برای نگهداری مقدار پتانسیومتر
float voltage = 0;  // متغیر برای نگهداری ولتاژ محاسبه شده

void setup() {
  Serial.begin(9600);  // سرعت شروع ارتباط سریال
}

void loop() {
  potValue = analogRead(potPin);        // خواندن مقدار پتانسیومتر
  voltage = potValue * (5.0 / 1023.0);  // تبدیل مقدار به ولتاژ

  // نمایش ولتاژ در Serial Monitor
  Serial.print("Voltage: ");
  Serial.println(voltage);

  delay(500);  // تاخیر خواندن مجدد
}
```

## طرز کار:
بعد از متصل کردن مدار و نوشتن و اپلود برنامه ان در برنامه با چرخاندن پیچ پتانسیومتر در serial monitor ولتاژ دو سر آن نمایش داده می شود.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه میتوان ولتاژ دو سر پتانسیومتر را اندازه گرفت. همچنین انجام این دستورات از طریق کد نویسی در Arduino و نمایش ان در serial monitor انجام شده است.