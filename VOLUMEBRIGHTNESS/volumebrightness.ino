int ledPin = 9;    // پایه دیجیتال
int potPin = A0;   // پایه آنالوگ پتانسیومتر
int potValue = 0;  // خوانده شده از پتانسیومتر

void setup() {
  pinMode(ledPin, OUTPUT);  // خروجی
}

void loop() {
  potValue = analogRead(potPin);                       // خواندن پتانسیومتر
  int ledBrightness = map(potValue, 0, 1023, 0, 255);  //تبدیل
  analogWrite(ledPin, ledBrightness);                  // تنظیم روشنایی
  delay(10);
}