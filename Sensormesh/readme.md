# Software Documentation

## Content

- [Main Tasks](#main-tasks)
- [Sensor Data Gathering RAK11200](#sensor-data-gathering-rak11200)
- [Serial Connection from RAK11200 to RAK4631](#serial-connection-from-rak11200-to-rak4631)
- [Configuration of Meshtastic on RAK4631](#configuration-of-meshtastic-on-rak4631)
- [Initialization of the Gateway via AT Commands RAK11300](#initialization-of-the-gateway-via-at-commands-rak11300)
- [Connection to the Gateway RAK11200 + RAK13300](#connection-to-the-gateway-rak11200--rak13300)

---

## Main Tasks

1. Gathering the sensor data.
2. Sending data through serial communication.
3. Forwarding data to the mesh network.
4. Forwarding data from the mesh network to the MQTT broker.

---

## Sensor Data Gathering RAK11200

1. Start by connecting the RAK Sensor 1906 properly to the RAK11200 as documented.
2. Use the provided library from the manufacturer to gather values from the sensor.
3. Convert the values to strings to prepare them for serial transmission.

---

## Serial Connection from RAK11200 to RAK4631

1. Ensure proper soldering of pin headers if necessary to connect RAK11200 and RAK4631 via their GND, RX, and TX pins. For RAK11200, enable sketch uploading via reset by connecting BOOT0 to GND.
2. Keep in mind when coding:

1. BLE connection to the node receiving serial data.
2. Navigate to **Device Settings** > **Serial** in **Module Settings**.
3. Enable and set **RX** to `14` and **TX** to `13`.
4. Set baud rate to `115200`.
5. Save changes for automatic reconnection.

**Note:** Use `Serial` for monitoring via computer and `Serial1` for RX/TX communication between devices.
   Forwarding serial data from RAK11200 to Meshtastic network on RAK4631 can be achieved by:

---

## Configuration of Meshtastic on RAK4631

1. Flash Meshtastic firmware on RAK4631 using [Meshtastic Flasher](https://flasher.meshtastic.org/).
2. Configure necessary settings like channel encryption. Important: Enable serial on the first node with RX/TX connected to RAK11200.
3. Enable MQTT and configure on each node. Defaults are acceptable; disable encryption and enable JSON.
4. On the last Meshnode (RAK11200 + RAK13300), enable WiFi. (steps further listed below in the section "Connection to the Gateway RAK11200 + RAK13300")
5. Verify operation with MQTT client desktop app.
6. Utilize web client on RAK11200 combined with 13300. (Select web UI option during firmware generation.)

**Important Note:** Internal serial communication pins are UART0 (pins 9, 10) and UART1 (pins 33, 34) in datasheet; Meshtastic uses UART1 (pins 14, 13).

---

## Connection to the Gateway RAK11200 + RAK13300

1. Flash RAK11200 firmware from Meshtastic flasher.
2. Initially configure RAK11200 via BLE for MQTT, then switch to WiFi to retain BLE connection using RAK device web client.
3. Ensure correct frequency configuration across nodes; enable serial on first node with RX/TX.
4. Configure RAK11200 endpoint to connect to MQTT broker on Meshtastic public network via WiFi.
5. Obtain IP (e.g., 192.168.2.174) from Arduino serial output, access via browser.
6. Set up endpoint channel, enable bidirectional forwarding with MQTT.
7. Test messaging, verify output.
8. Name broker topic for testing.
9. Connect to public broker with MQTT client desktop app.
10. Access configuration from RAK11200 web client.

---

## Alternative Way of Connection via LoRaWAN Gateway

### Initialization of the Gateway via AT Commands RAK11300

Initialize RAK11300 gateway with AT commands:

1. Connect to RAK11300 via serial.
2. Test connection with basic `AT` command.
3. Configure connection parameters, visit [The Things Network](https://eu1.cloud.thethings.network).
4. Register if needed, add new application.
5. Configure end device: OTAA or ABP.
6. Use [AT Commands](https://docs.rakwireless.com/product-categories/wisduo/rak11300-module/at-command-manual/#atr) in Arduino IDE serial monitor.
7. Set parameters, send join command to network via gateway.
8. Monitor status on website; test data via serial monitor.

---

### Links

- [RAK19007 Datasheet](https://docs.rakwireless.com/product-categories/wisblock/rak19007/datasheet/)
- [RAK11300 Datasheet](https://docs.rakwireless.com/product-categories/wisduo/rak11300-module/datasheet/)
- [RAK13300 Datasheet](https://docs.rakwireless.com/product-categories/wisblock/rak13300/datasheet/)
