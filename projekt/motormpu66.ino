// #include <Wire.h>
// #include <MPU6050.h>
// #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>

// // Wi-Fi credentials for ESP8266 Access Point (AP)
// const char* apSSID = "ESP8266-Car-Control"; // Access Point SSID
// const char* apPassword = "123456789"; // Password for the AP

// // Motor control pins (updated for DRV8833)
// const int IN1 = D3;
// const int IN2 = D4;
// const int IN3 = D5;
// const int IN4 = D6;
// const int Nsleep = D7;

// float carSpeed = 0.0;  // Car speed in m/s
// unsigned long lastTime = 0;  // Store last time to calculate time difference
// // MPU6050 object
// MPU6050 mpu;

// // Default motor speed (not needed for DRV8833)
// int motorSpeed = 1023; // No speed control for DRV8833

// // Web server setup
// ESP8266WebServer server(80);

// // Accelerometer data variables
// float ax_g = 0.0, ay_g = 0.0, az_g = 0.0;

// // Threshold for considering acceleration
// const float accelerationThreshold = 0.06;  // in g

// // Motor control functions
// void motorStop() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, LOW);
// }

// void moveForward() {
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
// }

// void moveBackward() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
// }

// void turnLeft() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
//   delay(400); // Turn for 400ms
//   motorStop(); // Stop after turning
// }

// void turnRight() {
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
//   delay(400); // Turn for 400ms
//   motorStop(); // Stop after turning
// }

// void handleRoot() {
//   String html = "<html><head><title>Car Control</title>";
//   html += "<style>";
//   html += "body { font-family: Arial, sans-serif; text-align: center; background: #F8E1D4; margin: 0; padding: 0; height: 100vh; display: flex; justify-content: center; align-items: center; flex-direction: column; }";
//   html += "h1 { font-size: 2.5rem; color: #4B4B4B; margin-bottom: 20px; }";
//   html += ".container { display: flex; flex-wrap: wrap; justify-content: center; align-items: center; gap: 30px; margin-top: 20px; }";
//   html += ".btn { background-color: #A5D8FF; color: black; padding: 30px; border-radius: 50%; width: 200px; height: 200px; font-size: 25px; border: none; cursor: pointer; transition: 0.3s; box-shadow: 0 6px 10px rgba(0, 0, 0, 0.1); }";
//   html += ".btn:hover { background-color: #78C5D6; }";
//   html += ".btn-stop { background-color: #FF8B8B; width: 140px; height: 140px; font-size: 32px; border-radius: 50%; }";
//   html += ".slider { width: 100%; max-width: 500px; margin-top: 30px; }";
//   html += ".slider-container { text-align: center; margin-top: 40px; }";
  
//   // Improved accelerometer styling
//   html += ".accel-values { font-size: 1.5rem; margin-top: 30px; background-color: #fff; border-radius: 15px; padding: 20px; box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2); display: inline-block; max-width: 400px; }";
//   html += ".accel-values h2 { color: #4B4B4B; font-size: 1.8rem; margin-bottom: 10px; }";
//   html += ".accel-value { margin: 10px 0; font-size: 1.2rem; color: #4B4B4B; }";
//   html += ".accel-value span { font-weight: bold; color: #007BFF; }";
  
//   html += "#speed { font-size: 2rem; font-weight: bold; color: #28a745; margin-top: 20px; background-color: #F1F1F1; padding: 10px 20px; border-radius: 10px; }";
//   html += "@media (max-width: 600px) { .btn { width: 100px; height: 100px; font-size: 24px; } .btn-stop { width: 120px; height: 120px; font-size: 28px; } .accel-values { max-width: 90%; } }";
//   html += "</style>";
//   html += "<script>";
//   html += "function fetchAccelData() {";
//   html += "fetch('/getAccelData').then(response => response.json()).then(data => {";
//   // html += "    // Update accelerometer data
//   html += "document.getElementById('ax').innerText = 'x: ' + data.ax + ' g';";
//   html += "document.getElementById('ay').innerText = 'y: ' + data.ay + ' g';";
//   html += "document.getElementById('az').innerText = 'z: ' + data.az + ' g';";
//   // html += "    
//   // html += "// Update speed dynamically
//   html += "document.getElementById('speed').innerText = 'Speed: ' + data.speed.toFixed(2) + ' m/s';";
//   html += "});";
//   html += "setTimeout(fetchAccelData, 100);"; // Update every 100ms for real-time speed
//   html += "}";
//   html += "window.onload = fetchAccelData;";
//   html += "</script>";
//   html += "</head><body>";
//   html += "<h1>Control Your Car</h1>";

