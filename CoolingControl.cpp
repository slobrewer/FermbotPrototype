/*
 * CoolingControl.cpp
 *
 *  Created on: Aug 1, 2012
 *      Author: dlouw
 */

#include <Arduino.h>
#include "CoolingControl.h"

#define CONTROL_PIN 5

bool CoolingControl::initialized = false;

void CoolingControl::begin() {
   if (!initialized) {
      pinMode(CONTROL_PIN, OUTPUT);

      initialized = true;
   }
}

CoolingControl::CoolingControl() {
}

CoolingControl::~CoolingControl() {
}

bool CoolingControl::isPoweredOn() const {
   return poweredOn;
}

void CoolingControl::setPoweredOn(bool poweredOn) {
   this->poweredOn = poweredOn;

   if (this->poweredOn) {
      digitalWrite(CONTROL_PIN, HIGH);
   } else {
      digitalWrite(CONTROL_PIN, LOW);
   }
}


