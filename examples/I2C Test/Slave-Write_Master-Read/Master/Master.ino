//i2c Master(UNO)
#include <Wire.h>

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  
  Wire.requestFrom(5,10);//10 is the number of byes to request. 
  //1f 2 instead of 10, you get 12 out of 1234567890
  
  while(Wire.available())
  {
    char c = Wire.read();
    Serial.print(c);
  }
}

void loop()
{
}
