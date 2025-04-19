// #include <Wire.h>
// #include <MPU6050.h>

// // Create an instance of the MPU6050
// MPU6050 mpu;

// void setup() {
//   // Start the serial communication
//   Serial.begin(115200);
  
//   // Initialize I2C communication
//   Wire.begin(21, 22); // SDA -> GPIO21, SCL -> GPIO22

//   // Initialize the MPU6050 sensor
//   Serial.println("Initializing MPU6050...");
//   mpu.initialize();

//   // Check if the sensor is connected
//   if (mpu.testConnection()) {
//     Serial.println("MPU6050 connection successful");
//   } else {
//     Serial.println("MPU6050 connection failed");
//   }

//   delay(1000); // Allow time for the sensor to stabilize
// }

// void loop() {
//   // Variables to store raw accelerometer and gyroscope data
//   int16_t ax, ay, az;
//   int16_t gx, gy, gz;

//   // Read the accelerometer and gyroscope values
//   mpu.getAcceleration(&ax, &ay, &az);
//   mpu.getRotation(&gx, &gy, &gz);

//   // Print the raw accelerometer data (in units of "LSB" - least significant bit)
//   Serial.print("Accelerometer: ");
//   Serial.print("X = ");
//   Serial.print(ax);
//   Serial.print(", Y = ");
//   Serial.print(ay);
//   Serial.print(", Z = ");
//   Serial.println(az);

//   // Print the raw gyroscope data (in units of "LSB")
//   Serial.print("Gyroscope: ");
//   Serial.print("X = ");
//   Serial.print(gx);
//   Serial.print(", Y = ");
//   Serial.print(gy);
//   Serial.print(", Z = ");
//   Serial.println(gz);

//   // Wait a little before the next read
//   delay(500); // Delay in milliseconds
// }
