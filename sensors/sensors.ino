#define TDSPin A0
#define TURBPin A2

int sensorValue = 0;
float tdsValue = 0;
float Voltage = 0;

void setup() {
    Serial.begin(9600);
}
void loop() {
    sensorValue = analogRead(TDSPin);
    Voltage = sensorValue*5/1024.0;
    tdsValue=(133.42*Voltage*Voltage*Voltage - 255.86*Voltage*Voltage + 857.39*Voltage)*0.5; //Convert voltage value to TDS value
    Serial.print("TDS Value = "); 
    Serial.print(tdsValue);
    Serial.println(" ppm");
    int sensorValue = analogRead(TURBPin);
    float voltage = sensorValue * (5.0 / 1024.0);
    Serial.print("Turbidity Value = "); 
    Serial.print(voltage);
    Serial.println(" NTU");
    delay(500);
}