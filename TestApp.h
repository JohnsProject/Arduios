#ifndef __TESTAPP_H_INCLUDED__
#define __TESTAPP_H_INCLUDED__

#include "Kernel.h"

/*
 * Simple test app to test the functionality of the Arduios
 * and demontrate how it works.
 */
class TestApp: public App {
    
    String getName() {
      // return your apps name here
      return "TestApp";
    }
    
    void setup() {
      // put your setup code here, to run once:
      Serial.println("TestApp begin");
    }
    
    void loop() {
      // put your main code here, to run repeatedly:
      Serial.println("TestApp loop");
      delay(1000);
    }
    
} testApp;

#endif
