
# تشخیص فواصل اجسام به کمک سنسور اولتراسونیک

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و سنسور و برد Arduino میخواهیم فواصل اجسام مختلف را از سنسور نشان دهیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- سنسور Ultrasonic
- سیم رابط

## طریقه انجام آزمایش (اتصالات):
- کد را در نرم‌افزار Arduino IDE اجرا کرده و سنسور را به برد متصل کرده و پس از آپلود کد ، فواصل اجسام از سنسور خواهد داد.

## تصاویر:

![Ultrasonic](https://github.com/user-attachments/assets/2f37f050-a1c8-4998-becb-d5f9b63ef7eb)
![Ultrasonicschema](https://github.com/user-attachments/assets/9cfce9d5-f146-445f-9415-7baba44afabd)



## کد پروژه:
```cpp
const int trigPin = 7;
const int echoPin = 6;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);


  distance = duration * 0.034 / 2;


  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
```

## طرز کار:
با نصب سنسور و آپلود کد میتوانیم فواصل اجسام را در Serial monitor بر حسب سانتی متر مشاهده کنیم.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه میتوان فواصل اجسام را از سنسور نمایش داده و از آن برای ساخت رادار های فواصل کوتاه مانند رادار خودرو و ... استفاده کرد. همچنین انجام این دستورات از طریق کد نویسی در Arduino و مشاهده آن در Serial Monitor انجام شده است.