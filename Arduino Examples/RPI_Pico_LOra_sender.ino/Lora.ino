#include <SPI.h>
#include <LoRa.h>

#define CS_PIN 5 // Connects to NSS
#define SCK_PIN 2 // Connects to SCK
#define MISO_PIN 4 // 
#define MOSI_PIN 3 // 
#define reset_PIN 10 // Connects to RST
#define INT_PIN 11 // Connects to DIO0

String outgoing;              // outgoing message
byte msgCount = 0;            // count of outgoing messages

void Lora_setup() {

  SPI.setRX(MISO_PIN);
  SPI.setCS(CS_PIN);
  SPI.setSCK(SCK_PIN);
  SPI.setTX(MOSI_PIN);
  SPI.begin(true);

  delay(5000);

  LoRa.setSPI(SPI);
  LoRa.setPins(CS_PIN, reset_PIN, INT_PIN);

  Serial.print("Starting LORA");

  while (!LoRa.begin(915E6)) {
    Serial.print(".");
    delay(200);
  }

  Serial.println("\tStarted!");

  LoRa.onReceive(onReceive);
  LoRa.receive();
  
}

void sendMessage(String outgoing) {

  Serial.print("Sending message: ");
  Serial.println(outgoing);
  
  LoRa.beginPacket();                   // start packet
//  LoRa.write(destination);              // add destination address
//  LoRa.write(localAddress);             // add sender address
  LoRa.write(msgCount);                 // add message ID
  LoRa.write(outgoing.length());        // add payload length
  LoRa.print(outgoing);                 // add payload
  LoRa.endPacket();                     // finish packet and send it
  msgCount++;                           // increment message ID
  LoRa.receive();
}

void onReceive(int packetSize) {
  if (packetSize == 0) return;          // if there's no packet, return

  digitalWrite(25,HIGH);

  // read packet header bytes:
//  int recipient = LoRa.read();          // recipient address
//  byte sender = LoRa.read();            // sender address
  byte incomingMsgId = LoRa.read();     // incoming msg ID
  byte incomingLength = LoRa.read();    // incoming msg length

  String incoming = "";                 // payload of packet

  while (LoRa.available()) {            // can't use readString() in callback, so
    incoming += (char)LoRa.read();      // add bytes one by one
  }

  if (incomingLength != incoming.length()) {   // check length for error
    Serial.println("error: message length does not match length");
    return;                             // skip rest of function
  }

//  // if the recipient isn't this device or broadcast,
//  if (recipient != localAddress && recipient != 0xFF) {
//    Serial.println("This message is not for me.");
//    return;                             // skip rest of function
//  }

  // if message is for this device, or broadcast, print details:
//  Serial.println("Received from: 0x" + String(sender, HEX));
//  Serial.println("Sent to: 0x" + String(recipient, HEX));
  Serial.println("Message ID: " + String(incomingMsgId));
  Serial.println("Message length: " + String(incomingLength));
  Serial.println("Message: " + incoming);
  PRINT_SCREEN(incoming);
  PRINT_SCREEN("\n");
  PRINT_SCREEN("RSSI: ");
  PRINT_SCREEN(String(LoRa.packetRssi()));
  PRINT_SCREEN("\n");
  Serial.println("RSSI: " + String(LoRa.packetRssi()));
  Serial.println("Snr: " + String(LoRa.packetSnr()));
  Serial.println();

  digitalWrite(25,LOW);

  if(incoming == "PONG"){

    unsigned int ping_time = millis() - now;
    
    PRINT_SCREEN("PING = ");
    PRINT_SCREEN(String(ping_time));
    PRINT_SCREEN("\n");
  };
}
