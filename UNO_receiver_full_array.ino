#include <Manchester.h>

#define RX_PIN 4
#define BUFFER_SIZE 9
uint8_t data[BUFFER_SIZE];




float newTemp;
uint32_t newPres;
uint16_t newLow, newHigh;
uint8_t lLow,hLow,lHigh,hHigh,ub[4];

void setup() {
  //Transmitter initialisieren
Serial.begin(9600);
Serial.println("Starte Empfang");
man.setupReceive(RX_PIN, MAN_1200);
man.beginReceiveArray(BUFFER_SIZE,data);
}

void loop() {
  //Daten empfangen:
  if(man.receiveComplete())
  {
    ub[0]=data[1];
    ub[1]=data[2];
    ub[2]=data[3];
    ub[3]=data[4];
    lLow=data[5];
    hLow=data[6];
    lHigh=data[7];
    hHigh=data[8];
    newTemp=*(float *)&ub;
    newLow=(data[6]<<8)|data[5];
    newHigh=(data[8]<<8)|data[7];
    newPres=newHigh;
    newPres<<=16;
    newPres|=newLow;
    Serial.println(newPres);
    Serial.println(newTemp);
    Serial.println("#############");
    
    man.beginReceiveArray(BUFFER_SIZE,data);
  }
}
