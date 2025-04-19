// #include <Wire.h>
// #include <MPU6050.h>

// // Create an MPU6050 object
// MPU6050 mpu;

// void setup() {
//   Serial.begin(115200);
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
// }

// void loop() {
//   // Variables to hold accelerometer data
//   int16_t ax, ay, az;

//   // Read accelerometer data from the MPU6050
//   mpu.getAcceleration(&ax, &ay, &az);

//   // Convert the raw accelerometer data to 'g' (gravitational units)
//   float ax_g = ax / 16384.0;
//   float ay_g = ay / 16384.0;
//   float az_g = az / 16384.0;

//   // Print the accelerometer data in g to the Serial Monitor
//   Serial.print("Accelerometer (x, y, z) in g: ");
//   Serial.print(ax_g, 4);  // 4 decimal places for precision
//   Serial.print(", ");
//   Serial.print(ay_g, 4);
//   Serial.print(", ");
//   Serial.println(az_g, 4);

//   delay(500);  // Delay for 500ms before reading the data again
// }
