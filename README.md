# Dieter Meshtastic

## Description

This project aims to send sensor values over the mesh network to a Wisblock Core.

## Content

- [Hardware](#hardware)
- [Documentation](#documentation)
- [Data Types](#data-types)


## Hardware
### RawWireless WisBlock

| Component  | Price (€) | Description                                |
|------------|-----------|--------------------------------------------|
| RAK4631    | -----     | Meshtastic Starter Kit                     |
| RAK13300   | -----     | Pi-based Wisblock Core (LoRa)              |
| RAK19007   | -----     | Wisblock Base                              |
| RAK11310   | -----     | ESP based Wisblock Core (BLE)              |
| **Total**  | **00.00** |                                           |

## Documentation

For datasheets, quick guides, and detailed descriptions, visit:  
[Meshtastic](https://meshtastic.org)
## Software


---

## Meshtastic

Meshtastic is an open-source project that enables a mesh network using affordable LoRa modules. It allows users to send and receive text messages and sensor data over long distances without the need for the internet or cellular networks.

### Technology

#### LoRa (Long Range)
- **Long-distance communication:** LoRa enables wireless data transmission over several kilometers with minimal power consumption.
- **License-free frequency bands:** Different frequency bands are used depending on the region (e.g., 868 MHz in Europe, 915 MHz in the USA).

#### Mesh Network
- **Decentralized structure:** Nodes automatically connect and relay messages.
- **Self-healing:** If a node fails, the network finds alternative routes.
- **Offline-capable:** No dependency on mobile networks or the internet.

### Features
- **Send & receive text messages** without the internet
- **GPS tracking & location sharing**
- **Integration with smartphones & computers** (via Bluetooth or USB)
- **Expandable through plugins & API**
- **AES encryption** for secure communication

### Hardware
Commonly supported hardware:
- **Heltec LoRa ESP32**
- **TTGO T-Beam**
- **RAK Wireless Modules**
- **LilyGO T-Echo**

###  Installation & Setup
#### Flash the Firmware
Install the latest Meshtastic firmware using:
```sh
pip install meshtastic
meshtastic --flash
```

#### Connect the App
- **Android:** Download the Meshtastic app from the store.
- **PC:** Use the `meshtastic-python` CLI for configurations.

#### Network Configuration
Customize the network with custom channels and encryption keys:
```sh
meshtastic --set channel_name "MyNetwork"
meshtastic --set psk "my_secure_key"
```

### Useful Links
- [Official Website](https://meshtastic.org/)
- [GitHub Repository](https://github.com/meshtastic/)
- [Community Forum](https://meshtastic.discourse.group/)
