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
 * 
 * If you need docs just take a look into the '.h' files.
 * ----------------------------------------------------------
 * https://github.com/JohnsProject/Arduios
 * ----------------------------------------------------------
 * 
 * This is the bootloader of the Arduios, it loads the kernel 
 * and is the place where your apps should be registered.
 */
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
    const static uint8_t MAX_APPS = 10;
    const App *apps[MAX_APPS];
    uint8_t currentApp;
  } registry;

  void addApp(App &app);
  // method used to load an app from the registry by its index
  void loadApp(uint8_t app_index);
  // method used to load an app from the registry by its name
  void loadApp(String app_name);
  // method called by the bootloader once when the kernel is loaded
  void setup();
  // method constantly called by the bootloader
  void loop();
} kernel;

#endif
