//#include <SoftwareSerial.h> //Für debugging
#include <MANCHESTER.h>
#include <TinyWireM.h>
#include <USI_TWI_Master.h>
#include <tinybmp.h>

//const int rx=3; //Für debugging
//const int tx=4;//Für debugging
const int trx=1;

tinybmp180 tiny;
//SoftwareSerial ser(rx,tx);//Für debugging
void setup() {
  // put your setup code here, to run once:
tiny.begin();
//ser.begin(9600);//Für debugging
MANCHESTER.SetTxPin(trx);
}

void loop() {
//Temp lesen und in int umwandeln
float a=tiny.readTemp()*100.0;
int b =(int)a; 
//Druck lesen und aus 32 bit in 2 16 bit int machen für besseres senden 
uint32_t c=tiny.readPressure();
uint16_t Low=c;
uint16_t High=c>>16;
//uint32_t temp=High;//Für debugging
//temp<<=16;          //Für debugging
//temp|=Low;//Für debugging
  // put your main code here, to run repeatedly:
  MANCHESTER.Transmit(b);
  delay(20);
  MANCHESTER.Transmit(Low);
  delay(20);
  MANCHESTER.Transmit(High);
  delay(20);
  //ser.println(tiny.readPressure()); //Für debugging
  //ser.println(Low); //Für debugging 
  //ser.println(High); //Für debugging
  //ser.println(temp); //Für debugging
  //ser.println("###############"); //Für debugging
  //MANCHESTER.Transmit(tiny.readPressure()); //Für debugging
delay(500);
}
