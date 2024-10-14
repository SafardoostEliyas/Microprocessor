# ساخت ماشین حساب ساده با Arduino از طریق Serial Monitor

## شرح مختصر پروژه
در این پروژه ما با استفاده از نرم افزار و برد Arduino یک ماشین حساب ساده طراحی کرده که میتوان در آن دو عدد و عملگر بین آنها را وارد کرده و در نهایت با زدن دکمه Enter نتیجه را دریافت کنیم.

## ابزارهای مورد نیاز
- برد Arduino Uno
- نرم‌افزار Arduino IDE
- کابل متصل کننده

## کد پروژه

```cpp
void setup() {
  Serial.begin(9600);
  Serial.println(type the calculation);
}

void loop() {
  while (Serial.available()  0) {
    int num1 = Serial.parseInt();
    char a = Serial.read();
    int num2 = Serial.parseInt();
    switch (a) {
      case '+'
        Serial.println(num1 + num2);
        break;

      case '-'
        Serial.println(num1 - num2);
        break;

      case ''
        Serial.println(num1  num2);
        break;

      case ''
      if(num2 != 0){
        Serial.println(num1  num2);
        }else{
          Serial.println(err);
        }
    }
  }
}
```
## نتیجه‌گیری
ما با تولید این برنامه و به کمک برد Arduino می توانیم ماشین حساب ساده , در حد چهار عمل اصلی طراحی کنیم.