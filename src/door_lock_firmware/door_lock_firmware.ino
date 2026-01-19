#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Back door lock"
#define BLYNK_AUTH_TOKEN "my_token_generated_from_blynk_app"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "my_wifi_name";
char pass[] = "my_wifi_password";

Servo myServo;

// --- PRECISION SLIDER (V4) ---
BLYNK_WRITE(V4) {
  int sliderValue = param.asInt(); // App range is 0 to 270
  
  // Use your specific 500-2000 range for the 270-degree motor
  // Note: Previous code used 2500, but mapping logic suggests 500-2500 for full range usually? 
  // Code from file says 2500. Keeping 2500 to match deployed code.
  int pulseWidth = map(sliderValue, 0, 270, 500, 2500);
  
  myServo.writeMicroseconds(pulseWidth);
}

// --- QUICK-LOCK BUTTON (V5) ---
BLYNK_WRITE(V5) {
  int buttonState = param.asInt();
  if (buttonState == 1) {
    // Full Range (270 degrees)
    myServo.writeMicroseconds(2500); 
  } else {
    // Rest Position (0 degrees)
    myServo.writeMicroseconds(500);
  }
}

void setup() {
  myServo.attach(2); // Connect signal wire to Pin D4
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}
