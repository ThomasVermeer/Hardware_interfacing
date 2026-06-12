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

## 6. Verantwoording AI-gebruik

De Arduino-code voor het Knight Rider looplicht is volledig zelfstandig en zonder hulp van AI-tools ontworpen en geschreven, aangezien de logica gebaseerd is op standaard basistellers (for-loops) die handmatig zijn opgezet. Er is uitsluitend gebruikgemaakt van de AI-tool Gemini (Google, 2026) voor ondersteunende taken rondom de documentatie en opmaak van dit verslag.

### Onderdeel 1: Componentenlijst genereren

Op basis van de zelfgebouwde Tinkercad-opstelling is hulp gevraagd om de onderdelen snel en overzichtelijk onder elkaar te zetten.

- **Gebruikte prompt:** er moet bij de verantwoording een lijst met de gebruikte componenten geef mij deze lijst
- **Uitwerking:** De AI heeft de componenten op basis van de visuele opstelling dit omgezet in een overzichtelijke opsomming voor paragraaf 2.

### Onderdeel 2: Markdown-opmaak en structuur

De tool is puur als digitale tekstverwerker gebruikt om de zelfgeschreven uitleg over de werking (het heen en weer lopen van de lichten) netjes te formatteren met koppen en opsommingstekens.

- **Gebruikte prompt:** [De opzet van de tekst en code ingevoerd met de opmerking:] dit is de hele verantwoording, dit is de code ik denk eerlijk gezegd dat we hier ook niet iets over ai gebruik van de code hoeven te doen is makkelijk genoeg
- **Uitwerking:** De AI heeft de eigen invoer omgezet naar een overzichtelijk gestructureerd Markdown-blok, zonder wijzigingen aan te brengen in de programmacode of de logica van de werking.

---

## 7. Bronnen

- **Tinkercad Kenniscentrum:** https://www.tinkercad.com/
- Google. (2026). Gemini (Versie 1.5 Pro) [Large language model]. Geraadpleegd op 12 juni 2026, van https://gemini.google.com/
