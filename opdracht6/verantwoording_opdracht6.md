# Opdracht 6: Stopwatch met een I2C LCD-scherm en twee drukknoppen

## 1. Opdrachtomschrijving

Bouw een schakeling en schrijf een programma waarmee je een I2C LCD aanstuurt, mede met twee knoppen.

- Het systeem moet een stopwatch nabootsen. Wordt er op de 1e knop geklikt, dan start de stopwatch met tellen. Wordt de 1e knop lang ( 2s ) ingedrukt, dan wordt de lap geregistreerd en weergegeven.
- Wordt er op de 2e knop geklikt, dan pauzeert het tellen.
- Worden deze 2 knoppen tegelijk ingedrukt, dan wordt de stopwatch en de laptime gereset.
- Gebruik de SDA en SCL poorten van de Arduino.
- Doe dus eerst onderzoek naar hoe de LCD werkt. Deze zit zowel in jouw kitje als op Tinkercad.

---

## 2. Analyse van Benodigdheden & Componentselectie

Gebruikte / benodigde componenten voor opdracht 6:

### Hardwarecomponenten

- **1x Arduino Uno R3:** De microcontroller die het programma uitvoert en de tijden berekent.
- **1x Breadboard:** Om de verbindingen tussen de knoppen en de Arduino te maken.
- **1x I2C LCD-scherm (16x2):** Het scherm waarop de live tijd en de laptime worden getoond via slechts twee datalijnen.
- **2x Drukknop (Push Button):** Knop 1 voor Start/Lap en Knop 2 voor Pauze.
- **2x Weerstand (10k Ohm):** Gebruikt als weerstand om een zwevende status op de digitale pinnen te voorkomen wanneer de knoppen niet zijn ingedrukt.
- **12x Jumper Wires (Draadjes):**
  - 2x draden vanaf de Arduino pinnen 13 en 12 naar de schakelkant van de drukknoppen.
  - 2x draden (SDA en SCL) vanaf de Arduino analoge pinnen A4 en A5 (of de speciale I2C-pinnen linksboven) naar de communicatiepinnen van het LCD-scherm.
  - 2x draden om de onderste plus- en minrail door te lussen naar de bovenste rails van het breadboard.
  - Voedingsdraden vanaf de Arduino 5V en GND naar de rails van het breadboard om zowel de knoppen als het scherm van spanning te voorzien.

---

## 3. Aansluitschema

## **screenshot van tinkercad meegeleverd in file opdracht6**

---

## 4. Broncode

## **.ino file meegeleverd in huidige map (opdracht6)**

### Stap voor stap werking:

- **De I2C-communicatie en Setup:** Bovenaan laden we Wire.h en LiquidCrystal_I2C.h in. Het scherm start op adres 0x20 met 16 kolommen en 2 rijen. In de setup() worden knoppen 12 en 13 als INPUT gezet. Daarna start lcd.init() het scherm en wist lcd.clear() het geheugen, zodat de basistekst (Time: 00:00:00) netjes in beeld springt.

- **De tijdsberekening met millis() - startTijd:** We gebruiken geen delay(), omdat de Arduino dan stopt met het uitlezen van de knoppen. In plaats daarvan gebruiken we millis(), een teller die vanaf het opstarten elke milliseconde bijhoudt. Bij de start slaan we de begintijd op in startTijd. De formule (millis() - startTijd) berekent live de verstreken tijd (NU min START). We gebruiken een unsigned long omdat dit een heel getal is dat nooit afrondingsfouten maakt (zoals een double) en groot genoeg is om dagen door te tellen.

