/********************************************************************/
// First we include the libraries
#include <DallasTemperature.h>
#include <OneWire.h>
/********************************************************************/
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
/********************************************************************/

String incomingMessage = "";
unsigned long countSinceLastRead = 0;

void setup(void) {
  // start serial port
  Serial.begin(115200);
  Serial.println("Running");
  // Start up the library
  sensors.begin();
}

void loop(void) {

  while (Serial.available() > 0) {
    handleIncomingMessage();
  }
  countSinceLastRead = countSinceLastRead +1;
  delay(1);
}

void handleIncomingMessage(){
  
  incomingMessage = Serial.readString();
  if(incomingMessage == "t"){      
    sensors.requestTemperatures();
    delay(2);
    Serial.println(String(sensors.getTempCByIndex(0)));
  }else if(incomingMessage == "b"){
    Serial.println(countSinceLastRead);
    countSinceLastRead = 0;
  }else {
     Serial.println("Unknown input" + String(incomingMessage));
    }
}
