#ifndef __KERNEL_H_INCLUDED__
#define __KERNEL_H_INCLUDED__

#include <Arduino.h>

/*
 *  The App class enables the kernel to communicate with your apps, that is why
 *  your app class should always extend and implement the methods of this class,
 *  and should then be registered in the apps array of the Arduios bootloader.
 */
class App {
  public:
    // method used to access the name of your app
    virtual String getName() = 0;
    // method called by the kernel once when the app is loaded
    virtual void setup() = 0;
    // method constantly called by the kernel
    virtual void loop() = 0;
};

extern struct Kernel {

  struct Registry {
    App **apps;
    uint8_t appsCount;
    uint8_t currentApp;
  } registry;

  // method used to load an app from the registry by its index
  void loadApp(uint8_t app_index);
  // method used to load an app from the registry by its name
  void loadApp(String app_name);
  // method called by the bootloader once when the kernel is loaded
  void setup(App *apps[]);
  // method constantly called by the bootloader
  void loop();
} kernel;

#endif
