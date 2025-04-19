// #define IN1 5    // GPIO 5 to IN1
// #define IN2 4    // GPIO 4 to IN2
// #define IN3 0    // GPIO 0 to IN3
// #define IN4 2    // GPIO 2 to IN4
// #define nSLEEP 14 // Pin to wake up the motor driver

// void setup() {
//   // Initialize the control pins as output
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(IN3, OUTPUT);
//   pinMode(IN4, OUTPUT);
//   pinMode(nSLEEP, OUTPUT);
  
//   // Wake up the DRV8833 by setting nSLEEP high
//   digitalWrite(nSLEEP, HIGH);
// }

// void loop() {
//   // Reverse direction for motor A (backward)
//   digitalWrite(IN1, LOW);   // IN1 low
//   digitalWrite(IN2, HIGH);  // IN2 high
  
//   // Reverse direction for motor B (backward)
//   digitalWrite(IN3, LOW);   // IN3 low
//   digitalWrite(IN4, HIGH);  // IN4 high
  
//   delay(2000);  // Run motors in reverse for 2 seconds
  
//   // Stop motors
//   digitalWrite(IN1, LOW);   // IN1 low
//   digitalWrite(IN2, LOW);   // IN2 low
//   digitalWrite(IN3, LOW);   // IN3 low
//   digitalWrite(IN4, LOW);   // IN4 low
  
//   delay(5000);  // Wait for 5 seconds before repeating
// }
