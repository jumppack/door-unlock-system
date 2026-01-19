# Hardware Setup

## Components
1.  **Microcontroller**: NodeMCU ESP8266
2.  **Servo Motor**: Miuzei 270 Degree High Torque Servo
    -   Operating Voltage: 4.8V - 6.8V
    -   Control Signal: PWM (Pulse Width Modulation)
    -   Pulse Width Range: 500us (0°) to 2500us (270°)
3.  **Power Supply**: 4x AA Battery Pack (6V)
    -   Used strictly for the Servo Motor to ensure sufficient current and prevent voltage sag on the NodeMCU.

## Power Connections
*   **NodeMCU**: Powered via Type-C cable (initial testing) or separate 5V source.
*   **Servo**: Powered directly by the 6V Battery Pack.
*   **Common Ground**: The Battery Pack Negative (GND) MUST be connected to the NodeMCU GND pin. This is critical for the control signal to work.

## Wiring Table

| Component | Wire Color | Connection Point | Note |
| :--- | :--- | :--- | :--- |
| **Servo** | Red | Battery (+) | Positive Terminal |
| **Servo** | Black/Brown | Battery (-) AND NodeMCU GND | Common Ground |
| **Servo** | Orange/White | NodeMCU D4 (GPIO2) | PWM Signal |
