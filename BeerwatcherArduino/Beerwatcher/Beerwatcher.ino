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

void setup(void) {
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  // Start up the library
  sensors.begin();
}

void loop(void) {

  sensors.requestTemperatures();
  sensors.getTempCByIndex(0);

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingMessage = Serial.readString();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(sensors.getTempCByIndex(0));
  }

  delay(100);
}
