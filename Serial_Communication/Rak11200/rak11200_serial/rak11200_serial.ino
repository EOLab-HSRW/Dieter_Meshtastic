void setup() {
    Serial.begin(115200);  // Serial Monitor
    Serial1.begin(115200); // UART an RAK4630

    Serial.println("RAK11200 bereit. Sende Daten an RAK4630...");
}

void loop() {
    int randomValue = random(0, 100);  // Zufallswert (0 - 99)
    
    Serial1.println(randomValue);  // Senden an RAK4630
    Serial.print("Gesendet: ");
    Serial.println(randomValue);
    
    delay(500);  // Kurze Pause für Stabilität

    // Antwort vom RAK4630 lesen
    if (Serial1.available()) {
        String response = Serial1.readStringUntil('\n');
        Serial.print("Empfangen: ");
        Serial.println(response);
    }

    delay(2000);  // Wartezeit für nächsten Durchgang
}
