# Software Documentation

## Content

- [Sensor Data Gathering RAK11200](#sensor-data-gathering-rak11200)
- [Serial Connection from RAK11200 to RAK4631](#serial-connection-from-rak11200-to-rak4631)
- [Configuration of Meshtastic on RAK4631](#configuration-of-meshtastic-on-rak4631)
- [Forwarding Data From Serial](#forwarding-data-from-serial)
- [Initialization of the Gateway via AT Commands RAK11300](#initialization-of-the-gateway-via-at-commands-rak11300)
- [Connection to the Gateway RAK13300](#connection-to-the-gateway-rak13300)
- [Combination of the Components](#combination-of-the-components)

---

## Sensor Data Gathering RAK11200

To gather sensor data using the RAK11200 with the WisBlock Environment Sensor, follow these steps:

1. Ensure the WisBlock Environment Sensor is properly connected to the RAK11200.
2. Use the appropriate libraries and example sketches on PlatformIO to read sensor values.
3. Implement the necessary code to transmit sensor data over the LoRa mesh network.

---

## Serial Connection from RAK11200 to RAK4631

Establishing a serial connection from the RAK11200 to the RAK4631 involves:

1. Configuring the UART communication parameters on both devices.
2. Testing the serial communication to ensure data transmission between RAK11200 and RAK4631 is successful.

**Note:** The commonly used way to establish UART communication is to use `Serial` for the connection to the computer monitor and `Serial1` for communication between the two devices via RX/TX.

---

## Configuration of Meshtastic on RAK4631

Configure Meshtastic on the RAK4631 by:

1. Flashing the Meshtastic firmware onto the RAK4631 using the following website: [Meshtastic Flasher](https://flasher.meshtastic.org/).
2. Setting up the mesh network parameters such as node IDs and communication channels.

**Important Note:** The internal pins for serial communication are listed in the datasheet as UART0 (pins 9 and 10) and UART1 (pins 33 and 34), but the Meshtastic app uses UART1 (pins 14 and 13).

---

## Forwarding Data From Serial

Forwarding data received over serial from RAK11200 to the Meshtastic network on RAK4631 can be done by following these steps:

1. Connect via BLE to the node that will receive the data over serial.
2. Go to **Device Settings** and select **Serial** from the **Module Settings**.
3. Enable it and set **RX** to `14` and **TX** to `13`.
4. Set the baud rate to `115200`.
5. Save the changes (the device will automatically reconnect to apply the changes).

---


## Connection to the Gateway RAK11200 + RAK 13300

1. Flash the RAK11200 with the firmware from the Meshtastic flasher website.
2. Configure the RAK11200 via BLE first for MQTT, and then for WiFi. Otherwise, you risk losing your BLE connection and will need to use the web client hosted on the RAK device.
3. Ensure all nodes are configured with the correct frequency. The first node should enable serial communication via RX/TX.
4. Configure the RAK11200 endpoint to connect to the MQTT broker on the Meshtastic public network via WiFi.
5. If needed, obtain the IP address from the Arduino serial output (e.g., 192.168.2.174) and access it via a web browser.
6. Configure the endpoint channel and enable forwarding to and from MQTT.
7. Test by sending a message and checking the output.

---

## Combination of the Components

This section consists of three parts:

1. Gathering the sensor data.
2. Sending data through serial communication.
3. Forwarding data to the mesh network.
4. Forwarding data from the mesh network to the MQTT broker.

## Alternative Way of Connection via LoRaWAN Gateway

### Initialization of the Gateway via AT Commands RAK11300

Initialize the RAK11300 gateway using AT commands:

1. Connect to the RAK11300 via serial communication.
2. To test the connection, use the basic command `AT`.
3. If step 2 works properly, configure the connection parameters.
4. Before configuration, visit the website: [The Things Network](https://eu1.cloud.thethings.network).
5. If you do not have an account, sign up.
6. After registration, you will see an empty console where you can add a new application.
7. Add a new end device with the following settings:
   - **Input Method:** Manually
   - **Frequency Plan:** Europe 863-870 MHz (SF9 for RX2 / recommended)
   - **LoRaWAN Version:** 1.0.2
   - **Regional Parameters Version:** RP001 Regional Parameters 1.0.2 revision B
   - There are two common connection methods: OTAA and ABP.

   **For OTAA:**
   - JoinEUI: `00 00 00 00 00 00 00 00`
   - DevEUI: Generate for the first time
   - AppKey: Generate for the first time
   - End Device ID: Should be meaningful

   **For ABP:**
   - DevEUI: Generate for the first time
   - Device Address: Generate for the first time
   - AppSKey: Generate for the first time
   - NwkSKey: Generate for the first time
   - End Device ID: Should be meaningful

8. Now use the [AT Commands](https://docs.rakwireless.com/product-categories/wisduo/rak11300-module/at-command-manual/#atr) for the RAK11300, accessible via the serial monitor in the Arduino IDE.
10. Set the parameters and send a join command to connect to the network via the defined gateway.
11. If the response from the serial monitor is positive, the connection status should be visible on the website.
12. Test sending example data via the serial monitor.

---


### Links

- [RAK19007 Datasheet](https://docs.rakwireless.com/product-categories/wisblock/rak19007/datasheet/)
- [RAK11300 Datasheet](https://docs.rakwireless.com/product-categories/wisduo/rak11300-module/datasheet/)
- [RAK13300 Datasheet](https://docs.rakwireless.com/product-categories/wisblock/rak13300/datasheet/)
