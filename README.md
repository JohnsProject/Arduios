# Arduios
Arduios is like a operating system for the arduino, it enables you to use a sketch in different use cases, without having to upload a new one every time.

## Usage
It's very simple to use the Arduios, as it has a simple shell app that enables you to communicate with it through the serial monitor of the Arduino IDE.

The Commands are
```
help. - shows all available commands
list. - shows all available apps
load:app_name. - loads an app from registry
```
Note that theres alway a point behind them. This is needed because of the way the shell works.

## Creating your own apps
It's also very simple to create your own Arduios apps.

First you need to download the latest Arduios release, with that done, create a new sketch and add the ``Arduios.zip`` to the Arduino IDE libraries. Now add a new file to the sketch called ``TestApp.h ``.

This is how a basic Arduios app looks like
```c++
#ifndef __TESTAPP_H_INCLUDED__
#define __TESTAPP_H_INCLUDED__

#include <Arduios_Kernel.h>

class TestApp: public App {
    
    String getName() {
      // return your app name here
      return "TestApp";
    }
    
    void setup() {
      // put your setup code here, to run once:
      Serial.begin(9600);
      Serial.println("TestApp begin");
    }
    
    void loop() {
      // put your main code here, to run repeatedly:
      Serial.println("TestApp loop");
      delay(1000);
    }
    
} testApp;

#endif
```

To finish you need to add the app to the ``kernel`` and call the ``kernel.setup()`` and ``kernel.loop()`` methods.
Your sketch should look like this:

```c++
#include <Arduios_Kernel.h>
#include "TestApp.h"

void setup() {
  kernel.addApp(testApp);
  kernel.setup();
}

void loop() {
  kernel.loop();
}
```

Congrats! you've just created your first Arduios app.

## Screenshot
![Screenshot](Screenshot.PNG "Screenshot of Arduios shell")
