//MMA8491Q test sketch

#include <Wire.h>

int sda = 18;
int scl = 19;
int en = 20;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(en, OUTPUT);
}


void loop() {
  /*digitalWrite(scl, HIGH);
  digitalWrite(sda, HIGH);
  digitalWrite(sda, LOW);
  digitalWrite(scl, LOW);*/
  digitalWrite(en, HIGH);
  delay(10);
  
  Serial.println("Start MMA8491q test");
  Wire.requestFrom(0x55, 3);
  
  while(Wire.available())    // slave may send less than requested
  { 
    Serial.println("start read");
    int c = Wire.read();    // receive a byte as character
    Serial.println(c);         // print the character
  }

  delay(500);
  digitalWrite(en, LOW);

}

