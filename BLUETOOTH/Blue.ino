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