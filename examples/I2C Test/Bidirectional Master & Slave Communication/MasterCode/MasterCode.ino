#include <Wire.h>;
 
void setup()
{
Wire.begin();
Serial.begin(9600);
}
 
void loop()
{
delay(100);
//////////////////////////////////  Request data from Slave
int32_t currentPos;
 
//byte array for 32-bits. i.e 4 bytes.
byte byteArray[4];
Wire.requestFrom(54,4); //request 32-bits from slave
for(int i = 0;i<sizeof(byteArray);i++)  //read the 4 requested bytes
{
  byteArray[i] = Wire.read();
}
currentPos = byteArray[0];
currentPos = (currentPos << 8) | byteArray[1];
currentPos = (currentPos << 8) | byteArray[2];
currentPos = (currentPos << 8) | byteArray[3];
 
Serial.print(currentPos);
Serial.print("\n");

///////////////////////////////////  Send data to Slave
int32_t targetPos;
Wire.beginTransmission(54);
Wire.write(targetPos);
Wire.endTransmission();

}

