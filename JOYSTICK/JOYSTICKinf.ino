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