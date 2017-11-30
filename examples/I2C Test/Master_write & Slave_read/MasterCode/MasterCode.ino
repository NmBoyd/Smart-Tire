#include <Wire.h>
//send character to arduino master
//master forwards the char to the slave
//slave turns on led
void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  while(Serial.available())
  {
    char c = Serial.read();     //read the serial monitor for input

    if(c == 'H')//high. turn on light
    {
      Wire.beginTransmission(5); //arbitrary number from 1-127 for the slave
      Wire.write('H');          //send the char 'H'
      Wire.endTransmission();   //stop sending the char to the slave
      Serial.println("I sent a H");
    }
    else if(c == 'L')
    {
      Wire.beginTransmission(5);
      Wire.write('L');
      Wire.endTransmission();
      Serial.println("I sent a L");
    }
    
  }
}
