/*
 * TempController.cpp
 *
 *  Created on: Aug 1, 2012
 *      Author: dlouw
 */

#include "TempController.h"

#define DEFAULT_FERM_TEMP 68.0f

bool TempController::initialized = false;
float TempController::deadbandRadius = 1.0f;

void TempController::begin() {
   if (!initialized) {
      Thermometer::begin();
      CoolingControl::begin();

      initialized = true;
   }
}

TempController::TempController() {
   this->targetTemp = DEFAULT_FERM_TEMP;
}

TempController::~TempController() {
}

float TempController::readFermentationTempF() {
   return this->thermometer.readTemperatureF();
}

bool TempController::isFermentationTempError() {
   return this->thermometer.isInError();
}

void TempController::setCoolingControl(bool enabled) {
   this->coolingControl.setPoweredOn(enabled);
}

void TempController::processTempControl() {
   float tempF = this->readFermentationTempF();

   if (this->thermometer.isInError()) {
      Serial.println("Error reading temperature.");
      return;
   }

   Serial.println("Processing Temp Control");
   Serial.print("Current Temperature: ");
   Serial.println(tempF);
   Serial.print("Target Temperature: ");
   Serial.println(this->targetTemp);

   if (abs(tempF - this->targetTemp) < this->deadbandRadius) {
      Serial.println("Temperature within deadband. Cooling unchanged.");
   } else if (tempF < this->targetTemp) {
      Serial.println("Temperature below target. Cooling disabled.");
      this->coolingControl.setPoweredOn(false);
   } else {
      Serial.println("Temperature above target. Cooling enabled.");
      this->coolingControl.setPoweredOn(true);
   }
}

bool TempController::getCoolingControlEnabled() {
   return this->coolingControl.isPoweredOn();
}

