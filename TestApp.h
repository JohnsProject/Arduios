#ifndef __TESTAPP_H_INCLUDED__
#define __TESTAPP_H_INCLUDED__

#include "kernel.h"

/*
 * Simple test app to test the functionality of the Arduios
 * and demontrate how it works.
 */
class TestApp: public App {
  public:
  
    String getName() {
      return "TestApp";
    }
    
    void setup() {
      Serial.println("TestApp begin");
    }
    
    void loop() {
      Serial.println("TestApp loop");
      delay(1000);
    }
} test;

#endif
