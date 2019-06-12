#include "Arduios_Kernel.h"
#include "Arduios_Shell.h"
#include "Arduios_TestApp.h"

void setup() {
  kernel.addApp(shell);
  kernel.addApp(testApp);
  kernel.setup();
}

void loop() {
  kernel.loop();
}
