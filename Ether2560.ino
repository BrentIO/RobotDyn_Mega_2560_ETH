#include <Ethernet.h>

/******************************************
 * Base sketch for the RobotDyn MEGA 2560 ETH R3
 * Sketch brings up Ethernet using DHCP
 * (C) 2020, P5Software, LLC
 */

#define SD_CARD_SS_PIN 4
#define ETHERNET_SS_PIN 10
#define ETHERNET_RESET_PIN 7

const byte mac[6] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

void setup() {

  //Start serial communications
  Serial.begin(115200);

  //Set SD Card and Ethernet pins for output
  pinMode(SD_CARD_SS_PIN, OUTPUT);
  pinMode(ETHERNET_SS_PIN,OUTPUT);
  pinMode(ETHERNET_RESET_PIN,OUTPUT);

  //Disable both SD Card and Ethernet
  digitalWrite(SD_CARD_SS_PIN, HIGH);
  digitalWrite(ETHERNET_SS_PIN, HIGH);

  //Bring up Ethernet
  digitalWrite(ETHERNET_SS_PIN, LOW);
  digitalWrite(ETHERNET_RESET_PIN,HIGH);

  //Start Ethernet
  Ethernet.begin(mac);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {

    //Disable both SD Card and Ethernet
    digitalWrite(SD_CARD_SS_PIN, HIGH);
    digitalWrite(ETHERNET_SS_PIN, HIGH);

    Serial.println("Ethernet shield was not found.");
    Serial.println("System halted.");

    //Put the processor in an infinite loop
    while (true);
  }

  delay(1000);

  if(Ethernet.linkStatus() == LinkON){
    Serial.println("Network link active.");

    //Print the current IP address
    Serial.println(Ethernet.localIP());
    
  }else{
    
    Serial.println("Network link failed.");
    
  }

}

void loop() {

}
