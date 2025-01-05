# کار با ماژول اینفرارد

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و ماژول مادون قرمز IR و برد Arduino میخواهیم نزدیک شدن اجسام را تشخیص دهیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- ماژول مادون قرمز IR
- سیم رابط
- لامپ LED

## طریقه انجام آزمایش (اتصالات):
- کد را در نرم‌افزار Arduino IDE اجرا کرده و ماژول مادون قرمز IR و لامپ را به برد بورد متصل کرده و پس از آپلود کد ، با تغییر وضعیت ماژول مادون قرمز IR نتیجه را مشاهده می کنیم.


## تصاویر:
![image](https://github.com/user-attachments/assets/2812bfad-4d64-4232-a0d2-e36a61547e2e)
![image](https://github.com/user-attachments/assets/86fd8b7c-c181-4919-b543-61a8bed7e7d2)
![image](https://github.com/user-attachments/assets/a84afa60-943a-4228-ab81-8336a626ba05)






## کد پروژه:
```cpp
int led = 2; // پین LED
int sensorPin = A0; // پین سنسور IR
int IR;

void setup() {
  pinMode(sensorPin, INPUT); // تنظیم پین سنسور به عنوان ورودی
  pinMode(led, OUTPUT);      // تنظیم پین LED به عنوان خروجی
  Serial.begin(9600);        // شروع ارتباط سریال
}

void loop() {
  IR = digitalRead(sensorPin); // خواندن وضعیت سنسور
  if (IR == LOW) { // اگر مانعی شناسایی شود
    Serial.print("Object detected = ");
    Serial.println(IR);
    digitalWrite(led, HIGH); // روشن کردن LED
  } else {
    Serial.print("Not detected = ");
    Serial.println(IR);
    digitalWrite(led, LOW); // خاموش کردن LED
  }
  delay(300); // تاخیر 300 میلی‌ثانیه
}
```
## طرز کار:
با نصب ماژول مادون قرمز IR و آپلود کد میتوانیم لامپ را از طریق ماژول مادون قرمز IR خاموش روشن کرده و وضعیت آن را در Serial monitor مشاهده کنیم.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه میتوان با استفاده از ماژول مادون قرمز IR نزدیک شدن اجسام را تشخیص داده و از آن برای کنترل و تغییر مقادیر استفاده کرد. همچنین انجام این دستورات از طریق کد نویسی در Arduino و مشاهده آن در Serial Monitor انجام شده است.
