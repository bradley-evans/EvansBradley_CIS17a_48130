/* 
 * File:   main.cpp
 * Author: Bradley Evans
 *
 * Created on October 10, 2014, 3:30 PM
 * 
 * Some functions are very specific to C++11, such as "enum class" used in the parser.
 * Checklist from the midterm assignment description:
 * 
 * [ ] Memory allocation
 * [X] Functions with structures
 *      See "classes.h" The diceroller used in this system includes functions with
 *      structures. The gameclock is initialized and iterated in this way as well.
 * [X] Pointers with arrays and arrays of structures, internally as well as externally.
 *      The way that commands are processed and parsed demonstrates this with a character
 *      array.
 * 
 */

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
    const int MAXL = 50;    // maximum character array length

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
    initializeSuspect();
    
    introduction();
       
    do {
        cout << "\nTime remaining: " << clock.currtime() << " turns.";
        readInput(ptrcmd,MAXL,noun,verb);       // take a command from the user and prepare it for parsing
        clock.downtick(1);                      // decrement the clock
        pNoun = parseNoun(noun);                // parse the noun
        pVerb = parseVerb(verb);                // now parse the verb
        control = validateInput(pVerb,pNoun);   // validate the input
        if (control == 'X') {                   // if input is invalid, say so...
            cout << "I'm sorry, I don't know how to \"" << ptrcmd << ".\"" << endl;
            clock.downtick(-1);                 // ... and don't run out the clock for bad input.
        } else if (control == 'E') {            // if an exit condition is detected, then exit the game
            cout << "\nExiting the game..." << endl;
            return 0;    
        } else {
            verbProc(pNoun,pVerb);              // if input is valid, process it
        }
                   
    } while (clock.currtime() > 0);
    
}

