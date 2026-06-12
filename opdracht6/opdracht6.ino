#include <Wire.h>                  
#include <LiquidCrystal_I2C.h>     
// Initialiseer het LCD op het correcte adres ik gebruik 0x20
LiquidCrystal_I2C lcd(0x27, 16, 2); 

const int knop1 = 13; // Start / Lap knop
const int knop2 = 12; // Pauze knop

unsigned long startTijd = 0;
unsigned long verstrekenTijd = 0;
unsigned long gepauzeerdeTijd = 0;
unsigned long lapTijd = 0;
// variabelen benoemen (unsigned long) zorgt dat hij niet af rond - bij een double kan hij fouten gaan maken

bool loopt = false;
bool heeftLap = false;

// Variabelen voor knop 1 (Start/Lap) timing
unsigned long knop1IngedruktTijd = 0;
bool knop1WasIngedrukt = false;
bool lapGeregistreerd = false;
const unsigned long langIndrukTijd = 2000; 

// Timer om het LCD-scherm niet onnodig vaak door te geven (voorkomt lag)
unsigned long laatsteSchermUpdate = 0;
const unsigned long schermInterval = 50; // Update scherm elke 50ms

void setup() {
  pinMode(knop1, INPUT);
  pinMode(knop2, INPUT);

  lcd.init();          
  lcd.backlight();     
  resetStopwatch();
}

void loop() {
  int status1 = digitalRead(knop1);
  int status2 = digitalRead(knop2);

  // BEIDE KNOPPEN TEGELIJK (RESET) (WERKT)
  if (status1 == HIGH && status2 == HIGH) {
    resetStopwatch();
    delay(500); // pauze (debounce)
    return; 
  }

  // KNOP 2 (PAUZE) (WERKT)
  if (status2 == HIGH && loopt) {
    loopt = false;
    gepauzeerdeTijd = millis() - startTijd;
    // Bereken de verstreken tijd: Actuele tijd van NU (millis) min de opgeslagen begintijd
    delay(200); // Korte debounce zodat hij direct reageert
  }

  //  KNOP 1 LOGICA (START & LAP) ---
  if (status1 == HIGH) {
    if (!knop1WasIngedrukt) {
      // Knop wordt NU net ingedrukt
      knop1IngedruktTijd = millis();
      knop1WasIngedrukt = true;
      lapGeregistreerd = false; // Reset de registratie
    } else {
      // Knop wordt ingehouden. Check of de 2 seconden voorbij zijn en we lopen
      if (loopt && !lapGeregistreerd && (millis() - knop1IngedruktTijd >= langIndrukTijd)) {
        lapTijd = millis() - startTijd;
        heeftLap = true;
        lapGeregistreerd = true; // Zorgt dat hij de lap maar één keer pakt per keer indrukken
        updateScherm();
      }
    }
  } 
  
  // Knop 1 wordt losgelaten
  if (status1 == LOW && knop1WasIngedrukt) {
    unsigned long indrukDuur = millis() - knop1IngedruktTijd;
    
    // Alleen starten als de knop KORT was ingedrukt én we nog niet geregistreerd hebben
    if (indrukDuur < langIndrukTijd && !lapGeregistreerd) {
      if (!loopt) {
        if (gepauzeerdeTijd > 0) {
          startTijd = millis() - gepauzeerdeTijd;
        } else {
          startTijd = millis();
        }
        loopt = true;
      }
    }
    knop1WasIngedrukt = false;
    delay(200); // Korte debounce
  }

  // Live de tijd bijwerken op het scherm (maar met een interval om haperingen te voorkomen)
  if (loopt) {
    verstrekenTijd = millis() - startTijd;
    if (millis() - laatsteSchermUpdate >= schermInterval) {
      updateScherm();
      laatsteSchermUpdate = millis();
    }
  }
}

// functie om resultaten op het scherm te tonen (WERKTTTTTTTT)
void updateScherm() {
  unsigned long totaleMilliSeconden = loopt ? verstrekenTijd : (gepauzeerdeTijd > 0 ? gepauzeerdeTijd : 0);
  
  unsigned long minuten = totaleMilliSeconden / 60000;
  unsigned long seconden = (totaleMilliSeconden % 60000) / 1000;
  unsigned long centiSeconden = (totaleMilliSeconden % 1000) / 10; 
  //berekeningen van minuten, secondes om vervolgens op het scherm te tonen

  // Rij 1: Live stopwatch tijd tonen
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  printNul(minuten); lcd.print(minuten); lcd.print(":");
  printNul(seconden); lcd.print(seconden); lcd.print(":");
  printNul(centiSeconden); lcd.print(centiSeconden);

  // Rij 2: Laptime tonen
  lcd.setCursor(0, 1);
  if (heeftLap) {
    unsigned long lapMin = lapTijd / 60000;
    unsigned long lapSec = (lapTijd % 60000) / 1000;
    unsigned long lapCent = (lapTijd % 1000) / 10;
    
    lcd.print("Lap : ");
    printNul(lapMin); lcd.print(lapMin); lcd.print(":");
    printNul(lapSec); lcd.print(lapSec); lcd.print(":");
    printNul(lapCent); lcd.print(lapCent);
  } else {
    lcd.print("Lap : --:--:--  ");
  }
}

void printNul(unsigned long getal) {
  if (getal < 10) {
    lcd.print("0");
  }
}

void resetStopwatch() {
  loopt = false;
  heeftLap = false;
  lapGeregistreerd = false;
  startTijd = 0;
  verstrekenTijd = 0;
  gepauzeerdeTijd = 0;
  lapTijd = 0;
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time: 00:00:00");
  lcd.setCursor(0, 1);
  lcd.print("Lap : --:--:--  ");
}