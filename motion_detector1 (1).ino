int ledpin=12;
int pirpin=3;
int piezo=10;
void setup()
{
  pinMode(pirpin, INPUT);
  pinMode(ledpin,OUTPUT);
  pinMode(piezo,OUTPUT);
  Serial.begin(9600);
}

void loop()
{ 
  int read=digitalRead(pirpin);
  int write=analogRead(A0);
  Serial.print("motion");
  Serial.print(read);
  Serial.print("Photo");
  Serial.print(write);
  if(read==HIGH && write < 500){
    digitalWrite(ledpin,HIGH);
    digitalWrite(piezo,HIGH);
  }
  else{
    digitalWrite(ledpin,LOW);
    digitalWrite(piezo,LOW);
  }
  delay(200);
}
     
    