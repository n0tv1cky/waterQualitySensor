#define TDSPin A0
#define TURBPin A2
#include "Arduino.h"
#include <SoftwareSerial.h>
const byte rxPin = 2;
const byte txPin = 3;

SoftwareSerial BTSerial(rxPin, txPin);  // RX IX

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);
}

String messageBuffer = "";
String message = "";

void loop() {
  float tdsSensorValue = analogRead(TDSPin);
  float Voltage = tdsSensorValue * 5 / 1024.0;
  float tdsValue = (133.42 * Voltage * Voltage * Voltage - 255.86 * Voltage * Voltage + 857.39 * Voltage);
  Serial.print("TDS Value = ");
  Serial.print(tdsValue);
  Serial.println(" ppm");

  float turbSensorValue = analogRead(TURBPin);
  float turbValue = turbSensorValue * (5.0 / 1024.0);
  Serial.print("Turbidity Value = ");
  Serial.print(turbValue);
  Serial.print(" NTU");

  //print on app
  BTSerial.print(tdsValue);
  BTSerial.print(",");
  BTSerial.print(turbValue/2);
  BTSerial.print(";");

  //print TDS Value
  // message.concat("        TDS = ");
  // message.concat(tdsValue);
  // message.concat(" ppm");
  // Serial.print(message);
  // BTSerial.println(message);
  // message = "";

  // //print Turbidity Value
  // message.concat("Turbidity = ");
  // message.concat(voltage);
  // message.concat(" NTU");
  // Serial.print(message);
  // BTSerial.println(message);
  // message = "";

  // Serial.print(message);
  // BTSerial.println(message);
  delay(500);
}
