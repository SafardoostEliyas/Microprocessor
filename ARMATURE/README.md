
# کنترل موتور به کمک ماژول درایو موتور

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و آرمیچر و ماژول درایو موتور و برد Arduino میخواهیم جهت و سرعت چرخ موتور را کنترل کنیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- ماژول درایو موتور
- منبع تغذیه
- سیم رابط
- موتور(آرمیچر)
## طریقه انجام آزمایش (اتصالات):
- کد را در نرم‌افزار Arduino IDE اجرا کرده و روی برد آپلود میکنیم موتور و درایو را مطابق شما به برد و به یکدیگر متصل میکنیم و با منبع تغذیه برق مورد نیازشان را تامین میکنیم.

## تصاویر:
![SchemaArmature](https://github.com/user-attachments/assets/ed5dc82c-ba7d-4288-a574-2fb730fd81dd)
![ArmatureProj](https://github.com/user-attachments/assets/a4da8a87-3fd8-4648-89d3-16b488c98e56)



## کد پروژه:
```cpp
void setup() { 
 pinMode(9, OUTPUT); //IN1 
 pinMode(8, OUTPUT); //IN2 
 pinMode(10, OUTPUT); //Enable Pin 
} 
void loop() { 
// Full speed forward 
 digitalWrite(9, HIGH); 
 digitalWrite(8, LOW); 
 digitalWrite(10, HIGH); 
 delay(1000); 
// Full speed backward 
 digitalWrite(9, LOW); 
 digitalWrite(8, HIGH); 
 digitalWrite(10, HIGH); 
 delay(1000); 
// 0 to 100% speed in forward mode 
 for (int i=0;i<256;i++) 
 { digitalWrite(9, HIGH); 
 digitalWrite(8, LOW); 
 analogWrite(10, i); 
 delay(20);  
 } 
 delay(50); 
// 0 to 100% speed in backward mode 
 for (int i=0;i<256;i++) 
 { digitalWrite(9, LOW); 
 digitalWrite(8, HIGH); 
 analogWrite(10, i); 
 delay(20);  
 } 
 delay(50);
```

## طرز کار:
این آزمایش برای کنترل یک موتور DC با استفاده از ماژول درایور موتور H-Bridge طراحی شده است. به طور خاص، این کد به شما امکان می‌دهد موتور را در هر دو جهت (حرکت به جلو و عقب) کنترل کرده و همچنین سرعت آن را با استفاده از تکنیک PWM (Pulse Width Modulation) تغییر دهید. این نوع آزمایش معمولاً برای یادگیری و تست نحوه کنترل موتورهای DC در پروژه‌های رباتیک و الکترونیکی استفاده می‌شود.
## نتیجه‌ پروژه:
بررسی و یادگیری کنترل موتورهای DC با تغییر جهت و سرعت.
استفاده از PWM برای کنترل سرعت.
آشنایی با عملکرد درایور H-Bridge و نحوه کنترل آن.
این نوع آزمایش معمولاً در پروژه‌هایی مثل ساخت خودروهای رباتیک، بازوهای مکانیکی یا دیگر سیستم‌های حرکتی استفاده می‌شود.
همچنین انجام این دستورات از طریق کد نویسی در Arduino انجام شده است.