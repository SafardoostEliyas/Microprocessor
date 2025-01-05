
# کنترل هوشمند روشنایی معابر

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و سنسور فوتوسل و برد Arduino میخواهیم لامپ LED روی برد بطور خودکار با تاریک شدن روشن و در نور خاموش شود.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- سنسور فوتوسل
- مقاومت

## طریقه انجام آزمایش (اتصالات):
- کد را در نرم‌افزار Arduino IDE اجرا کرده و روی برد آپلود میکنیم سنسور فوتوسل را به پین A0 متصل کرده مقدار سنجیده شده توسط فوتوسل را از طریق Serial Monitor مشاهده کرده و تغییرات در شرایط متفاوت را در LED میبینیم.

## تصاویر:
![schema_smart_lightening](https://github.com/user-attachments/assets/e5a742d6-472d-4540-975a-674d5009fad0)
![solarcell](https://github.com/user-attachments/assets/9d634206-94b1-469d-8e5d-178fedbadc2d)



## کد پروژه:
```cpp
const int ldrPin = A0; // پین فوتوسل
const int ledPin = 9;  // پین LED
int ldrValue = 0;      // متغیر برای ذخیره مقدار LDR

void setup() {
  pinMode(ledPin, OUTPUT);    // تنظیم LED به عنوان خروجی
  Serial.begin(9600);         // شروع ارتباط سریال
}

void loop() {
  // خواندن مقدار آنالوگ فوتوسل
  ldrValue = analogRead(ldrPin);

  // نمایش مقدار نور در سریال مانیتور
  Serial.print("Light Intensity: ");
  Serial.println(ldrValue);

  // تنظیم روشنایی LED بر اساس مقدار فوتوسل
  int ledBrightness = map(ldrValue, 0, 1023, 0, 255); // تبدیل مقیاس 0-1023 به 0-255
  analogWrite(ledPin, ledBrightness);

  delay(100); // تاخیر 100 میلی‌ثانیه
}
```

## طرز کار:
با اپلود برنامه و گرفتن یک لامپ روی فوتوسل LED خاموش و در شرایط تاریکتر روشن میشود.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه میتوان کنترل روشنایی معابر شهری را هوشمند سازی کزد. همچنین انجام این دستورات از طریق کد نویسی در Arduino انجام شده است.
