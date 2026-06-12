void setup() {


  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  delay(1500);
  digitalWrite(13, LOW);
  digitalWrite(10, HIGH);
   delay(1500);
  digitalWrite(10, LOW);
  delay(1500);
}