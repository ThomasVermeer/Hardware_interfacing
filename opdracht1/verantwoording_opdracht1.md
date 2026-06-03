# Opdracht 1: LED's om en om laten knipperen

## 1. Opdrachtomschrijving

- Sluit 2 LED’s aan op poort 10 en 13.
- Laat de LED’s om en om knipperen (1.5s / 1.5s).
- Eerst Sketch maken.
- Dan Tinkeren en testen.
- Dan opbouwen en testen.

## 2. Analyse van Benodigdheden & Componentselectie

gebruikte / benodigde componenten voor opdracht 1

### Hardwarecomponenten

- **1x Arduino Uno R3:**
- **1x Breadboard:**
- **2x LED (Rood):**
- **2x Weerstand (220 Ohm):**
- **5x Jumper Wires (Draadjes):**
  - 1x draad van Arduino Pin 10 -> Kolom 11 (Plus-poot LED 2)
  - 1x draad van Arduino GND -> Onderste Min-strip (-)
  - 2x Verbindingsdraden aan de linkerkant om de onderste Min-strip (-) door te lussen naar de bovenste Min-strip (-), zodat beide weerstanden met de Ground (GND) verbonden zijn.

---

## 3. Aansluitschema (Tinkercad)

## **screenshot van tinkercad meegeleverd in file opdracht1**

## 4. Broncode

## **.ino file meegeleverd in huidige map (opdracht1)**

## 5. werking

## 5. Werking (Software & Stroomloop)

- **LED 13 gaat aan:**
  De code zet poort 13 op `HIGH` (5 Volt). De stroom loopt via de groene draad naar de eerste LED. Via de weerstand en de min-strip loopt de stroom terug naar de GND van de Arduino. Door `delay(1500);` blijft dit lampje 1,5 seconde branden.

- **De wissel:**
  De code zet poort 13 op `LOW` (0 Volt), waardoor de eerste LED uitgaat. Meteen daarna wordt poort 10 `HIGH` gemaakt. De stroom loopt nu via de andere groene draad door de tweede LED en de weerstand naar de GND. Dit lampje blijft door de tweede delay ook 1,5 seconde branden.

- **De herhaling:**
  Aan het einde gaat poort 10 op `LOW`. Omdat de code in een `loop` staat, begint het programma direct weer helemaal bovenaan bij stap 1. In Tinkercad werkt dit prima om ze om en om te laten knipperen.
