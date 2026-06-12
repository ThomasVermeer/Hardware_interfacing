# Opdracht 5: Servomotor aansturen met twee drukknoppen

## 1. Opdrachtomschrijving

• Op de Arduino zijn 2 drukknoppen aangesloten.
• Zolang op drukknop 1 wordt gedrukt draait een servomotor van 0° naar 120° in 5s. Als de servomotor zijn uiterste stand heeft bereikt dan moet hij terugdraaien, ook in 5s.
• Zolang op drukknop 2 wordt gedrukt draait een servomotor van 0° naar 120° in 0,5s. Als de servomotor zijn uiterste stand heeft bereikt dan moet hij terugdraaien, ook in 0,5s.
• Worden beide drukknoppen tegelijk ingedrukt, dan zal de servomotor in 5s van 0° naar 120° draaien, 2s zo blijven staan en vervolgens in 0.5s terugdraaien naar 0°.
• De beweging van de servomotor dient in één functie / methode te zijn ontworpen.
• Ingangen en uitgangen zijn vrij te kiezen.

---

## 2. Analyse van Benodigdheden & Componentselectie

Gebruikte / benodigde componenten voor opdracht 5

### Hardwarecomponenten

- **1x Arduino Uno R3:**
- **1x Breadboard:**
- **1x Servomotor (Propellor):** De motor die we in exacte graden (0° tot 120°) kunnen aansturen.
- **2x Drukknop (Push Button):**
- **2x Weerstand (10k Ohm):** Gebruikt als pull-down weerstanden om te zorgen dat de pinnen 12 en 13 niet gaan 'zweven' als de knoppen open zijn.
- **8x Jumper Wires (Draadjes):**
  - 2x draden vanaf Arduino pinnen 13 en 12 naar de schakelkant van de drukknoppen.
  - 1x draad vanaf Arduino PWM-pin 3 naar de signaaldraad (oranje/geel) van de servomotor.
  - 1x draad vanaf Arduino 5V -> Plus-strip (+) voor de knoppen en de rode voedingsdraad van de servo.
  - 1x draad vanaf Arduino GND -> Min-strip (-) voor de pull-down weerstanden en de bruine/zwarte gnd-draad van de servo.

---

## 3. Aansluitschema (Tinkercad)

## **screenshot van tinkercad meegeleverd in file opdracht5**

---

## 4. Broncode

## **.ino file meegeleverd in huidige map (opdracht5)**

---

## 5. Werking

Een servomotor werkt op basis van graden. Omdat een servo normaal gesproken direct naar een hoek toe schiet, moeten we de vertraging (5s of 0,5s) softwarematig manipuleren. Dit doen we door de servo (1 graad per keer) te verplaatsen met een pauze ertussen die we hebben ingesteld (want zoals word verwacht kijken we vanuit een programmeur perspectief).

We sluiten de propellor specifiek aan op poort 3 omdat dit een PWM-pin met een golfje is. Een servo luistert namelijk naar de exacte lengte van een stroompulsje. Dankzij dit PWM-kanaal gebruikt de Arduino zijn ingebouwde hardware-timers om deze pulsjes nauwkeurig te versturen.

### Stap voor stap:

- **De setup & de CSS-reset van de Servo:**
  Bovenaan laden we de Servo.h bibliotheek in en maken we het servo-object aan onder de eigen naam propellor. We stellen de pinnen voor de knoppen in als INPUT en koppelen de signaaldraad via propellor.attach(3) aan de motorpoort.

  In de void setup() dwingen we de motor ook om direct naar de startpositie te gaan via propellor.write(0). Dit fungeertfunctioneerd als een soort CSS-reset (zoals margin 0 in een stylesheet) (ja ik heb dit uitgezocht want blijkbaar start de propellor op negative graden ofzo als je hem op 0 zet draait hij al iets)(heeft geen bijzondere impact wel grappig om te onderzoeken)

