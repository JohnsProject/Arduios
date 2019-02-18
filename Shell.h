#ifndef __SHELL_H_INCLUDED__
#define __SHELL_H_INCLUDED__

#include "kernel.h"

/*
 *  The Shell app is a simple command line interface, that enables 
 *  you to communicate with the Arduios through the serial monitor.
 *  
 *  Commands:
 *  help. - shows all available commands
 *  list. - shows all available apps
 *  load:app_name. - loads an app from registry
 */
extern class Shell: public App {
  public:

    String getName();
    void setup();
    void loop();
    
} shell;

#endif
