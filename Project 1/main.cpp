/* 
 * File:   main.cpp
 * Author: Bradley Evans
 *
 * Created on October 10, 2014, 3:30 PM
 * 
 * Some functions are very specific to C++11, such as "enum class" used in the parser.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <string>

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
    char    command[MAXL];         // character array to store user command
    char    *ptrcmd = command;     // character pointer to read user command
    string  noun;                // user gives me a noun
    string  verb;                // user gives me a verb
    // Classes and Structures
    Gameclock clock;        // tracks time, tick time down using clock.downtick(loss);
    
    clock.initialize();
       
    do {
        cout << "Time remaining: " << clock.currtime() << " ticks.";
        statHeader();
        readInput(ptrcmd,MAXL,noun,verb);
        clock.downtick(1);
                
        cout    << "Verb:               " << verb << endl
                << "Noun:               " << noun << endl;
        
        cout    << "Parseverb output:   " << parseVerb(verb) << endl;
        cout    << "Parsenoun output:   " << parseNoun(noun) << endl;
        
    } while (clock.currtime() > 0);
    
}

