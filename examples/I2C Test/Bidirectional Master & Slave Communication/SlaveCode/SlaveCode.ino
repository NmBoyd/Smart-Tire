#include <Wire.h>;
 
void setup()
{
Wire.begin(54);
Wire.onRequest(requestEvent);
Wire.onReceive(receiveEvent);
}
 
void loop()
{
delay(100);
}
 
void requestEvent()
{
int32_t bigNum = 12345678;
byte myArray[4];

myArray[0] = (bigNum >> 24) & 0xFF;
myArray[1] = (bigNum >> 16) & 0xFF;
myArray[2] = (bigNum >> 8) & 0xFF;
myArray[3] = bigNum & 0xFF;
 
Wire.write(myArray, 4);
}

void receiveEvent(int howMany)
{
  while(Wire.available())
  {
    int32_t targetPos = Wire.read();
    Serial.println("I received the data");
    //Serial.println(targetPos);
  }
}

