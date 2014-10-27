/* 
 * File:   main.cpp
 * Author: Bradley Evans
 *
 * Created on October 10, 2014, 3:30 PM
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

    const int MAXL = 50;    ///< maximum character array length

int main() {
    // Main Variables.
    char    command[MAXL];          ///< character array to store user command
    char    *ptrcmd = command;      ///< character pointer to read user command
    string  noun;                   ///< user gives me a noun
    string  verb;                   ///< user gives me a verb
    Noun    pNoun;                  ///< A parsed out noun, associated with an enum
    Verb    pVerb;                  ///< A parsed out verb, associated with an enum
    char    control;                ///< Control / Command Character
    // Classes and Structures
    Gameclock clock;        ///< tracks time, tick time down using clock.downtick(loss);
    
    clock.initialize();
    initializeSuspect();
    zeroScores();
    
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
            totalScores();                      // show high scores
            return 0;    
        } else {
            verbProc(pNoun,pVerb);              // if input is valid, process it
        }
                   
    } while (clock.currtime() > 0);
    totalScores();                              // show high scores
}



/*! \mainpage Interrogation: A Game about Questioning Suspects
 *
 * \section intro_sec Introduction
 *
 * This game is meant to take place in a single room, with the player acting as
 * interrogator questioning a terrorism suspect. The player will reveal different
 * new [subjects] through interrogation, and based on how the questions are asked
 * and how different coercion techniques are employed, the suspect will either
 * tell the truth, lie, or not answer at all.
 * 
 * The suspect is governed by statistics that are generated randomly before each
 * session, and a general description of the suspect is given based on what each
 * statistic reads.
 *
 * \section known_issues Known Problems
 *
 * This build does not have complete functionality. For one thing, the only command
 * that works with any real reliability is "ask name," and there are a few strange
 * input errors related to my implementation of getline. This program is meant
 * more as a proof of concept -- a skeleton upon which to build a more complex
 * and detail-rich game.
 * 
 * I attempted to follow conventions for header and external .cpp files, but when
 * I began moving functions out of the header files and into proper .cpp files,
 * the program ceased to compile. Documentation of the worst error was posted here
 * on StackExchange:
 * 
 * http://stackoverflow.com/questions/26569177/compiler-error-enumerated-class-was-not-declared-in-this-scope?noredirect=1#comment41758610_26569177
 * 
 * Sometimes, when the command 'quit' is used, the game crashes rather than exits
 * normally.
 * 
 * \section explain How it Works
 * 
 * 1 - User enters a command
 * 2 - Command is taken as a cstring and parsed out into two std::strings, assuming
 *      that the first word is a verb and the second is a noun.
 * 3 - The std::strings are compared against maps of nouns and verbs, and then
 *      converted into an associated enumerated value.
 * 4 - The enumerated values then drive switch statements which decide what output
 *      to give to the user.
 * 5 - Outcomes, statistics, the "truth table," and other ingame conditions are
 *      modified by the choice, and then a new command is requested.
 * 
 * \section requirements Assignment Requirements
 * 
 * \subsection malloc Memory allocation
 * 
 * An admittedly crude example of this can be found in the Dice class.
 * 
 * \subsection structs Functions with structures
 *     
 * See "classes.h" The diceroller used in this system includes functions with
 * structures. The gameclock is initialized and iterated in this way as well.
 * 
 * \subsection arraystructs Pointers with arrays and arrays of structures, internally as well as externally.
 * 
 * Commands in this game are taken in by character arrays and passed around by
 * reference to other parts of the parsing process.
 * 
 * An "array of structures" was implemented to record "high scores" in functions.h,
 * the totalScores function.
 * 
 * A 2D array is implemented in printLine(); under cmdtree.
 * 
 */