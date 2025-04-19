// #include <Wire.h>

// void setup() {
//   // Start the serial communication at 9600 baud
//   Serial.begin(9600);
//   // Initialize I2C communication
//   Wire.begin();
  
//   Serial.println("I2C Scanner");
// }

// void loop() {
//   byte error, address;
//   int nDevices = 0;

//   // Scan I2C addresses from 1 to 127
//   for(address = 1; address < 127; address++) {
//     // Try to communicate with each device
//     Wire.beginTransmission(address);
//     error = Wire.endTransmission();
    
//     if (error == 0) {
//       // If the device is found, print the address
//       Serial.print("I2C device found at address 0x");
//       if (address < 16) {
//         Serial.print("0");
//       }
//       Serial.println(address, HEX);
//       nDevices++;
//     }
//     else if (error == 4) {
//       // If there's an error, print a message for the failed address
//       Serial.print("Unknown error at address 0x");
//       if (address < 16) {
//         Serial.print("0");
//       }
//       Serial.println(address, HEX);
//     }
//   }

//   // If no devices are found
//   if (nDevices == 0) {
//     Serial.println("No I2C devices found");
//   }
//   else {
//     Serial.println("I2C scan complete");
//   }
  
//   // Wait a few seconds before starting the scan again
//   delay(5000);
// }
