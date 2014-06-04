#include <SPI.h>
#include <Ethernet.h>
#include <SendCarriots.h>         // You must include the library here in order to use it in the sketch

const String APIKEY="YOUR APIKEY HERE"; 		// Replace with your Carriots apikey
const String DEVICE="YOUR DEVICE's ID_DEVELOPER HERE"; 		// Replace with the id_developer of your device
      
const int numElements=3;				// Specify the number of rows in your array, in this case 3

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,27);       // Your IP Address

SendCarriots sender;              // Instantiate an instance of the SendCarriots library

void setup() {
  Serial.begin(9600);             	// Start serial port
  Serial.println(F("Starting"));

  Ethernet.begin(mac,ip);         // Start the Ethernet connection

}

void loop() {
  String array[numElements][2] = {{"Name", "James"}, {"Age", "28"}, {"Gender", "Male"}};  // Define the values of the array to be sent
  Serial.println(sender.send(array, numElements, APIKEY, DEVICE));                 // Using the instance of the library, call the method send
  delay(5000);                                                                								 // Send this stream every 10 seconds
}
