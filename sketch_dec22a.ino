#include "DHT.h"
#define DHTPIN 6
#define DHTTYPE DHT11
#include <SPI.h>
#include <SD.h>

DHT dht(DHTPIN,DHTTYPE);
File myFile;
int time=1;


void setup()
{
  delay(1000);
  Serial.begin(9600);
  dht.begin();
  SD.begin(4);
  myFile = SD.open("HW01.txt",FILE_WRITE);
  if(myFile)
  {
    Serial.println("Writing to FinalReport.txt");
    myFile.close();
  }
  else
  {
    Serial.println("error opening FinalReport.txt");
  }

}


void loop()
{
  delay(300000);
  float h=dht.readHumidity();
  float t=dht.readTemperature();

  myFile = SD.open("HW01.txt",FILE_WRITE);


if(time<49)
{

  if(myFile)
{

    Serial.println("======================================================");
    Serial.print("NO.");
    Serial.print(time);
    Serial.print(" Humidity:");
    Serial.print(h);
    Serial.print("%\t");

    Serial.print("  Temperature:");
    Serial.print(t);
    Serial.println(" °C");


    myFile.println("======================================================");
    myFile.print("NO.");
    myFile.print(time);
    myFile.print(" Humidity : ");
    myFile.print(h);
    myFile.print("%\t");

    myFile.print("  Temprerature : ");
    myFile.print(t);
    myFile.println(" °C");
    time=time+1;

    if(time==49)
    {
      myFile.println("======================================================");
      myFile.println("done");
    }
    
    myFile.close();

} // if myFile end
else
{
 myFile.println("error opening FinalReport.txt");
} // not myFile



}  //if time<N end

}//void loop end



