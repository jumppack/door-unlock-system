# IoT Door Unlock System

A smart, secure, and reliable door unlock system powered by the ESP8266 NodeMCU and controlled via the Blynk IoT platform. This project allows you to lock and unlock your door remotely using a mobile app, featuring both a precision slider and a quick-toggle button.

## 🚀 Features
*   **Remote Access**: Control your door lock from anywhere in the world.
*   **High Precision**: 0-270° control using a high-torque servo.
*   **Dual Modes**:
    *   **Slider Widget**: Fine-tune the lock position.
    *   **Button Widget**: One-tap Lock/Unlock toggle.
*   **Reliable Hardware**: Built on the robust NodeMCU ESP8266 (Type-C) platform.

## 🛠️ Hardware Requirements
See the full [Shopping List](resources/shopping_list.md) for purchase links.

1.  **NodeMCU ESP8266 (Type-C Version)**
    *   *Note*: Ensure you get the ESP8266 model with a Type-C connector (often Lolin D1 Mini V4 or similar).
2.  **Miuzei 270° Servo (20KG/25KG)**
    *   Must handle 500-2500us pulse width for full 270° range.
3.  **4x AA Battery Pack (6V)**
    *   Powers the servo independently to prevent brownouts.
4.  **Jumper Wires & Breadboard/PCB**

## 🔌 specific Wiring & Assembly
**CRITICAL**: The Servo must be powered by the battery pack, NOT the NodeMCU. The grounds must be shared.

| NodeMCU Pin | Component | Connection |
| :--- | :--- | :--- |
| **D4 (GPIO2)** | Servo | Signal Wire (Orange/White) |
| **GND** | Battery (-) | Common Ground |
| **GND** | Servo | Ground Wire (Brown/Black) |
| **N/A** | Battery (+) | Servo Power (Red) |

See the **[Wiring Diagram](knowledge/wiring_diagram.md)** for a visual guide.

## 💻 Software Setup

### 1. Blynk App Setup
1.  Create a New Template named "Back door lock".
2.  Add two Datastreams:
    *   **V4 (Integer)**: Min 0, Max 270 (for Slider).
    *   **V5 (Integer)**: Min 0, Max 1 (for Button).
3.  Create a Web Dashboard / Mobile Dashboard with a Slider (V4) and Button (V5).

### 2. Firmware Installation
1.  Install [Arduino IDE](https://www.arduino.cc/en/software).
2.  Install the **ESP8266 Board** manager (search for "esp8266 by ESP8266 Community").
3.  Install the **Blynk** library (Sketch -> Include Library -> Manage Libraries -> Search "Blynk").
4.  Open `src/door_lock_firmware/door_lock_firmware.ino`.
5.  Update the top section with your credentials:
    ```cpp
    #define BLYNK_TEMPLATE_ID "YOUR_ID_HERE"
    #define BLYNK_TEMPLATE_NAME "Back door lock"
    #define BLYNK_AUTH_TOKEN "YOUR_TOKEN_HERE"
    char ssid[] = "YOUR_WIFI_SSID";
    char pass[] = "YOUR_WIFI_PASS";
    ```
6.  Connect NodeMCU via Type-C cable and upload.

## 📱 Usage
*   **Slider (V4)**: Drag to set the servo angle precisely between 0° (Unlock) and 270° (Lock).
*   **Button (V5)**:
    *   **ON (1)**: Locks (moves to 270°).
    *   **OFF (0)**: Unlocks (moves to 0°).
