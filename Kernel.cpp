#include "kernel.h"

Kernel kernel;

void Kernel::setup(App *apps[], uint8_t appsCount) {
  registry.appsCount = appsCount;
  registry.currentApp = 0;
  registry.apps = apps;
  registry.apps[registry.currentApp]->setup();
}

void Kernel::loop() {
  registry.apps[registry.currentApp]->loop();
}

void Kernel::loadApp(uint8_t app_index) {
  registry.currentApp = app_index;
  registry.apps[registry.currentApp]->setup();
}

void Kernel::loadApp(String app_name) {
  for (uint8_t i = 0; i < registry.appsCount; i++) {
    if (app_name == registry.apps[i]->getName()) {
      registry.currentApp = i;
      registry.apps[registry.currentApp]->setup();
    }
  }
}
