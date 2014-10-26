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

#endif	/* CLASSES_H */