- **De methode aansturenServo:**
  Om te voldoen aan de harde eis dat de hele beweging in één functie moet staan, heb ik de methode aansturenServo(duurHeenweg, pauzeTijd, duurTerugweg) gebouwd. Deze functie accepteert drie tijden in milliseconden.
  - **Heenweg:** Een for-loop telt van 0 naar 120 graden. De Arduino berekent zelf de pauze per graad door de totale duurHeenweg te delen door 120 stapjes. Bij 5 seconden (5000ms) wacht hij 41ms per graad. Bij 0,5 seconde (500ms) wacht hij slechts 4ms per graad, waardoor hij snel draait.
  - **Pauze:** Er wordt gecontroleerd of er een pauzetijd is meegegeven via een if-statement. Als dat zo is (zoals de vereiste 2 seconden bij beide knoppen), blijft de propellor daar even strak stilstaan via een normale delay().
  - **Terugweg:** Een tweede for-loop telt weer netjes achteruit van 120 naar 0 graden met zijn eigen berekende snelheid door de duurTerugweg te delen door 120.

- **De logica in de void loop():**
  De Arduino leest continu de status van knopLinks (pin 13) en knopRechts (pin 12) uit. Vervolgens filtert een if / else if structuur exact de drie gevraagde situaties uit:
  1. **Beide knoppen ingedrukt:** De Arduino roept de functie aan met de parameters (5000, 2000, 500). De servo doet er 5s over heen, wacht 2s, en sjeest in 0,5s terug.
  2. **Alleen links ingedrukt:** De functie krijgt (5000, 0, 5000) mee. De servo gaat in 5s heen en direct in 5s weer terug.
  3. **Alleen rechts ingedrukt:** De functie krijgt (500, 0, 500) mee. De servo gaat supersnel (0,5s) heen en direct weer terug (0,5s).

- **De herhaling:**
  Omdat dit proces zich non-stop herhaalt in de void loop(), reageert de propellor direct en vloeiend zodra een van de knoppencombinaties op het breadboard wordt geactiveerd.

## 6. Verantwoording AI-gebruik

Bij deze opdracht is de basisstructuur zelfstandig opgezet. Er is gebruikgemaakt van de AI-tool Gemini (Google, 2026) om te brainstormen over de datastructuur, het oplossen van een logische fout in de loop en voor de opmaak van de documentatie.

### Onderdeel 1: Variabelennamen en datastructuur

Om te voldoen aan de eis dat de hele beweging in één functie moest staan, is eerst advies gevraagd over hoe de gegevens rondom de timing het beste bijgehouden konden worden.

- **Gebruikte prompt:** Zou je mij suggesties kunnen geven hoe we het kunnen doen met gegevens bijhouden, dus welke data handig is om op te slaan of bij te houden?
- **Uitwerking:** De AI heeft meegedacht over de variabelennamen om de structuur overzichtelijk te houden en stelde voor om met parameters binnen de functie te werken, zoals `duurHeenweg`, `pauzeTijd` en `duurTerugweg`. Hierdoor konden de delays per graad (zoals `delayHeen`) berekend worden.

### Onderdeel 2: Foutoplossing (Code werkt maar één keer)

Tijdens het testen bleek dat de code na het indrukken van een knop de beweging keurig uitvoerde, maar daarna niet meer reageerde op nieuwe knoppen.

- **Gebruikte prompt:** Ik heb het getest en het werkt maar 1 keer [gevolgd door de opzet van de code], is het mogelijk om er voor te zorgen dat als het klaar is het nog steeds werkt?
- **Uitwerking:** De AI wees mij erop dat de knoppenchecks per ongeluk buiten de herhaling stonden. De tool adviseerde om de digitale metingen (`digitalRead`) en de bijbehorende `if / else if` statements expliciet toe te voegen aan de `void loop()`. Na deze aanpassing bleef de Arduino live luisteren en werkte het systeem continu.

### Onderdeel 3: Componentenlijst en Markdown-structuur

De tool is ingezet als tekstverwerker om de hardwareonderdelen te ordenen op basis van de Tinkercad-opstelling en de ruwe tekst te voorzien van de juiste Markdown-opmaak.

---

## 7. Bronnen

- **Tinkercad Kenniscentrum:** https://www.tinkercad.com/
- **Arduino Officiële Documentatie (Servo Bibliotheek):** https://www.arduino.cc/reference/en/libraries/servo/
- Google. (2026). Gemini (Versie 1.5 Pro) [Large language model]. Geraadpleegd op 10 juni 2026, van https://gemini.google.com/
