#include "Shell.h"

Shell shell;

String Shell::getName() {
  return F("Shell");
}

void Shell::setup() {
  Serial.begin(9600);
  Serial.println(F(" -----------------"));
  Serial.println(F("|     Arduios     |"));
  Serial.println(F("|    ---------    |"));
  Serial.println(F("|by John´s Project|"));
  Serial.println(F(" -----------------"));
  Serial.println(F("type help. for help!"));
}

void Shell::loop() {
  String content;
  if (Serial.available() > 0) {
    content = Serial.readStringUntil('.');
    if (content.length() > 0) {
      Serial.print(F("# "));
      Serial.println(content);
      if (content == F("help")) {
        Serial.println(F("commands: list., load:app_name."));
      }
      if (content == F("list")) {
        for (uint8_t i = 1; i <= kernel.registry.appsCount; i++) {
            Serial.println(kernel.registry.apps[i]->getName());
          }
      }
      if (content.substring(0, 5) == F("load:")) {
        content.replace("load:", "");
        kernel.loadApp(content);
      }
    }
  }
}
