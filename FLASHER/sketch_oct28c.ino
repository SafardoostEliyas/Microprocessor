int ledPin = 9; // پین دیجیتال

void setup() {
  pinMode(ledPin, OUTPUT); // خروجی
}

void loop() {
  // افزایش روشنایی
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);  // تنظیم روشنایی
    delay(10); 
  }

  // کاهش روشنایی
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);  // تنظیم روشنایی
    delay(10);
  }
}