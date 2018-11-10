void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to runonce repeatedly:
  Serial.println(digitalRead(2));
  if (digitalRead(2) == 0){
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  if (digitalRead(2) == 1){
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
}
