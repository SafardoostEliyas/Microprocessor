
# تشخیص دمای محیط

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و سنسور و برد Arduino میخواهیم دمای محیط را از سنسور گرفته و نشان دهیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- سنسور Temperature
- سیم رابط

## طریقه انجام آزمایش (اتصالات):
- کد برنامه را در نرم‌افزار Arduino IDE اجرا کرده و سنسور را به برد متصل کرده و پس از آپلود کد ، دمای محیط را اندازه گرفته و در سیستم نمایش می دهد.

## تصاویر:

![Temp](https://github.com/user-attachments/assets/7a6495ea-c13c-459e-830c-0c19b682e29d)
![TempSchema](https://github.com/user-attachments/assets/a52ba6af-cb04-43c9-b3be-1b3c368f312d)
![TempShow](https://github.com/user-attachments/assets/659e75cb-03d4-4fe9-9baf-a2e0b6443b17)




## کد پروژه:
```cpp
void setup() {
Serial.begin(9600);

}

void loop() {
float d=analogRead(A1);
d=d*0.488822000;
Serial.print("Dama=");
Serial.println(d);
delay(1000);

}
```

## طرز کار:
با نصب سنسور و آپلود کد میتوانیم دمای محیط را در Serial monitor بر حسب سلسیوس مشاهده کنیم.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه دمای محیط را محاسبه کرده و در سیستم نمایش دهیم و از آن برای ساخت انواع دماسنج های الکترونیکی برای کاربرد های متفاوت استفاده کرد. همچنین انجام این دستورات از طریق کد نویسی در Arduino و مشاهده آن در Serial Monitor انجام شده است.