- **De knoppenlogica en de Scherm-update:** De loop() checkt non-stop de knoppen. Om te zorgen dat het scherm niet flikkert en de processor stabiel blijft, ververst het LCD via schermInterval maar elke 50 milliseconden. Dit geeft ruimte om direct op de knoppen te reageren:
  1. **Beide knoppen hoog (Reset):** De stopwatch reset direct naar 0 en de boolean loopt gaat op false.
  2. **Knop 2 hoog (Pauze):** De klok stopt en de tijd bevriest in gepauzeerdeTijd om later weer vloeiend verder te kunnen tellen.
  3. **Knop 1 lang ingedrukt (>= 2s - Lap):** Als de knop langer dan 2 seconden wordt ingedrukt, bevriest de tussentijd op rij 2 via de vlag (lapGeregistreerd), terwijl de hoofdklok op rij 1 gewoon live doorloopt.

---

## 6. Verantwoording AI-gebruik

Bij deze stopwatch-opdracht is de functionele opzet zelfstandig ontworpen. Er is intensief gebruikgemaakt van de AI-tool Gemini (Google, 2026) voor het oplossen van een logisch herstart-probleem, schermstabilisatie en de uiteindelijke documentatiestructuur.

### Onderdeel 1: Schermstabilisatie tegen flikkeren (Lag)

In de eerste testfase werd de schermupdate continu aangeroepen, wat zorgde voor een flikkerend LCD-scherm og vertraging in de loop.

- **Gebruikte prompt:** Mijn I2C LCD-scherm flikkert heel erg als ik de stopwatch live update in de loop en de tijd loopt achter, hoe fix ik dit zonder delay?
- **Uitwerking:** De AI introduceerde het concept van een softwarematige timer met een interval (`schermInterval = 50`). Door de check `if (millis() - laatsteSchermUpdate >= schermInterval)` in te bouwen, wordt het scherm nu maximaal 20 keer per seconde ververst. Dit loste het flikkeren en de lag volledig op.

### Onderdeel 2: Logische structuur voor starten en hervatten (Knop 1 loslaten)

Bij het loslaten van Knop 1 moest de code bepalen of de stopwatch voor het eerst startte, of juist moest hervatten vanaf het exacte moment dat hij op pauze was gezet. Dit zorgde voor conflicten in de timing.

- **Gebruikte prompt:** Hoe kan ik bij het loslaten van knop 1 controleren of de knop kort is ingedrukt, en hoe zorg ik dat hij daarna correct verder telt vanaf de gepauzeerde tijd?
- **Uitwerking:** De AI gaf een logische suggestie om de `indrukDuur` te berekenen (`millis() - knop1IngedruktTijd`) en deze te vergelijken met `langIndrukTijd`. Daarnaast adviseerde de AI om een if-statement te gebruiken die controleert of `gepauzeerdeTijd > 0`. Als dat zo is, berekent de code de nieuwe starttijd als `millis() - gepauzeerdeTijd`. Deze aangedragen logische opzet is succesvol geïmplementeerd in de code. (dit is verteld in tekst ai heeft geen code gegeven omdat ik dat expliciet heb aangegeven)

### Onderdeel 3: Datatypes voor exacte tijdmeting

Er is advies gevraagd over het correct omrekenen van de totale milliseconden naar minuten, seconden en centiseconden om vreemde sprongen in de tijd te voorkomen.

- **Gebruikte prompt:** Welk datatype moet ik gebruiken voor de variabelen van de stopwatch om afrondingsfouten te voorkomen bij langdurig meten?
- **Uitwerking:** De AI adviseerde om consistent `unsigned long` te gebruiken voor alle tijdsindicatoren en comments toe te voegen bij de modulo-berekeningen (`% 60000`), wat de nauwkeurigheid van de live-weergave garandeert.

---

## 7. Bronnen

- **Tinkercad Kenniscentrum:** https://www.tinkercad.com/
- **Maker Guide:** https://www.makerguides.com/character-i2c-lcd-arduino-tutorial/
- **lastminuteengineers:** https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/
- **youtube tutorial** https://www.youtube.com/watch?v=-jiHul1kQh4

- Google. (2026). Gemini (Versie 1.5 Pro) [Large language model]. Geraadpleegd op 10 juni 2026, van https://gemini.google.com/
