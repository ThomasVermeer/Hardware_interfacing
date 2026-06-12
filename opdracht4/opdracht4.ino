const int potPin = A5;   // Potmeter vast instellen op de poort waar de analoge kabel ingaat
const int eersteLed = 8; // Eerste LED vaststellen op pin 8 (dus geef aan welke de eerste is zodat je hiermee kan rekenen)
const int laatsteLed = 13;// Laatste LED vaststellen op pin 13 (het einde waarmee dus gerekend kan worden)

int potmeterWaardeOutput = 0;
int aantalLedsBrandend = 0;   // Variabele voor hoeveel LED's er moeten branden

void setup() {
  // uit luiheid inplaats van individueel voor elk lampje te zeggen output gebruik ik hier een rekensommetje die zegt begin bij led 1 zolang hij kleiner is dan getal van laatste let
  //tel 1 bij getal eersteLed op en zet hem met output correct (dus als er 100 letjes zouden zijn hoeft alleen laatsteled veranderd te worden naar het getal van de laatste
  for (int i = eersteLed; i <= laatsteLed; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // haal de output waarde van die potmeter er uit en lees het (analogRead) analoog lees letterlijk vertaald
  potmeterWaardeOutput = analogRead(potPin);

 
  // map functie gebruiken eerste 0 geeft aan wat de minimale output is van potmeter 2e getal maximale waarde de 6 is het aantal lampjes
  // hij verdeelt 1023 in 6 stukken want je zegt bij de minimale output staan er 6 lampen aan bij max input staan er 0 aan
  aantalLedsBrandend = map(potmeterWaardeOutput, 0, 1023, 6, 0);

// om bug te voorkomen dat lamp 1 altijd brand
  if (potmeterWaardeOutput > 1010) {
  aantalLedsBrandend = 0;
}

  // stuur de leds aan met een for loop door het rekensommetje steeds optellen zolang hij kleiner is
  for (int i = 0; i < 6; i++) {
    // als getal van pin lager is dan aantal wat aan moet staan (zet aan of uit)
    if (i < aantalLedsBrandend) {
      digitalWrite(eersteLed + i, HIGH); // Zet de LED aan
    } else {
      digitalWrite(eersteLed + i, LOW);  // Zet de LED uit
    }
  }
}