//   // Buttons for movement control
//   html += "<div class='container'>";
//   html += "<button class='btn' onclick='location.href=\"/backward\"'>Backward</button>";
//   html += "<button class='btn' onclick='location.href=\"/forward\"'>Forward</button><br>";
//   html += "<button class='btn' onclick='location.href=\"/left\"'>Left</button>";
//   html += "<button class='btn' onclick='location.href=\"/right\"'>Right</button>";
//   html += "</div>";
  
//   // Stop button
//   html += "<button class='btn-stop' onclick='location.href=\"/stop\"'>Stop</button>";

//   // Display speed value above accelerometer values
//   html += "<div id='speed'>Speed: " + String(carSpeed, 2) + " m/s</div>";

//   // Display accelerometer values dynamically
//   html += "<div class='accel-values'>";
//   html += "<h2>Accelerometer (in g)</h2>";
//   html += "<p class='accel-value' id='ax'>x: " + String(ax_g, 4) + " g</p>";
//   html += "<p class='accel-value' id='ay'>y: " + String(ay_g, 4) + " g</p>";
//   html += "<p class='accel-value' id='az'>z: " + String(az_g, 4) + " g</p>";
//   html += "</div>";

//   html += "</body></html>";

//   server.send(200, "text/html", html);
// }

// void loop() {
//   int16_t ax, ay, az;

//   // Read accelerometer data from the MPU6050
//   mpu.getAcceleration(&ax, &ay, &az);

//   // Convert the raw accelerometer data to 'g' (gravitational units)
//   ax_g = ax / 16384.0;
//   ay_g = ay / 16384.0;
//   az_g = az / 16384.0;

//   // Only consider acceleration in the X-axis if it exceeds the threshold
//   if (fabs(ax_g) > accelerationThreshold) {
//     // Calculate acceleration in m/s^2
//     float ax_mps2 = ax_g * 9.81;

//     // Calculate the time difference (in seconds)
//     unsigned long currentTime = millis();
//     float deltaTime = (currentTime - lastTime) / 1000.0;  // in seconds

//     // Update speed: v = u + at (initial speed u = 0, so v = at)
//     carSpeed += ax_mps2 * deltaTime;  // m/s

//     // Limit speed to prevent it from becoming unreasonably large
//     if (carSpeed < 0) carSpeed = 0;

//     lastTime = currentTime;  // Update the time for the next loop
//   }

//   server.handleClient();  // Handle HTTP requests
// }

// void setup() {
//    Serial.begin(115200);
//   Wire.begin(D2, D1);  // Initialize I2C with SDA on D2 and SCL on D1

//   // Initialize the MPU6050
//   Serial.println("Initializing MPU6050...");
//   mpu.initialize();

//   // Check if the MPU6050 is connected
//   if (mpu.testConnection()) {
//     Serial.println("MPU6050 connection successful.");
//   } else {
//     Serial.println("MPU6050 connection failed.");
//     while (1);  // Stop if connection fails
//   }

//   delay(1000);  // Wait for 1 second before starting to read data

//   // Initialize motor control pins
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(IN3, OUTPUT);
//   pinMode(IN4, OUTPUT);
//   pinMode(Nsleep, OUTPUT);
  
//   // Set the Nsleep pin HIGH to wake up the motor driver
//   digitalWrite(Nsleep, HIGH);

//   // Start ESP8266 as an Access Point (AP)
//   WiFi.softAP(apSSID, apPassword);

//   // Print the IP address assigned to the ESP8266 in AP mode
//   Serial.print("ESP8266 is in AP Mode. IP Address: ");
//   Serial.println(WiFi.softAPIP());

//   // Define web server routes
//   server.on("/", HTTP_GET, handleRoot);
//   server.on("/getAccelData", HTTP_GET, []() {
//     String json = "{\"ax\": " + String(ax_g, 4) + ", \"ay\": " + String(ay_g, 4) + ", \"az\": " + String(az_g, 4) + ", \"speed\": " + String(carSpeed, 2) + "}";
//     server.send(200, "application/json", json);
//   });

//   // Define motor control routes
//   server.on("/forward", HTTP_GET, []() {
//     moveForward();
//     server.sendHeader("Location", "/");
//     server.send(303);
//   });
//   server.on("/backward", HTTP_GET, []() {
//     moveBackward();
//     server.sendHeader("Location", "/");
//     server.send(303);
//   });
//   server.on("/left", HTTP_GET, []() {
//     turnLeft();
//     server.sendHeader("Location", "/");
//     server.send(303);
//   });
//   server.on("/right", HTTP_GET, []() {
//     turnRight();
//     server.sendHeader("Location", "/");
//     server.send(303);
//   });
//   server.on("/stop", HTTP_GET, []() {
//     motorStop();
//     server.sendHeader("Location", "/");
//     server.send(303);
//   });

//   // Start the server
//   server.begin();
// }
