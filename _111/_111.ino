#include "SevSeg.h"
SevSeg sevseg;
int a;
void setup()
{
  Serial.begin(9600);
  Serial.println("group:14 number:03050371");
  byte numDigits = 4;
  byte digitPins[] = {A0,A1,A2,A3};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);


}
void loop()
{
   
  a=Serial.parseInt( );
  if(a!=0)
  {
  Serial.println(a);
  }
  int val;
    if(Serial.available())
    {
      val = Serial.parseInt();
      Serial.println(val);    
      if(val>=0 && val<10000)
      {
        sevseg.setNumber(val);
          sevseg.refreshDisplay();
        }
      else
        Serial.println("range error");  
      
      
    }
    else
            sevseg.refreshDisplay();

 
}
