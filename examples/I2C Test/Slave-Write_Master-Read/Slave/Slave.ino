//i2c Slave
#include <Wire.h>

void setup()
{
  Wire.begin(5);
  Wire.onRequest(requestEvent); //when master asks for data from slave
}

void loop()
{
  delay(100);
}

void requestEvent()
{
  Wire.write("1234567890"); //send master this number
}
