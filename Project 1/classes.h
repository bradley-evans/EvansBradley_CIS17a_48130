/* 
 * File:   classes.h
 * Author: Bradley Evans
 *
 * Created on October 10, 2014, 3:32 PM
 */

#ifndef CLASSES_H
#define	CLASSES_H

// Dependant Files
#include <cstdlib>      // for rand()
#include <time.h>       // to seed random function
#include <ctime>
#include "functions.h"
using namespace std;

struct Suspect_s {                      // Defines the suspect's statistics.     
    // The likelihood the suspect will take a certain action.
    int     minimize,       ///< give minimum amount of cooperation, delay tactic
            silence,        ///< ignore interrogation
            distort,        ///< misinformation, with some truth
            distract;       ///< distract
    // primary three responses
    int     comply,         ///< answer at all
            honest,         ///< be honest
            deception;      ///< be deceptive
    // other modifiers
    int     exhaustion,     ///< tired
            pain,           ///< result of torture
            hatred;         ///< hatred, willingness to do anything to deny information
} suspect;

class Gameclock {                       ///< Tracks in game time remaining
    int timeleft;
public:
    void downtick(int);
    int currtime();
    void initialize();
};

class Dice {
public: 
    int roll (int); // roll dice of (size)
};

struct Scoreboard { // a truth table to store truths as an array of structures
    string ident;
    bool state;
    int num;
};

struct Cmd {
    enum Noun {
    // Interrogation subjects
        name,                   // ask the subject his name
        base,                   // where is the rebel base?
        attack,                 // when will the attack be?
        suspect,                // The person you're interrogating

        invalid
    };
    enum Verb {
        ask,        // ask a question
        quit,       // quit the game
        look,       // look at a thing

        invalid     // verb was invalid           
    };


};
#endif	/* CLASSES_H */

