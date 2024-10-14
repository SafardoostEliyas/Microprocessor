const int ledpin=12;
void setup() {
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
if(Serial.available()> 0){
  int value = Serial.parseInt();
  if(value == 10){
     digitalWrite(ledpin,HIGH);
    }else if(value == 20 ){
           digitalWrite(ledpin,LOW);
    };
  
  };

}
