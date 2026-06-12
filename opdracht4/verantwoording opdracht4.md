# Opdracht 4: Analoge LED-aansturing met potmeter

## 1. Opdrachtomschrijving

- Sluit 6 LED’s aan op de digitale poorten 8 tot en met 13.
- Sluit een potmeter (regelbare weerstand) aan op de analoge ingang A5.
- Maak gebruik van voorschakelweerstanden voor de bescherming van de LED's.
- Stuur de LED's aan op basis van de hoekverdraaiing van de potmeter.
- Eis: Hoe verder je de knop naar rechts (richting de maximale waarde 1023) draait, hoe meer LED’s er uit moeten gaan.

---

## 2. Analyse van Benodigdheden & Componentselectie

Gebruikte / benodigde componenten voor opdracht 4

### Hardwarecomponenten

- **1x Arduino Uno R3:**
- **1x Breadboard:**
- **6x LED:**
- **6x Weerstand (220 Ohm):** Voor de bescherming van de zes LED's.
- **1x Potmeter (Potentiometer):** De regelbare weerstand om de spanning tussen 0 en 5 Volt aan te passen.
- **11x Jumper Wires (Draadjes):**
  - 6x draden vanaf Arduino pinnen 8 tot en met 13 naar de lange (plus) poten van de LED's.
  - 1x draad vanaf Arduino analoge pin A5 naar de middelste poot (de loper/signaalpoot) van de potmeter.
  - 1x draad vanaf Arduino 5V -> Onderste Plus-strip (+), verbonden met de buitenste poot van de potmeter.
  - 1x draad vanaf Arduino GND -> Onderste Min-strip (-), verbonden met de andere buitenste poot van de potmeter.
  - 6x korte verbindingen vanaf de korte (min) poten van de LED's via de weerstanden naar de Min-strip (-).

---

## 3. Aansluitschema (Tinkercad)

## **screenshot van tinkercad meegeleverd in file opdracht4**

---

## 4. Broncode

## **.ino file meegeleverd in huidige map (opdracht4)**

---

## 5. Werking

De potmeter werkt als een spanningsdeler. Door aan de knop te draaien verandert de mechanische weerstand, waardoor het voltage op de analoge pin A5 varieert tussen de 0 en 5 Volt. echt analoog kan niet dus Arduino vertaalt / simuleert een digitaal getal tussen de 0 en 1023. We gebruiken een map() functie en for-loops om op basis van deze waarde de LED's aan te sturen. zoals werd gevraagd: als programmeur dus niet een stroomkring verbreken om het zelfde resultaat te krijgen.

### Stap voor stap:

- **De setup (pinnen aanmaken):**
  Bovenaan maken we constanten aan (kan niet veranderen) voor de analoge pin van de potmeter A5, de eerste LED 8 en de laatste LED 13. In de void setup() gebruiken we uit luiheid een for-loop in plaats van elk lampje apart te definiëren. Deze loop start bij pin 8 en herhaalt zich zolang de teller kleiner of gelijk is aan pin 13
  i <= laatsteLed. Bij elke stap wordt de pin ingesteld als OUTPUT. Hierdoor is de code direct en makkelijk te wijzigen/aan te passen als er 100 LED's zouden zijn, hoeft alleen het getal van de laatste LED aangepast te worden.

- **De potmeter uitlezen (analogRead):**
  Aan het begin van de void loop() haalt de Arduino de actuele waarde van de potmeter op met de functie analogRead(potPin). Dit getal wordt direct opgeslagen in de variabele potmeterWaardeOutput. Omdat de loop duizenden keren per seconde herhaalt, blijft Arduino het live bijhouden.

- **De waardes omrekenen met de `map()` functie:**
  De Arduino moet de range van de potmeter (0 tot 1023) koppelen aan het aantal LED's dat moet branden (6 tot 0). De regel map(potmeterWaardeOutput, 0, 1023, 6, 0)
  verdeelt de 1023 stappen in 6 gelijke stukken van ongeveer 170 stappen per stuk.
  - **Knop helemaal links (0):** De map-functie geeft aan dat er **6** lampen aan moeten staan.
  - **Knop in het midden (ongeveer 512):** De map-functie berekent dat er nog **3** lampen aan moeten staan.
  - **Knop helemaal rechts (1023):** De map-functie zorgt dat er **0** lampen aan staan (allemaal uit).
    De uitkomst hiervan wordt opgeslagen in aantalLedsBrandend.

- **De LED's updaten via een `for`-loop:**
  Als laatste stap start er een for-loop die telt van 0 tot en met 5 (voor de 6 lampjes). Bij elk stapje controleert een if-statement of de huidige index i kleiner is dan het berekende aantalLedsBrandend.
  - Is de index **kleiner**, dan stuurt de Arduino de bijbehorende pin eersteLed + i naar HIGH (AAN).
  - Is de index **groter of gelijk**, dan schiet de code in de else en gaat de LED naar LOW (UIT).

- **De herhaling:**
  Omdat dit hele proces zich non-stop herhaalt in de void loop(), reageren de lampjes direct en vloeiend op elke millimeter die jij de potmeterknop naar rechts of links draait.

  ## 6. Verantwoording AI-gebruik

  De functionele broncode voor deze analoge LED-aansturing is volledig zelfstandig en zonder de hulp van AI-tools ontworpen, geschreven en gecorrigeerd. De logica rondom het inlezen van de potmeter, het toevoegen van het if-statement tegen de reststroom en het aansturen van de LED-pinnen is zelf opgebouwd. Er is alleen gebruikgemaakt van de AI-tool Gemini (Google, 2026) voor ondersteunende taken bij de opmaak van de documentatie.

### Onderdeel 1: Componentenlijst genereren

Op basis van de zelfgebouwde Tinkercad-opstelling is de AI gevraagd om de fysieke onderdelen en de verbindingsdraadjes snel en overzichtelijk onder elkaar te zetten.

- **Gebruikte prompt:** [De opzet van de tekst en code ingevoerd en screenshot van tinkercad ontwerp voor opdracht 4] geef mij de lijst van de hardware components
- **Uitwerking:** De AI heeft de hardware-onderdelen uit de opstelling gestructureerd en omgezet in de opsomming die te vinden is onder paragraaf 2.

### Onderdeel 2: Markdown-opmaak en structuur

De tool is puur als digitale tekstverwerker gebruikt om de zelfgeschreven uitleg over de werking (zoals de analogRead, de map-functie en de rekenkundige stappen in de for-loop) netjes te formatteren met koppen en opsommingstekens op de plekken waar nodig.

- **Gebruikte prompt:** [De opzet van de tekst en code ingevoerd voor opdracht 4]
- **Uitwerking:** De AI heeft de eigen invoer omgezet naar een overzichtelijk en scannbaar Markdown-blok, zonder wijzigingen of inhoudelijke aanvullingen aan te brengen in de programmacode of de werking.

---

## 7. Bronnen

- **Tinkercad Kenniscentrum:** https://www.tinkercad.com/
- Google. (2026). Gemini (Versie 1.5 Pro) [Large language model]. Geraadpleegd op 10 juni 2026, van https://gemini.google.com/
