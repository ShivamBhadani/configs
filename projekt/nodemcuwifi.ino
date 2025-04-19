// #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>

// #define IN1 5    // GPIO 5 to IN1 (Left motor)
// #define IN2 4    // GPIO 4 to IN2 (Left motor)
// #define IN3 0    // GPIO 0 to IN3 (Right motor)
// #define IN4 2    // GPIO 2 to IN4 (Right motor)
// #define nSLEEP 14 // Pin to wake up the motor driver

// // Set WiFi credentials
// const char* ssid = "ESP8266-Motor-Controller";  // AP SSID
// const char* password = "123456789";             // AP Password

// ESP8266WebServer server(80);

// int motorSpeedA = 255;  // Full speed by default
// int motorSpeedB = 255;  // Full speed by default

// // Declare the stopMotors function
// void stopMotors();

// // Declare the handleStopMotors function
// void handleStopMotors() {
//   stopMotors(); // Calls stopMotors to stop the motors
//   server.send(200, "text/plain", "Motors Stopped");
// }

// void setup() {
//   // Start Serial Monitor for debugging
//   Serial.begin(115200);

//   // Set motor control pins as outputs
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(IN3, OUTPUT);
//   pinMode(IN4, OUTPUT);
//   pinMode(nSLEEP, OUTPUT);

//   // Wake up the motor driver
//   digitalWrite(nSLEEP, HIGH);

//   // Initialize the motor pins to LOW (stop motors initially)
//   stopMotors();

//   // Start Wi-Fi Access Point
//   WiFi.softAP(ssid, password);
//   Serial.println("WiFi Access Point Started");

//   // Print the IP address
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.softAPIP());

//   // Serve the webpage
//   server.on("/", HTTP_GET, handleRoot);
//   server.on("/motorControl", HTTP_GET, handleMotorControl); // Handle motor control requests
//   server.on("/stopMotors", HTTP_GET, handleStopMotors);    // Handle stop motors request

//   // Start the web server
//   server.begin();
//   Serial.println("Server Started");
// }

// void loop() {
//   // Handle incoming HTTP requests
//   server.handleClient();
// }

// // Webpage to control motor direction, speed, and stop
// void handleRoot() {
//   String html = "<html><head><style>";
  
//   // CSS for styling the page
//   html += "body { font-family: Arial, sans-serif; text-align: center; background-color: #f7f7f7; padding: 20px; margin: 0; }";
//   html += "h2 { color: #333; font-size: 24px; margin-bottom: 30px; }";
//   html += "button { padding: 15px 30px; font-size: 18px; background-color: #4CAF50; color: white; border: none; border-radius: 5px; cursor: pointer; margin: 10px; width: 250px; }";
//   html += "button:hover { background-color: #45a049; }";
//   html += "input[type=range] { width: 80%; margin: 10px 0; }";
//   html += ".controls { margin-bottom: 20px; display: grid; grid-template-columns: 1fr 1fr; gap: 10px; }";
//   html += ".controls button { width: 100%; }";
//   html += "h3 { color: #333; font-size: 20px; margin-top: 20px; }";
//   html += "</style></head><body>";

//   // Header and motor control options
//   html += "<h2>ESP8266 Motor Controller</h2>";

//   // Control buttons for forward, backward, left, right, and stop
//   html += "<div class=\"controls\">";
//   html += "<button onclick=\"moveForward()\">Move Forward</button>";
//   html += "<button onclick=\"moveBackward()\">Move Backward</button>";
//   html += "<button onclick=\"turnLeft()\">Turn Left</button>";
//   html += "<button onclick=\"turnRight()\">Turn Right</button>";
//   html += "<button onclick=\"stopMotors()\">Stop Motors</button>";
//   html += "</div>";
  
//   // Speed control slider
//   html += "<h3>Adjust Speed (0-255)</h3>";
//   html += "<input type=\"range\" min=\"0\" max=\"255\" value=\"" + String(motorSpeedA) + "\" id=\"speedA\" onchange=\"updateSpeed(this.value)\">";
  
//   // JavaScript to update the speed values and stop the motors without refreshing the page
//   html += "<script>";
//   html += "function updateSpeed(speed) {";
//   html += "  var xhr = new XMLHttpRequest();";
//   html += "  xhr.open('GET', '/motorControl?motor=A&speed=' + speed, true);";
//   html += "  xhr.send();";
//   html += "}";

//   html += "function moveForward() {";
//   html += "  var xhr = new XMLHttpRequest();";
//   html += "  xhr.open('GET', '/motorControl?motor=A&direction=forward', true);";
//   html += "  xhr.send();";
//   html += "}";

//   html += "function moveBackward() {";
//   html += "  var xhr = new XMLHttpRequest();";
//   html += "  xhr.open('GET', '/motorControl?motor=A&direction=backward', true);";
//   html += "  xhr.send();";
//   html += "}";

//   html += "function turnLeft() {";
//   html += "  var xhr = new XMLHttpRequest();";
//   html += "  xhr.open('GET', '/motorControl?motor=A&direction=left', true);";
//   html += "  xhr.send();";
//   html += "}";

//   html += "function turnRight() {";
//   html += "  var xhr = new XMLHttpRequest();";
//   html += "  xhr.open('GET', '/motorControl?motor=A&direction=right', true);";
//   html += "  xhr.send();";
//   html += "}";

//   html += "function stopMotors() {";
//   html += "  var xhr = new XMLHttpRequest();";
//   html += "  xhr.open('GET', '/stopMotors', true);";
//   html += "  xhr.send();";
//   html += "  alert('Motors stopped');";
//   html += "}";
//   html += "</script>";

//   html += "</body></html>";
//   server.send(200, "text/html", html);
// }

// // Handle the motor control logic (direction and speed)
// void handleMotorControl() {
//   String motor = server.arg("motor");
//   String direction = server.arg("direction");
//   String speed = server.arg("speed");

//   motorSpeedA = speed.toInt();
//   if (motor == "A") {
//     stopMotors();  // Stop motors before any new movement command
//     if (direction == "forward") {
//       moveMotorForward();
//     } else if (direction == "backward") {
//       moveMotorBackward();
//     } else if (direction == "left") {
//       turnLeft();
//     } else if (direction == "right") {
//       turnRight();
//     }
//   }

//   // Update motor speed with PWM
//   analogWrite(IN1, motorSpeedA);
//   analogWrite(IN2, 255 - motorSpeedA);

//   // Send a response
//   server.send(200, "text/plain", "OK");
// }

// // Motor moving forward
// void moveMotorForward() {
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
// }

// // Motor moving backward
// void moveMotorBackward() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
// }

// // Turn left: left motor backward, right motor forward for 300-500ms
// void turnLeft() {
//   digitalWrite(IN1, LOW);  // Left motor backward
//   digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, HIGH); // Right motor forward
//   digitalWrite(IN4, LOW);
//   delay(400); // Turn for 400ms
//   stopMotors();  // Stop after turning
// }

// // Turn right: left motor forward, right motor backward for 300-500ms
// void turnRight() {
//   digitalWrite(IN1, HIGH); // Left motor forward
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);  // Right motor backward
//   digitalWrite(IN4, HIGH);
//   delay(400); // Turn for 400ms
//   stopMotors();  // Stop after turning
// }

// // Stop both motors
// void stopMotors() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, LOW);
//   motorSpeedA = 0;
//   motorSpeedB = 0;
// }
