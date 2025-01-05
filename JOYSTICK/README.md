# کار با جوی استیک

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و جوی استیک و برد Arduino میخواهیم ارسال مقادیر و دستورات را انجام دهیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- ماژول جوی استیک
- سیم رابط
- لامپ LED

## طریقه انجام آزمایش (اتصالات):
- کد را در نرم‌افزار Arduino IDE اجرا کرده و ماژول و لامپ را به برد بورد متصل کرده و پس از آپلود کد ، با تغییر وضعیت جوی استیک نتیجه را مشاهده می کنیم.


## تصاویر:
![image](https://github.com/user-attachments/assets/b28939ec-51c7-44ba-930c-85a06365f955)
![1000269552](https://github.com/user-attachments/assets/93d9715e-35f3-48c3-b916-66a6709050ce)
![1000269553](https://github.com/user-attachments/assets/f7ca908b-e8e7-4b9e-8ba8-f9b50b9aa576)




## کد پروژه:
```cpp
const int joystickX = A1;
const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT); 
  pinMode(joystickX, INPUT);
}

void loop() {
  int xValue = analogRead(joystickX);
  int brightness = map(xValue, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
}
```
```cpp
int VRx = A0; // پین محور X
int VRy = A1; // پین محور Y
int SW = 2;   // پین کلید فشاری (در صورت وجود)
int xValue, yValue, buttonState;

void setup() {
  Serial.begin(9600); // شروع ارتباط سریال
  pinMode(SW, INPUT_PULLUP); // تنظیم کلید به‌عنوان ورودی با Pull-up داخلی
}

void loop() {
  // خواندن مقادیر آنالوگ محورهای X و Y
  xValue = analogRead(VRx); 
  yValue = analogRead(VRy);

  // خواندن وضعیت کلید فشاری
  buttonState = digitalRead(SW);

  // چاپ مقادیر در سریال مانیتور
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  Serial.print(" | Button: ");
  Serial.println(buttonState == LOW ? "Pressed" : "Not Pressed");

  delay(100); // تاخیر برای کاهش نرخ چاپ
}
```
## طرز کار:
با نصب ماژول و آپلود کد میتوانیم لامپ را از طریق جوی استیک خاموش روشن کرده و با کد دوم وضعیت آن را در Serial monitor مشاهده کنیم.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه میتوان با استفاده از جوی استیک فرامین را صادر کرده و از آن برای کنترل و تغییر مقادیر استفاده کرد. همچنین انجام این دستورات از طریق کد نویسی در Arduino و مشاهده آن در Serial Monitor انجام شده است.
