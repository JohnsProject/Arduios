#include <Kernel.h>
#include <Shell.h>
#include <TestApp.h>

void setup() {
  kernel.addApp(shell);
  //kernel.addApp(testApp);
  kernel.setup();
}

void loop() {
  kernel.loop();
}
