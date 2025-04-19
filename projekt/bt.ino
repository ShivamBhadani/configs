// #include <BluetoothSerial.h>  // Include BluetoothSerial library for Classic Bluetooth

// BluetoothSerial SerialBT;  // Create Bluetooth serial object

// void setup() {
//   Serial.begin(115200);  // Start serial communication (for debugging)
  
//   // Add delay to avoid issues during initialization
//   delay(2000);  // Wait for 2 seconds to allow the ESP32 to initialize properly

//   // Initialize Bluetooth
//   if (!SerialBT.begin("ESP32_Device")) {  // Set the Bluetooth name
//     Serial.println("Bluetooth initialization failed!");
//     return;
//   }

//   // Indicate that Bluetooth is ready
//   Serial.println("Bluetooth device is ready to pair!");
  
//   // Add some more delay to allow Bluetooth to be discoverable
//   delay(5000);  // Give some time to make the ESP32 discoverable

//   Serial.println("Now you can pair with the ESP32 via Bluetooth.");
// }

// void loop() {
//   // Placeholder loop, we can add logic here to handle Bluetooth commands
//   if (SerialBT.available()) {
//     char received = SerialBT.read();  // Read incoming Bluetooth data
//     Serial.print("Received: ");
//     Serial.println(received);
    
//     // Respond back over Bluetooth
//     SerialBT.write(received);
//   }
// }
