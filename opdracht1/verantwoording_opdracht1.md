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

## 6. Verantwoording AI-gebruik

Bij het opstellen en structureren van deze verantwoording is gebruikgemaakt van de AI-tool Gemini (Google, 2026). De AI is uitsluitend ingezet voor de opmaak, ordening en het omzetten van de eigen invoer naar Markdown-formaat volgens de schoolrichtlijnen.

### Onderdeel 1: Componentenlijst genereren

Op basis van de zelfgebouwde Tinkercad-opstelling is hulp gevraagd om de onderdelen snel en overzichtelijk onder elkaar te zetten.

- **Gebruikte prompt:** er moet bij de verantwoording een lijst met de gebruikte componenten geef mij deze lijst
- **Uitwerking:** De AI heeft de componenten op basis van de visuele opstelling dit omgezet in een overzichtelijke opsomming voor paragraaf 2.

### Onderdeel 2: Markdown-opmaak en structuur

Om de eigen geschreven werking en tekst netjes te formatteren voor het inleverdossier, is de tool gebruikt als tekstverwerker.

- **Gebruikte prompt:** dit is mijn verantwoording van opdracht 1 zet dit netjes in markdown
- **Uitwerking:** De AI heeft de ruwe tekst gestructureerd met koppen, scheidingslijnen og opsommingstekens zonder nieuwe inhoudelijke stappen aan de werking toe te voegen.

## 7. Bronnen

- **Tinkercad Kenniscentrum:** https://www.tinkercad.com/
- Google. (2026). Gemini (Versie 1.5 Pro) [Large language model]. Geraadpleegd op 4 juni 2026, van https://gemini.google.com/
