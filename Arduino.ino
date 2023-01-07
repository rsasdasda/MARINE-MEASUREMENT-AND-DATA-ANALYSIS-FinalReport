
#include "DHT.h"
#include <SPI.h>
#include <SD.h>
#define DHTTYPE DHT11
#define DHTPIN 6

DHT dht(DHTPIN,DHTTYPE);

File myFile;

void setup()

{
Serial.begin(9600);
SD.begin(4);
Serial.println("Initializing SD card...");

myFile = SD.open("hw5.txt", FILE_WRITE);

if(myFile) 
{
  Serial.println("writing to FinalReport.txt ...");

  myFile.close();
  Serial.println("done");
}
else
{
  Serial.println("error opening FinalReport.txt");
}



Serial.begin(9600);
dht.begin();
delay(1000);
}

void loop()
 {
float h = dht.readHumidity();
float t = dht.readTemperature();

myFile.print(h);
myFile.print(t);
Serial.print("Humidity: ");
Serial.print(h);
Serial.print(" %\t");
Serial.print("Temperature: ");
Serial.print(t);
Serial.println(" C");
delay(2000);

}
