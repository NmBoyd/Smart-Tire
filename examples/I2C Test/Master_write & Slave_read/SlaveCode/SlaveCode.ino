#include <Wire.h>

void setup() {
 Wire.begin(5);  //the address of this slave arduino
  Wire.onReceive(receiveEvent);
  
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop()
{ 
  
}

void receiveEvent(int howMany)  //stores how many bytes come from the master
{
  while(Wire.available())
  {
    char c = Wire.read();
    
    if(c == 'H')
    {
      digitalWrite(13,HIGH);
    }
    else if(c == 'L')
    {
      digitalWrite(13,LOW);
    }
  }
}

