// #include "painlessMesh.h"
// #include <Wire.h>
// #include <MPU6050.h>

// // Mesh Network Parameters
// #define   MESH_PREFIX     "whateverYouLike"
// #define   MESH_PASSWORD   "somethingSneaky"
// #define   MESH_PORT       5555

// // MPU6050 Parameters
// MPU6050 mpu;
// float ax_g, ay_g, az_g; // Acceleration in g for X, Y, Z axes
// const float threshold = 0.5; // Threshold for broadcasting data (±0.5g)

// // LED Pin
// #define LED_PIN 13

// Scheduler userScheduler;  // to control personal tasks
// painlessMesh  mesh;

// // User stub
// void sendMessage(); // Prototype so PlatformIO doesn't complain

// // Task to periodically check and send data
// Task taskSendMessage(TASK_SECOND * 1, TASK_FOREVER, &sendMessage);

// // Callback functions
// void receivedCallback(uint32_t from, String &msg) {
//   Serial.printf("Received message: %s\n", msg.c_str());
// }

// void newConnectionCallback(uint32_t nodeId) {
//   Serial.printf("--> New Connection, nodeId = %u\n", nodeId);
// }

// void changedConnectionCallback() {
//   Serial.println("Changed connections\n");
// }

// void nodeTimeAdjustedCallback(int32_t offset) {
//   Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(), offset);
// }

// void setup() {
//   // Start Serial communication
//   Serial.begin(115200);

//   // Initialize the MPU6050
//   Wire.begin();
//   mpu.initialize();

//   // Check if the MPU6050 sensor is connected
//   if (!mpu.testConnection()) {
//     Serial.println("MPU6050 connection failed!");
//     while (1); // Halt if sensor not found
//   }

//   // Set up Mesh Network
//   mesh.setDebugMsgTypes(ERROR | STARTUP);  // Set debug types
//   mesh.init(MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT);
  
//   // Register callbacks for PainlessMesh
//   mesh.onReceive(&receivedCallback);
//   mesh.onNewConnection(&newConnectionCallback);
//   mesh.onChangedConnections(&changedConnectionCallback);
//   mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);

//   // Set up LED pin
//   pinMode(LED_PIN, OUTPUT);
//   digitalWrite(LED_PIN, LOW);  // Make sure LED is off initially
  
//   // Add the sendMessage task to scheduler
//   userScheduler.addTask(taskSendMessage);
//   taskSendMessage.enable();
// }

// void sendMessage() {
//   // Read accelerometer data from the MPU6050
//   int16_t ax, ay, az;
//   mpu.getAcceleration(&ax, &ay, &az);
  
//   // Convert raw data to g (scale factor for 4g range: 8192)
//   ax_g = (float)ax / 8192.0;
//   ay_g = (float)ay / 8192.0;
//   az_g = (float)az / 8192.0;

//   // Print the values to Serial Monitor for debugging
//   Serial.print("Accel X: ");
//   Serial.print(ax_g);
//   Serial.print(" | Accel Y: ");
//   Serial.print(ay_g);
//   Serial.print(" | Accel Z: ");
//   Serial.println(az_g);

//   // Check if the X or Y axis acceleration exceeds the threshold
//   if (abs(ax_g) > threshold || abs(ay_g) > threshold) {
//     // Prepare message
//     String msg = "Accel X: " + String(ax_g) + " | Accel Y: " + String(ay_g) + " | Accel Z: " + String(az_g);

//     // Broadcast the message using PainlessMesh
//     mesh.sendBroadcast(msg);
//     Serial.println("Broadcasting message: " + msg);

//     // Blink LED during the broadcast (500ms total: 250ms on, 250ms off)
//     digitalWrite(LED_PIN, HIGH);  // Turn LED on
//     delay(250);                   // Keep LED on for 250ms
//     digitalWrite(LED_PIN, LOW);   // Turn LED off
//     delay(250);                   // Keep LED off for 250ms

//     // After blinking, stop LED and block further operations for 500ms
//     digitalWrite(LED_PIN, LOW);  // Ensure LED is off after broadcast
//     delay(500);                  // Block for 500ms to avoid multiple broadcasts too quickly

//     // Randomize the next interval for sending the message
//     taskSendMessage.setInterval(random(TASK_SECOND * 1, TASK_SECOND * 5));
//   }
// }

// void loop() {
//   // Update Mesh Network and run the scheduled tasks
//   mesh.update();
// }
