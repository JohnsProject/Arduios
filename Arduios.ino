/*
 * Arduios
 * by John´s Project
 * 
 * Arduios is like a operating system for the arduino, 
 * it enables you to use a sketch in different use cases, 
 * without having to upload a new one every time.
 * 
 * You can easily write an app by including "kernel.h", 
 * extending and implementing the methods of the App class
 * and registering it in the apps array here.
 * (App class is in "kernel.h") 
 * ----------------------------------------------------------
 * 
 * This is the bootloader of the Arduios, it loads the kernel 
 * and is the place where your apps should be registered.
 */
 
#include "Kernel.h"

#include "Shell.h"
#include "TestApp.h"

// the kernel will call the first app in the array when its loaded
const App *apps[] = {
  &shell,
  //&testApp // uncomment to enable TestApp
  };

void setup() {
  kernel.setup(apps);
}

void loop() {
  kernel.loop();
}
