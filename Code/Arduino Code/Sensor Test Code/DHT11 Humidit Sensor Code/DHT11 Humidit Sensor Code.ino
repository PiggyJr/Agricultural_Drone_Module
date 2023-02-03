#include <DHT.h>
#define Type DHT11

int sensePin=2;
DHT HT(sensePin,Type);
float humidity;
float tempC;

void setup() {

Serial.begin(9600);

HT.begin();
delay(500);

}

void loop() {
  
  //Start of program

humidity = HT.readHumidity();
tempC = HT.readTemperature();

Serial.print("Humidity: ");
Serial.print(humidity);
Serial.print(" %\n");
Serial.print("Temperature: ");
Serial.print(tempC);
Serial.print(" C\n");

}
