
const int dry = 480;
const int wet = 210;
int state;

void setup() {
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0){
    state = Serial.parseInt();
  }

  while (state == 1){
    int sensorVal = analogRead(A0);

    int percentageMoisture = map(sensorVal, wet, dry, 100, 0);
  
    Serial.print(percentageMoisture);
    Serial.println("%");

    delay(500);

    Serial.println(Serial.available());

    if (Serial.available() > 2){
      state = Serial.parseInt();
      Serial.println(Serial.available());
    }
  }
}
