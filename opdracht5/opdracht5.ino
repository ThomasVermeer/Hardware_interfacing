#include <Servo.h> // De ingebouwde bibliotheek inladen om een servo aan te kunnen sturen

Servo propellor; // zelf gekozen naam servo

const int knopLinks = 13;  // Drukknop 1 vast aan pin 13
const int knopRechts = 12; // Drukknop 2 vast aan pin 12
const int motorPoort = 3;  // Servomotor signaaldraad vast aan pin 3 met ~

int statusLinks = 0;
int statusRechts = 0;

void setup() {
  pinMode(knopLinks, INPUT);
  pinMode(knopRechts, INPUT);
  
  propellor.attach(motorPoort); // geef aan op welke poort de propellor zit
  propellor.write(0);           // startpositie in graden aangeven (0)
}

//methode van de gestuurde bewegingen
void aansturenServo(int duurHeenweg, int pauzeTijd, int duurTerugweg) {
  
  // HEENWEG: Van 0 naar 120 graden bewegen (van begin tot eind)
  // bereken de stapgrootte van de delay door de totale tijd te delen door 120 stapjes
  int delayHeen = duurHeenweg / 120;
  for (int huidigeGraad = 0; huidigeGraad <= 120; huidigeGraad++) {
    propellor.write(huidigeGraad); // update positie van servo naar huidige graad
    delay(delayHeen);              // kort de tijd geven voor controle
  }

  // PAUZE: Blijf even op de uiterste stand staan (als de pauzeTijd groter is dan 0)
  if (pauzeTijd > 0) {
    delay(pauzeTijd);
  }

  // TERUGWEG: Van 120 terug naar 0 graden bewegen (terug)
  int delayTerug = duurTerugweg / 120;
  for (int huidigeGraad = 120; huidigeGraad >= 0; huidigeGraad--) {
    propellor.write(huidigeGraad); // Zet de servo op de huidige graad
    delay(delayTerug);             // Wacht even
  }
}

void loop() {
  // Lees de status van beide knoppen live uit (of ze wel of niet ingedrukt worden)
  statusLinks = digitalRead(knopLinks);
  statusRechts = digitalRead(knopRechts);

  // BEIDE knoppen zijn tegelijk ingedrukt
  if (statusLinks == HIGH && statusRechts == HIGH) {
    // Heen in 5s (5000ms), 2s pauze (2000ms), terug in 0.5s (500ms)
    aansturenServo(5000, 2000, 500);
  }
  // Alleen de linker knop is ingedrukt
  else if (statusLinks == HIGH) {
    // Heen in 5s (5000ms), 0s pauze, terug in 5s (5000ms)
    aansturenServo(5000, 0, 5000);
  }
  // Alleen de rechter knop is ingedrukt
  else if (statusRechts == HIGH) {
    // Heen in 0.5s (500ms), 0s pauze, terug in 0.5s (500ms)
    aansturenServo(500, 0, 500);
  }
}