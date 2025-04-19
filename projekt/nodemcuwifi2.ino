// #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>

// // Define Wi-Fi credentials for the ESP8266 Access Point (AP)
// const char* apSSID = "ESP8266-Car-Control"; // Access Point SSID
// const char* apPassword = "123456789"; // Password for the AP

// // Motor control pins
// const int IN1 = D1;
// const int IN2 = D2;
// const int IN3 = D3;
// const int IN4 = D4;
// const int Nsleep = D5;

// // PWM pins for motor speed control
// const int speedPinLeft = D6;  // For controlling speed of left motor
// const int speedPinRight = D7; // For controlling speed of right motor

// // Default speed
// int motorSpeed = 1023; // PWM range: 0-1023

// ESP8266WebServer server(80);

// // Motor control functions
// void motorStop() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, LOW);
//   analogWrite(speedPinLeft, 0);
//   analogWrite(speedPinRight, 0);
// }

// void moveForward() {
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
//   analogWrite(speedPinLeft, motorSpeed);
//   analogWrite(speedPinRight, motorSpeed);
// }

// void moveBackward() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
//   analogWrite(speedPinLeft, motorSpeed);
//   analogWrite(speedPinRight, motorSpeed);
// }

// void turnLeft() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
//   analogWrite(speedPinLeft, motorSpeed);
//   analogWrite(speedPinRight, motorSpeed);
//   delay(400); // Turn for 400ms
//   motorStop(); // Stop after turning
// }

// void turnRight() {
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
//   analogWrite(speedPinLeft, motorSpeed);
//   analogWrite(speedPinRight, motorSpeed);
//   delay(400); // Turn for 400ms
//   motorStop(); // Stop after turning
// }

// // Serve HTML with speed control and joystick-like buttons
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
//   html += "@media (max-width: 600px) { .btn { width: 100px; height: 100px; font-size: 24px; } .btn-stop { width: 120px; height: 120px; font-size: 28px; } }";
//   html += "</style></head><body>";
//   html += "<h1>Control Your Car</h1>";
  
//   // Buttons for movement control
//   html += "<div class='container'>";
//   html += "<button class='btn' onclick='location.href=\"forward\"'>backward</button>";
//   html += "<button class='btn' onclick='location.href=\"/backward\"'>forward</button><br>";
//   html += "<button class='btn' onclick='location.href=\"/left\"'>right</button>";
//   html += "<button class='btn' onclick='location.href=\"/right\"'>left</button>";
//   html += "</div>";
  
//   // Stop button
//   html += "<button class='btn-stop' onclick='location.href=\"/stop\"'>Stop</button>";
  
//   // Speed control
//   html += "<div class='slider-container'>";
//   html += "<h2>Motor Speed</h2>";
//   html += "<input type='range' min='0' max='1023' value='" + String(motorSpeed) + "' class='slider' id='speedSlider' onchange='updateSpeed()'>";
//   html += "<p>Speed: <span id='speedValue'>" + String(motorSpeed) + "</span></p>";
//   html += "</div>";

//   html += "<script>";
//   html += "function updateSpeed() {";
//   html += "  var speed = document.getElementById('speedSlider').value;";
//   html += "  document.getElementById('speedValue').innerHTML = speed;";
//   html += "  var xhr = new XMLHttpRequest();";
//   html += "  xhr.open('GET', '/setSpeed/' + speed, true);";
//   html += "  xhr.send();";
//   html += "}";
//   html += "</script>";
//   html += "</body></html>";

//   server.send(200, "text/html", html);
// }

// // Handle speed change
// void handleSetSpeed() {
//   if (server.hasArg("speed")) {
//     motorSpeed = server.arg("speed").toInt();
//   }
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void setup() {
//   // Initialize motor control pins
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(IN3, OUTPUT);
//   pinMode(IN4, OUTPUT);
//   pinMode(Nsleep, OUTPUT);
  
//   // Initialize PWM pins for motor speed control
//   pinMode(speedPinLeft, OUTPUT);
//   pinMode(speedPinRight, OUTPUT);

//   // Start Serial monitor for debugging
//   Serial.begin(115200);

//   // Set the Nsleep pin HIGH to wake up the motor driver
//   digitalWrite(Nsleep, HIGH);

//   // Set the PWM frequency to 25 kHz (higher frequency for motor control)
//   analogWriteFreq(25000); // Set frequency to 25 kHz

//   // Start ESP8266 as an Access Point (AP)
//   WiFi.softAP(apSSID, apPassword);

//   // Print the IP address assigned to the ESP8266 in AP mode
//   Serial.print("ESP8266 is in AP Mode. IP Address: ");
//   Serial.println(WiFi.softAPIP());

//   // Define web server routes
//   server.on("/", HTTP_GET, handleRoot);
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
  
//   server.on("/setSpeed", HTTP_GET, handleSetSpeed);

//   // Start the server
//   server.begin();
// }

// void loop() {
//   server.handleClient();
// }
