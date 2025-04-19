// #include <WiFi.h>
// #include <ESPAsyncWebServer.h>

// // Motor control pins
// #define IN1 25  // GPIO 25 to IN1
// #define IN2 26  // GPIO 26 to IN2
// #define IN3 19  // GPIO 19 to IN3
// #define IN4 18  // GPIO 18 to IN4
// #define nSLEEP 32  // Pin to wake up DRV8833

// // Wi-Fi credentials
// const char *ssid = "ESP32-Access-Point";  // ESP32 as AP
// const char *password = "123456789";       // Password for Wi-Fi AP

// AsyncWebServer server(80);

// void setup() {
//   Serial.begin(115200);

//   // Initialize motor control pins as outputs
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(IN3, OUTPUT);
//   pinMode(IN4, OUTPUT);
//   pinMode(nSLEEP, OUTPUT);
  
//   // Wake up the DRV8833 by setting nSLEEP high
//   digitalWrite(nSLEEP, HIGH);

//   // Start Wi-Fi Access Point
//   WiFi.softAP(ssid, password);

//   // Print ESP32 IP address
//   Serial.println("ESP32 is ready to connect");
//   Serial.println("IP Address: ");
//   Serial.println(WiFi.softAPIP());

//   // Serve the webpage with motor control buttons
//   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
//     String html = "<html><body><h1>ESP32 Motor Control</h1>";
//     html += "<button onclick=\"location.href='/forward'\">Move Forward</button>";
//     html += "<button onclick=\"location.href='/backward'\">Move Backward</button>";
//     html += "<button onclick=\"location.href='/stop'\">Stop Motors</button>";
//     html += "</body></html>";
//     request->send(200, "text/html", html);
//   });

//   // Control motor actions via URL
//   server.on("/forward", HTTP_GET, [](AsyncWebServerRequest *request){
//     // Move motors forward
//     moveForward();
//     request->send(200, "text/html", "<h1>Moving Forward</h1><a href='/'>Back</a>");
//   });

//   server.on("/backward", HTTP_GET, [](AsyncWebServerRequest *request){
//     // Move motors backward
//     moveBackward();
//     request->send(200, "text/html", "<h1>Moving Backward</h1><a href='/'>Back</a>");
//   });

//   server.on("/stop", HTTP_GET, [](AsyncWebServerRequest *request){
//     // Stop motors
//     stopMotors();
//     request->send(200, "text/html", "<h1>Motors Stopped</h1><a href='/'>Back</a>");
//   });

//   // Start the web server
//   server.begin();
// }

// void loop() {
//   // Nothing to do here
// }

// // Function to move motors forward
// void moveForward() {
//   // Forward direction for motor A
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);

//   // Forward direction for motor B
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
// }

// // Function to move motors backward
// void moveBackward() {
//   // Reverse direction for motor A (backward)
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);

//   // Reverse direction for motor B (backward)
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
// }

// // Function to stop motors
// void stopMotors() {
//   // Stop motors
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, LOW);
// }
