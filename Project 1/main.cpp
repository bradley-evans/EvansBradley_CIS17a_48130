/* 
 * File:   main.cpp
 * Author: Bradley Evans
 *
 * Created on October 10, 2014, 3:30 PM
 */

#include <cstdlib>
#include <iostream>

#include "functions.h"      // keeping my functions off main
#include "classes.h"        // keeping my classes off main
#include "nouns.h"          // nouns
#include "verbs.h"          // verbs
using namespace std;

// FUNCTION DECLARATIONS
        // go here

/*
 * 
 */
    const int MAXL = 50;    // maximum text command length

int main() {
    // Main Variables.
    char command[MAXL];         // character array to store user command
    char *ptrcmd = command;     // character pointer to read user command
    
    // Display introduction
    Gameclock clock;        // tracks time, tick time down using clock.downtick(loss);
    
    clock.initialize();
    
    cout << clock.currtime();
    
    statHeader();
    do {
        readInput(ptrcmd,MAXL);
        clock.downtick(1);
    } while (clock.currtime() > 0);
    
}

