# Opdracht 2: Knight Rider looplicht

## 1. Opdrachtomschrijving

- Sluit 8 LED’s aan op externe poorten.
- Laat de LED’s heen en weer lopen volgens deze link: Knight Rider (2018) Official Fan Movie Trailer [HD] New Movie Teaser.
- Eerst een Sketch maken, dan Tinkeren en daarna testen.
- Als laatste opbouwen en testen.

## 2. Analyse van Benodigdheden & Componentselectie

gebruikte / benodigde componenten voor opdracht 2

### Hardwarecomponenten

- **1x Arduino Uno R3:**
- **1x Breadboard:**
- **8x LED (Rood):**
- **8x Weerstand (220 Ohm):**
- **11x Jumper Wires (Draadjes):**
  - 8x draden vanaf Arduino pinnen 6 tot en met 13 naar de plus-poten van de LED's.
  - 1x draad van Arduino GND -> Onderste Min-strip (-).
  - 2x Verbindingsdraden aan de linkerkant om de onderste Min-strip (-) door te lussen naar de bovenste Min-strip (-), zodat alle 8 de weerstanden geconnect zijn met de Ground (GND).

---

## 3. Aansluitschema (Tinkercad)

## **screenshot van tinkercad meegeleverd in file opdracht2**

---

## 4. Broncode

## **.ino file meegeleverd in huidige map (opdracht2)**

---

## 5. Werking

De stroom loopt altijd vanuit de Arduino-poort die op `HIGH` wordt gezet, door de LED en de weerstand heen, naar de GND (min). In deze opdracht gebruiken we constanten en `for`-loops om dit simpel aan te sturen.

### Stap voor stap:

- **De setup (pinnen aanmaken):**
  Bovenaan maken we constanten aan voor de eerste pin (`6`), de laatste pin (`13`) en de wachttijd (`100 ms`). In de `void setup()` zorgt een `for`-loop ervoor dat de teller `i` oploopt van 6 naar 13. Zo worden alle 8 de pinnen in één klap ingesteld als `OUTPUT`.

- **Heen bewegen (van rechts naar links):**
  In de `void loop()` start de eerste `for`-loop. De teller `i` begint bij 6 (`firstPin`) en telt elke stap eentje op met `i++` tot hij bij 13 (`lastPin`) is. De code zet de huidige pin op `HIGH`, wacht 100 milliseconden en zet hem weer op `LOW`. Het licht schuift zo op naar links.

- **Terug bewegen (van links naar rechts):**
  De tweede `for`-loop doet precies het omgekeerde om de lichtjes terug te laten bewegen. De teller begint nu bovenaan bij 13 (`lastPin`) en telt met `i--` telkens eentje af totdat hij onderaan bij pin 6 (`firstPin`) is. De lampjes gaan zo in omgekeerde volgorde achter elkaar aan en uit.

- **De herhaling:**
  Als de tweede loop klaar is, begint de `void loop()` direct weer helemaal bovenaan bij stap 1 (pin 6). Dit blijft zich oneindig herhalen, waardoor de lampjes constant heen en weer lopen.
