//const maken van eerste pin
const int firstPin = 6;
//const maken van laatste pin
const int lastPin = 13;
//const maken om wacht tijd tussen lapjes aan te geven
const int waitTimeInMs = 100; 

void setup() {
  for (int i = firstPin; i <= lastPin; i++) {
    pinMode(i, OUTPUT);
  }
}
// for loop zegt: i is nummer van firstpin (6) als i kleiner is dan lastpin (13) verhoog met 1

void loop() {
  for (int i = firstPin; i <= lastPin; i++) {
    digitalWrite(i, HIGH);
    delay(waitTimeInMs);
    digitalWrite(i, LOW);
  }
// loop om lichtjes heen te laten bewegen (zelfde als setup maar nu maakt hij de pins niet aan maar optellend geef hij instructie)

  for (int i = lastPin ; i >= firstPin; i--) {
    digitalWrite(i, HIGH);
    delay(waitTimeInMs);
    digitalWrite(i, LOW);
  }
}

//2e stukje van de loop om lichtjes terug te laten bewegen dit is dus als i aan het eind is dan met -- verlaag je hem dus)