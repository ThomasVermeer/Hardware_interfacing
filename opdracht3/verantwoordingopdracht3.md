# Opdracht 3: Schakelbaar looplicht met drukknop

## 1. Opdrachtomschrijving

- Sluit 2 LED’s aan op poort 8 en poort 10.
- Sluit een drukknop aan op poort 12.
- Laat de 1e LED aangaan door de druk op de knop, en weer uitgaan bij de volgende druk op dezelfde knop.
- De 2e LED moet altijd tegenovergesteld reageren (is LED 1 aan, dan is LED 2 uit, en andersom).

---

## 2. Analyse van Benodigdheden & Componentselectie

Gebruikte / benodigde componenten voor opdracht 3

### Hardwarecomponenten

- **1x Arduino Uno R3:**
- **1x Breadboard:**
- **2x LED:**
- **2x Weerstand (220 Ohm):** Voor de bescherming van de twee LED's.
- **1x Weerstand (10k Ohm):** Gebruikt als pull-down weerstand voor de drukknop.
- **1x Drukknop (Push Button):**
- **7x Jumper Wires (Draadjes):**
  - 2x draden vanaf Arduino pinnen 8 en 10 naar de lange (plus) poten van de LED's.
  - 1x draad vanaf Arduino pin 12 naar de schakelkant (kolom 26) van de drukknop.
  - 1x draad vanaf Arduino 5V -> Onderste Plus-strip (+).
  - 1x draad vanaf Arduino GND -> Onderste Min-strip (-).
  - 1x rode draad van de Plus-strip (+) naar de invoerkant (kolom 28) van de drukknop.
  - 1x korte verbindingsdraad om de min-strips door te lussen indien nodig.

---

## 3. Aansluitschema (Tinkercad)

## **screenshot van tinkercad meegeleverd in file opdracht3**

---

## 4. Broncode

## **.ino file meegeleverd in huidige map (opdracht3)**

---

## 5. Werking

De stroom loopt via de 5V naar de drukknop. Zodra de knop wordt ingedrukt, sluit de brug en meet de Arduino een stabiele spanning op pin 12. Om te voorkomen dat de pin gaat 'zweven' door statische elektriciteit wanneer de knop open is, trekt de 10k Ohm pull-down weerstand de pin direct naar de GND (0 Volt). We gebruiken functies (methodes) en een rekentruc (modulo) om de LED's netjes aan te sturen (het programmeur perspectief)

### Stap voor stap:

- **De setup (pinnen aanmaken):**
  Bovenaan maken we vaste constanten aan voor de pinnen van de knop (`12`), led1 (`8`), led2 (`10`) en de dender-delay (`50 ms`). In de `void setup()` worden de pinnen ingesteld als `INPUT` of `OUTPUT`. Daarnaast wordt de beginstatus bepaald: LED 1 start bewust op `LOW` (UIT) en LED 2 op `HIGH` (AAN), zodat ze direct tegenovergesteld van elkaar staan.

- **De knop uitlezen via een methode (`leesKnop`):**
  In de `void loop()` wordt als eerste de zelfgemaakte functie `leesKnop()` aangeroepen. De Arduino checkt de status van de knop. Er wordt gecontroleerd of de knop _nu_ ingedrukt is (`HIGH`), terwijl hij dat de vorige meetronde nog _niet_ was (`LOW`). Als dat zo is, wordt er in het geheugen 1 opgeteld bij de variabele `teller` (`teller++`). Er wordt direct een delay van 50 ms ingelast om 'contactdender' (het trillen van de knop) te negeren. Aan het einde wordt de huidige status opgeslagen als de `vorigeKnopStatus`.

- **De LED's aansturen via een methode (`stuurLedsAan`):**
  Als tweede wordt de functie `stuurLedsAan()` uitgevoerd. Hierin zit de rekenkundige truc met modulo (`% 2`). De Arduino deelt de huidige stand van de teller door 2 dan word er gekeken naar wat er overblijft (het restant).
  - **Even getal (Rest is 0):** Kan het getal perfect door 2 gedeeld worden (zoals bij de start op 0, of na 2, 4, 1000 keer drukken)? Dan stuurt de Arduino LED 1 op `LOW` (UIT) en LED 2 op `HIGH` (AAN).
  - **Oneven getal (Rest is 1):** Blijft er na de deling 1 over (zoals na 1, 3, 5, 999 keer drukken)? Dan springen de lampjes om: LED 1 gaat op `HIGH` (AAN) en LED 2 op `LOW` (UIT).

- **De herhaling:**
  Omdat deze twee methodes in de `void loop()` staan, blijft de Arduino dit duizenden keren per seconde herhalen. Hierdoor reageren de lampjes direct, vloeiend en altijd exact tegenovergesteld van elkaar zodra je op de knop drukt.
