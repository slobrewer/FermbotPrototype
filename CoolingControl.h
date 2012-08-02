/*
 * CoolingControl.h
 *
 *  Created on: Aug 1, 2012
 *      Author: dlouw
 */

#ifndef COOLINGCONTROL_H_
#define COOLINGCONTROL_H_

class CoolingControl {
public:
   static void begin();

private:
   static bool initialized;

public:
   CoolingControl();
   virtual ~CoolingControl();
   bool isPoweredOn() const;
   void setPoweredOn(bool poweredOn);

private:
   bool poweredOn;
};

#endif /* COOLINGCONTROL_H_ */
