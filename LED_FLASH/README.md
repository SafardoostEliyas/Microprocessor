
# روشن و خاموشی متناوب LED

## شرح مختصر پروژه
در این پروژه ما با استفاده از نرم افزار و برد Arduino یک LED را کنترل میکنیم. تحت تاثیر زمان لامپ ها روشن و خاموش میشوند.

## لوازم مورد نیاز
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- لامپ LED
- سیم‌های رابط
- مقاومت 220 اهم

## تصاویر
![circuit](https://github.com/user-attachments/assets/7673fc80-a997-4549-a6b7-bf413b3319a5)
![Led-clignotante-scaled](https://github.com/user-attachments/assets/5a9a7a7e-ffdf-425f-89e1-225280287358)



## طریقه انجام آزمایش (اتصالات)
- پایه منفی LED به مقاومت 220 اهم و سپس به GND همچنین پایه مثبت LED به پین 12 بر روی برد Arduino متصل می‌شود.

## کد پروژه

```cpp
int led= 9;
void setup() {
pinMode(led,OUTPUT);

}

void loop() {

digitalWrite(led,HIGH);
delay(3000);
digitalWrite(led,LOW);
delay(3000);
}
```

## طرز کار
با آپلود کردن برنامه می‌توان روشن و خاموش شدن لامپ را بصورت متناوب مشاهده کرد.


## نتیجه‌ پروژه
در این پروژه نشان‌ میدهیم که چگونه یک LED بطور متناوب روشن و خاموش میشود.
