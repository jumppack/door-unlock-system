# Blynk Configuration

## Template Details
*   **Template Name**: Back door lock
*   **Device Name**: Back door lock

## Datastreams

| Name | VPin | Data Type | Units | Min | Max | Widget Type | Function |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Slider** | V4 | Integer | None | 0 | 270 | Slider | Controls specific angle of the lock |
| **Button** | V5 | Integer | None | 0 | 1 | Button/Switch | Quick Toggle (Lock/Unlock) |

## Automation / Logic
*   **V4 (Slider)**: Maps the 0-270 input directly to the servo pulse width (500-2500us).
*   **V5 (Button)**:
    *   `1` (ON) -> Moves servo to 2500us (Locked/270°)
    *   `0` (OFF) -> Moves servo to 500us (Unlocked/0°)
