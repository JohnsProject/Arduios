#ifndef __TESTAPP_H_INCLUDED__
#define __TESTAPP_H_INCLUDED__

#include "Arduios_Kernel.h"

/*
 * Simple test app to test the functionality of the Arduios
 * and demontrate how it works.
 */
class TestApp: public App {
    
    String getName() {
      // return your app name here
      return F("TestApp");
    }
    
    void setup() {
      // put your setup code here, to run once:
      Serial.begin(9600);
      Serial.println(F("TestApp begin"));
    }
    
    void loop() {
      // put your main code here, to run repeatedly:
      Serial.println(F("TestApp loop"));
      delay(1000);
    }
    
} testApp;

#endif
