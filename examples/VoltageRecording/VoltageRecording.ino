
float vout = 0.0;
float R1 = 30000.0; //  
float R2 = 7500.0; // 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  Serial.println("millis, Pot Voltage, Pot Position, Anode Voltage, Cathode Voltage, Nitinol Voltage Difference");
 
}

void loop() {
  
   uint32_t m = millis();
   Serial.print(m);         // milliseconds since start
   Serial.print(", ");  
   
 ////////////////////////////////////////////////////////////////////////////////////////////////// 
 
  double voltagePot = analogRead(A0);
  voltagePot = (voltagePot*7.19)/1023;           //convert count to voltage 0-7.2
  voltagePot = 7.19-voltagePot;                  //reverse the voltage polarity in code
  
  Serial.print(", ");
  Serial.print(voltagePot);
  
  float potPos = -1.8511*(voltagePot)+ 14.639;       //calculate potentiometer position using calibration curve data

  Serial.print(", ");
  Serial.print(potPos);
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  /*This wire should be attached to the entrance of the nitinol*/
  double voltageAnodeVal = analogRead(A3);
  vout = (voltageAnodeVal * 5.0) / 1024.0; // see text
  voltageAnodeVal = vout / (R2/(R1+R2));
  Serial.print(", ");   
  Serial.print(voltageAnodeVal);

//////////////////////////////////////////////////////////////////////////////////////
 /*This wire should be attached to the exit of the nitinol*/
 /*since this voltage should be lower than 5V, we don't need to attach the voltage sensor*/
  double voltageCathodeVal = analogRead(A4);    
  
  Serial.print(", ");   
  Serial.print(voltageCathodeVal);

////////////////////////////////////////////////////////////////////////////////////
  // converting that reading to voltage, for 3.3v arduino use 3.3, for 5.0, use 5.0
  double nitinolV = voltageAnodeVal - voltageCathodeVal;
  nitinolV = (nitinolV*7.2)/1024; 
  
  Serial.print(", ");   
  Serial.print(nitinolV);

Serial.println("");
 
  delay(10);
}
