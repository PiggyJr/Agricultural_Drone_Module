
const int dry = 480;
const int wet = 210;

void setup() {
  Serial.begin(9600);

}

void loop() {
  
  int sensorVal = analogRead(A0);

  int percentageMoisture = map(sensorVal, wet, dry, 100, 0);
  
  Serial.print(percentageMoisture);
  Serial.println("%");

  delay(500);

}
