
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLrz44PxHJ"
#define BLYNK_DEVICE_NAME "NodeMCU"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
int x,y;
BLYNK_WRITE(V0)
{ 
  x=digitalRead(5);
  Serial.println(x);
  if(digitalRead(5)==1)
  {
    Serial.println("Battery-1 and solar - Bt 2");
    y=1;
    
  }
  else if(digitalRead(5)==0)
  {
    Serial.println("Battery-2 and solar - Bt 1");
    y=2;
    
  }
  else
  {
    Serial.println("Cannot Determine");
    y=0;
   
  }
  Blynk.virtualWrite(V0,y);
}
BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);
}
void setup()
{
  pinMode(5,INPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  
}
