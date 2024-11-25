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