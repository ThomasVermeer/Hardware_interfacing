const int knopPin = 12;
const int led1 = 8;
const int led2 = 10;
// vaste (niet aan te passen) variabele aanmaken voor de pin die iets kan uitlezen en de pinnen naar de leds

const int denderDelay = 50; 

int knopStatus = 0;
int vorigeKnopStatus = 0;
int teller = 0;

//knop status bijhouden dus ingedrukt of niet en teller op 0 zetten

void setup() {
  
  pinMode(knopPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
}

// aangeven welke input en output zijn 12 word uitleesbaar, 8 en 10 stuurbaar

void leesKnop() {
  knopStatus = digitalRead(knopPin);
// uitlezen van status

  if (knopStatus == HIGH && vorigeKnopStatus == LOW) {
    
    
    teller++;
    
  
    delay(denderDelay); 
  }
// teller laten opstellen als de if statement klopt 
  
  vorigeKnopStatus = knopStatus;
}

void stuurLedsAan() {
  if (teller % 2 == 0) {
  
    digitalWrite(led1, LOW);   
    digitalWrite(led2, HIGH);  
  } else {
    
    digitalWrite(led1, HIGH);  
    digitalWrite(led2, LOW);   
  }
// hier rekenen met de teller checken of het getal wat er uit komt even of oneven is geef een knop aan of uit en dus het andere de andere reactie
}

void loop() {
  leesKnop();
  stuurLedsAan();
}