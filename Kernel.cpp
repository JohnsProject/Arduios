#include "kernel.h"

Kernel kernel;

void Kernel::setup() {
  registry.currentApp = 0;
  registry.apps[registry.currentApp]->setup();
}

void Kernel::loop() {
  registry.apps[registry.currentApp]->loop();
}

void Kernel::addApp(App &app) {
  for (uint8_t i = 0; i < registry.MAX_APPS; i++) {
    if(registry.apps[i] == NULL){
      registry.apps[i] = &app;
      return;
    }
  }
}

void Kernel::loadApp(uint8_t app_index) {
  registry.currentApp = app_index;
  registry.apps[registry.currentApp]->setup();
}

void Kernel::loadApp(String app_name) {
  for (uint8_t i = 0; i < registry.MAX_APPS; i++) {
    if(registry.apps[i] != NULL){
      if (app_name == registry.apps[i]->getName()) {
        registry.currentApp = i;
        registry.apps[registry.currentApp]->setup();
        return;
      }
    }
  }
}
