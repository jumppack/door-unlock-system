# Door Unlock System

A Smart Home IoT project to control a sliding door lock using a NodeMCU (ESP8266), a High-Torque Servo, and the Blynk platform.

## Features
- **Remote Control**: Lock/Unlock from anywhere using the Blynk App.
- **Precision Control**: Slider widget for fine-tuning the lock position (0-270 degrees).
- **Quick Actions**: One-tap button for immediate Lock/Unlock.
- **High Torque**: Uses a standard size metal gear servo to handle mechanical resistance.

## Project Structure
- `src/`: Contains the firmware code for the NodeMCU.
- `knowledge/`: Documentation on hardware, wiring, and configuration.
- `resources/`: Datasheets and assets.

## Getting Started
1. Open `src/door_lock_firmware/door_lock_firmware.ino` in Arduino IDE.
2. Update the `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, and `BLYNK_AUTH_TOKEN`.
3. Provide your WiFi credentials (`ssid` and `pass`).
4. Flash to NodeMCU.

## Hardware
See [Hardware Setup](knowledge/hardware_setup.md) for detailed wiring instructions.
