/*
 * TempController.h
 *
 *  Created on: Aug 1, 2012
 *      Author: dlouw
 */

#ifndef TEMPCONTROLLER_H_
#define TEMPCONTROLLER_H_

#include "Thermometer.h"
#include "CoolingControl.h"

class TempController {
public:
   static void begin();

private:
   static bool initialized;
   static float deadbandRadius;

public:
   TempController();
   virtual ~TempController();

   float readFermentationTempF();
   bool isFermentationTempError();

   float getTargetTemp() const {
      return targetTemp;
   }

   void setTargetTemp(float targetTemp) {
      this->targetTemp = targetTemp;
   }

   void processTempControl();

   void setCoolingControl(bool enabled);
   bool getCoolingControlEnabled();

private:
   Thermometer thermometer;
   CoolingControl coolingControl;
   float targetTemp;
};

#endif /* TEMPCONTROLLER_H_ */
