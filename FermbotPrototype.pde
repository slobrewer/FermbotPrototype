// Do not remove the include below
#include "FermbotPrototype.h"
#include "TempController.h"

TempController tempController;

//The setup function is called once at startup of the sketch
void setup() {
   // start serial port
   Serial.begin(9600);

   // start the thermometer library
   tempController.begin();
   tempController.setTargetTemp(80.0f);

   Serial.println("Initialized. (Build 011)");
}

void printTemperature()
{
  float tempF = tempController.readFermentationTempF();
  if (tempController.isFermentationTempError()) {
    Serial.print("Error getting temperature");
  } else {
    Serial.print(" F: ");
    Serial.print(tempF);
  }
}

// The loop function is called in an endless loop
void loop() {
   delay(2000);

   tempController.processTempControl();
}
