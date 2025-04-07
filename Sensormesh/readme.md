# Software Documentation

## Serial Connection from RAK11200 to RAK4631

Establishing UART communication between RAK11200 and RAK4631:

1. Ensure pinheaders are soldered if necessary for connecting RAK11200 and RAK4631.
2. Use `Serial` for monitor connection and `Serial1` for device-to-device communication via RX/TX.
3. Configure Meshtastic on RAK4631 to receive and process data forwarded from RAK11200.

---

## Configuration of Meshtastic on RAK4631

Setting up Meshtastic on RAK4631 involves the following steps:

1. Flash the Meshtastic firmware onto RAK4631 using the [Meshtastic Flasher](https://flasher.meshtastic.org/).
2. Configure channels, encryption, and enable serial communication on nodes.
3. Enable MQTT with default settings and JSON format across all nodes.
4. Enable Wi-Fi on RAK13300 for MQTT connection, noting the loss of BLE capability afterward.
5. Verify connectivity and data transmission using MQTT Client Desktop App.

**Note:** Use UART1 (pins 14 and 13) for serial communication as per Meshtastic application requirements.

---

## Connection to the Gateway RAK11200 + RAK13300

Connecting RAK11200 and RAK13300 for data forwarding:

1. Flash RAK11200 with Meshtastic firmware.
2. Initially configure RAK11200 via BLE for MQTT, then switch to Wi-Fi.
3. Configure nodes with correct frequencies and enable serial communication on the first node.
4. Connect RAK11200 to MQTT broker on Meshtastic public network via Wi-Fi.
5. Test MQTT connection and verify data transmission to the specified topic.

---

## Alternative Way of Connection via LoRaWAN Gateway

### Initialization of the Gateway via AT Commands RAK11300

Initialize RAK11300 LoRaWAN gateway using AT commands:

1. Connect to RAK11300 via serial communication.
2. Test connection with basic command `AT`.
3. Configure network parameters (e.g., OTAA or ABP) via serial monitor in Arduino IDE.
4. Set join parameters and test network connection.
5. Verify connectivity and data transmission using the designated network console.

---

### Links

- [RAK19007 Datasheet](https://docs.rakwireless.com/product-categories/wisblock/rak19007/datasheet/)
- [RAK11300 Datasheet](https://docs.rakwireless.com/product-categories/wisduo/rak11300-module/datasheet/)
- [RAK13300 Datasheet](https://docs.rakwireless.com/product-categories/wisblock/rak13300/datasheet/)
