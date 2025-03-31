#include <Wire.h>

void setup()
{
    time_t timeout = millis();
    Serial.begin(115200); // Debug-Serielle Schnittstelle
    while (!Serial)
    {
        if ((millis() - timeout) < 5000)
        {
            delay(100);
        }
        else
        {
            break;
        }
    }

    Serial.println("================================");
    Serial.println("RAK4630 Meshtastic Forwarding!");
    Serial.println("================================");

    Serial1.begin(115200); // UART zum RAK11200
}

void loop()
{
    if (Serial1.available())  // Daten vom RAK11200 empfangen
    {
        String msg = "";
        while (Serial1.available())
        {
            char c = Serial1.read();
            msg += c;
            delay(2); // Kurze Pause für vollständige Nachricht
        }

        Serial.print("Empfangen: ");
        Serial.println(msg);

        // Meshtastic-AT-Befehl zum Senden der Nachricht
        String atCommand = "AT+SEND=" + msg + "\r\n";  
        Serial1.print(atCommand);  // An Meshtastic senden
        Serial.print("Gesendet: ");
        Serial.println(atCommand);
    }
}
