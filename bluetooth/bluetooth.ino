#include "Arduino.h"
#include <SoftwareSerial.h>
const byte rxPin = 2;
const byte txPin = 3;

SoftwareSerial BTSerial(rxPin, txPin); // RX IX

void setup() {
  pinMode (rxPin, INPUT);
  pinMode (txPin, OUTPUT);
  BTSerial.begin (9600);
  Serial.begin (9600);
}
String messageBuffer = "";
String message = "";

void loop() {
  while (BTSerial.available() > 0) {
    char data = (char)BTSerial.read();
    messageBuffer += data;
    if (data == ';'){
        message = messageBuffer;
        messageBuffer = "";
        Serial.print(message);
        message = "You sent " + message;
        BTSerial.println(message);
    }
  }
}