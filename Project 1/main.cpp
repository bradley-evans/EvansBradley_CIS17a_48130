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
using namespace std;

// FUNCTION DECLARATIONS
        // go here

/*
 * 
 */
int main() {
    // Display introduction
    Gameclock clock;        // tracks time, tick time down using clock.downtick(loss);
    
    clock.initialize();
    cout << clock.currtime();
    
    statHeader();
    
}

