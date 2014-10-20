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

#include "functions.h"      // general functions, such as localPause() or dicerollers
#include "classes.h"        // keeping my classes off main
#include "nouns.h"          // nouns
#include "verbs.h"          // verbs
#include "cmdtree.h"        // takes in input and starts the parsing tree
using namespace std;

// FUNCTION DECLARATIONS
        // go here

/*
 * 
 */
    const int MAXL = 50;    // maximum text command length

int main() {
    // Main Variables.
    char    command[MAXL];          // character array to store user command
    char    *ptrcmd = command;      // character pointer to read user command
    string  noun;                   // user gives me a noun
    string  verb;                   // user gives me a verb
    Noun    pNoun;                  // A parsed out noun, associated with an enum
    Verb    pVerb;                  // A parsed out verb, associated with an enum
    char    control;                // Control / Command Character
    // Classes and Structures
    Gameclock clock;        // tracks time, tick time down using clock.downtick(loss);
    
    clock.initialize();
    cout << "Initializing suspect.." << endl;
    initializeSuspect();
       
    do {
        cout << "Time remaining: " << clock.currtime() << " ticks.";
        readInput(ptrcmd,MAXL,noun,verb);       // take a command from the user and prepare it for parsing
        clock.downtick(1);                      // decrement the clock
        pNoun = parseNoun(noun);                // parse the noun
        pVerb = parseVerb(verb);                // now parse the verb
        control = validateInput(pVerb,pNoun);   // validate the input
        if (control == 'X') {                   // if input is invalid, say so...
            cout << "I'm sorry, I don't know how to \"" << ptrcmd << ".\"" << endl;
            clock.downtick(-1);                 // ... and don't run out the clock for bad input.
        } else if (control == 'E') {                   // if input is invalid, say so...
            cout << "\nExiting the game..." << endl;
            return 0;    
        } else {
            verbProc(pNoun,pVerb);              // if input is valid, process it
        }
                   
    } while (clock.currtime() > 0);
    
}

