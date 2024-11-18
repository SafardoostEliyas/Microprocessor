void setup() {
Serial.begin(9600);

}

void loop() {
float d=analogRead(A1);
d=d*0.488822000;
Serial.print("Dama=");
Serial.println(d);
delay(1000);

}