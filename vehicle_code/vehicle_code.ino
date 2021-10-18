int sensor_pin = A0;
int output_value ;
int runTime = 1000;
int waterTime = 1000;
int r = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
}

void loop() {

  output_value = analogRead(sensor_pin);
  output_value = map(output_value, 550, 0, 0, 100);
  Serial.print("Mositure : ");
  Serial.print(output_value);
  Serial.println("%");
  delay(1000);

  if (output_value > 0) {
    runForword();

  }


}

void runForword() {
  Serial.println("run Forword");
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  delay(runTime);
  Serial.println("water");
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  Serial.print(output_value);
  delay(runTime);
  while (output_value > 0) {
    Serial.println("watering");
    output_value = analogRead(sensor_pin);
    output_value = map(output_value, 550, 0, 0, 100);
    Serial.println(output_value);
    if (output_value == 0) {
      comeBack();
    }
    if (output_value < 0) {
      comeBack();
    }

  }
  if (output_value < 0) {
    comeBack();
  }

}


void comeBack() {
  Serial.println("run back");
  digitalWrite(4, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(runTime);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}
