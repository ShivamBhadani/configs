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
//   // Variables to hold accelerometer and gyroscope data
//   int16_t ax, ay, az;
//   int16_t gx, gy, gz;

//   // Read accelerometer and gyroscope data from the MPU6050
//   mpu.getAcceleration(&ax, &ay, &az);
//   mpu.getRotation(&gx, &gy, &gz);

//   // Print the accelerometer data to the Serial Monitor
//   Serial.print("Accelerometer (x, y, z): ");
//   Serial.print(ax); Serial.print(", ");
//   Serial.print(ay); Serial.print(", ");
//   Serial.println(az);

//   // Print the gyroscope data to the Serial Monitor
//   Serial.print("Gyroscope (x, y, z): ");
//   Serial.print(gx); Serial.print(", ");
//   Serial.print(gy); Serial.print(", ");
//   Serial.println(gz);

//   delay(500);  // Delay for 500ms before reading the data again
// }
