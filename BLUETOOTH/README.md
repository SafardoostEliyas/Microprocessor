# کار با ماژول بلوتوث

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و ماژول بلوتوث و برد Arduino میخواهیم ارسال و دریافت پیام و دستورات را انجام دهیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- ماژول HC-05
- سیم رابط
- لامپ LED

## طریقه انجام آزمایش (اتصالات):
- کد را در نرم‌افزار Arduino IDE اجرا کرده و ماژول و لامپ را به برد بورد متصل کرده و پس از آپلود کد ، دستورات را به وسیله دستگاه دیگری ارسال میکنیم.


## تصاویر:
![1000269546](https://github.com/user-attachments/assets/eb2ccf98-c405-4ee0-93d2-1d26e4e35340)
![1000269544](https://github.com/user-attachments/assets/991e09a4-0886-4d0a-bfc0-ca2a28ea062a)
![image](https://github.com/user-attachments/assets/98582718-9434-4bed-b4d7-a1d037e81ab5)
![1000269545](https://github.com/user-attachments/assets/3693cb8c-f790-4f09-86d5-ed0bb7b80503)


## کد پروژه:
```cpp
#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(10, 11); // RX | TX  
String flag;  
int LED = 13;  

void setup() {    
  Serial.begin(9600);  
  MyBlue.begin(9600);  
  pinMode(LED, OUTPUT);  
  Serial.println("Ready to connect\nDefault password is 1234 or 0000");  
}  

void loop() {  
  if (MyBlue.available()) {  
    flag = MyBlue.readString(); 
    flag.trim(); 
    Serial.print("Received: "); // چاپ داده دریافتی
    Serial.println(flag); 

    if (flag == "1") {  
      digitalWrite(LED, HIGH);  
      Serial.println("LED On");  
    }  
    else if (flag == "0") {  
      digitalWrite(LED, LOW);  
      Serial.println("LED Off");  
    }  
  }  
}
```

## طرز کار:
با نصب ماژول و آپلود کد میتوانیم لامپ را از طریق موبایل خاموش روشن کرده و وضعیت آن را در Serial monitor مشاهده کنیم.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه میتوان با استفاده از ماژول بلوتوث فرامین را صادر کرده و از آن برای ارتباطات نزدیک در دستگاه های دیجیتال استفاده کرد. همچنین انجام این دستورات از طریق کد نویسی در Arduino و مشاهده آن در Serial Monitor انجام شده است.
