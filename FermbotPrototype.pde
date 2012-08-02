// Do not remove the include below
#include "FermbotPrototype.h"
#include "Thermometer.h"

#include <DallasTemperature.h>

Thermometer thermometer;

//The setup function is called once at startup of the sketch
void setup() {
   // start serial port
   Serial.begin(9600);

   // start the thermometer library
   thermometer.begin();

   Serial.println("Initialized.  (Build 003)");
}

void printTemperature()
{
  float tempF = thermometer.readTemperatureF();
  if (thermometer.isInError()) {
    Serial.print("Error getting temperature");
  } else {
    Serial.print(" F: ");
    Serial.print(tempF);
  }
}

// The loop function is called in an endless loop
void loop() {
   delay(2000);

   Serial.print("Getting temperatures...\n\r");

   Serial.print("Inside temperature is: ");
   printTemperature();
   Serial.print("\n\r\n\r");
}
