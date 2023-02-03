#include <SPI.h>
#include <SD.h>
#include <DHT.h>
#include <Wire.h>
#include "Adafruit_SI1145.h"
#define Type DHT11

//Capacitive Soile Moisture Sensor Setup (calibrated)
const int dry = 500;
const int wet = 210;

//DHT11 Humidity Sensor Setup
int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float tempC;

//SI1145 UV Sensor Setup
Adafruit_SI1145 uv = Adafruit_SI1145();

//SD card module setup
const int chipSelect = 4;

void setup() {

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  HT.begin();
  uv.begin();

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
}

void loop() {
  // make a string for assembling the data to log:
  String dataString = "";

  // read three sensors and append to the string:
  //Moisture
  int sensorVal = analogRead(A0);
  int percentageMoisture = map(sensorVal, wet, dry, 100, 0);
  dataString += String(percentageMoisture);
  dataString += "%";
  dataString += ",";
  //Humidity
  humidity = HT.readHumidity();
  dataString += String(humidity);
  dataString += "%";
  dataString += ",";
  //Temperature
  tempC = HT.readTemperature();
  dataString += String(tempC);
  dataString += "C";
  dataString += ",";
  //UV
  float UVindex = uv.readUV();
  UVindex /= 100.0;
  dataString += String(UVindex);

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
     //print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}









