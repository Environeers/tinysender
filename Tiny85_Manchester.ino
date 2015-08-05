//#include <SoftwareSerial.h>
#include <MANCHESTER.h>
#include <TinyWireM.h>
#include <USI_TWI_Master.h>
#include <tinybmp.h>

//const int rx=3;
//const int tx=4;
const int trx=1;

tinybmp180 tiny;
//SoftwareSerial ser(rx,tx);
void setup() {
  // put your setup code here, to run once:
tiny.begin();
//ser.begin(9600);
MANCHESTER.SetTxPin(trx);
}

void loop() {
float a=tiny.readTemp()*100.0;
int b =(int)a; 
uint32_t c=tiny.readPressure();
uint16_t Low=c;
uint16_t High=c>>16;
//uint32_t temp=High;
//temp<<=16;
//temp|=Low;
  // put your main code here, to run repeatedly:
  MANCHESTER.Transmit(b);
  delay(20);
  MANCHESTER.Transmit(Low);
  delay(20);
  MANCHESTER.Transmit(High);
  delay(20);
  //ser.println(tiny.readPressure());
  //ser.println(Low);
  //ser.println(High);
  //ser.println(temp);
  //ser.println("###############");
  //MANCHESTER.Transmit(tiny.readPressure());
delay(500);
}
