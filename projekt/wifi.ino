// #include <WiFi.h>

// const char *ssid = "ESP32-Access-Point";
// const char *password = "123456789";

// void setup() {
//   Serial.begin(9600);  // Start Serial communication
//   delay(5000);  // Wait for the Serial Monitor to start

//   Serial.println("Setting up Wi-Fi AP...");
//   WiFi.mode(WIFI_AP);  // Set ESP32 as Access Point

//   Serial.println("Starting Access Point...");
//   if(WiFi.softAP(ssid, password)) {
//     Serial.println("Access Point Started");
//   } else {
//     Serial.println("Access Point Failed");
//   }

//   delay(2000);  // Allow time for AP to initialize

//   Serial.println("ESP32 is ready to connect");
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.softAPIP());  // Print IP Address of the AP
// }

// void loop() {
//   // Nothing to do here
// }
