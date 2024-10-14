const int ledpin=12;
void setup() {
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
if(Serial.available()> 0){
  String value = Serial.readString();

  if(value == "ROSHAN"){
     digitalWrite(ledpin,HIGH);
    }else if(value == "KHAMOSH"){
           digitalWrite(ledpin,LOW);
    };
  
  };

}
