//MMA8491Q test sketch

#include <Wire.h>

int sda = 18;
int scl = 19;

void setup() {
  Serial.begin(9600);
  Wire.begin();
}


void loop() {
  digitalWrite(scl, HIGH);
  digitalWrite(sda, HIGH);
  digitalWrite(sda, LOW);
  digitalWrite(scl, LOW);
  
  Serial.println("Start MMA8491q test");
  Wire.requestFrom(171, 8);
  
  while(Wire.available())    // slave may send less than requested
  { 
    Serial.println("start read");
    char c = Wire.read();    // receive a byte as character
    Serial.print(c);         // print the character
  }

  delay(500);
}

