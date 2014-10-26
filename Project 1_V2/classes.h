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

struct Suspect_s {                      ///< Defines the suspect's statistics.     
    // The likelihood the suspect will take a certain action.
    int     minimize,       ///< give minimum amount of cooperation, delay tactic
            silence,        ///< ignore interrogation
            distort,        ///< misinformation, with some truth
            distract;       ///< distract
    // primary three responses
    int     comply,         ///< answer at all, may be redundant with silence.
            honest,         ///< be honest
            deception;      ///< be deceptive
    // other modifiers
    int     exhaustion,     ///< tired, increases every single turn
            pain,           ///< result of torture
            hatred;         ///< hatred, willingness to do anything to deny information
    int     truthtold[15];  ///< tracks specific truths told by suspect
    int     liestold[15];   ///< tracks specific lies told by suspect
} suspect;

class Gameclock {                       // Tracks in game time remaining
    int timeleft;           ///< How much time is left ingame?
public:
    void downtick(int);     ///< Decrements the clock by a given number (handy for a "wait" command).)
    int currtime();         ///< Output the current time remaining.
    void initialize();      ///< Initialize the clock to a random time.
};
void Gameclock::downtick(int loss) {    
    timeleft = timeleft - loss;
}
int Gameclock::currtime() {             
    return(timeleft);
}
void Gameclock::initialize() {
    srand(time(NULL));
    timeleft = 20 + (rand()%20);
}

class Dice {                    ///< This class lets me roll a dice from anywhere in the function.
public: 
    int roll (int);             ///< roll dice of (size). Unnecessarily complex on purpose to demonstrate skill with memory allocation.
};
int Dice::roll (int size) {  
    int result;
    int *arr;
    
    srand(clock());
    arr = new int[size];
    for (int i=0;i<size;i++) {
        arr[i]=(rand()%size);
    }
    result = arr[size-1];
    delete []arr;
    // Delay, to ensure the same time isn't used for each dice roll accidentally.
    clock_t start_time = clock();
    clock_t end_time = 10 + start_time;
    do { /* nothing */ } while ( clock() < end_time);
    return(result);
}

struct Highscore {          ///< Show the ~high scores~, also demonstrates an array of structures.
    int score;
    string name;
} scores[10];

#endif	/* CLASSES_H */

