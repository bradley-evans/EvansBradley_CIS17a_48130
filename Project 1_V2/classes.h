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

/**
 * Define's suspect attributes.
 */
struct Suspect_s {                      
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

/**
 * Tracks in game time remaining
 */
class Gameclock {                       
    int timeleft;           
public:
    void downtick(int);    
    int currtime();         
    void initialize();     
};
/**
 * Tracks the number of turns left in game.
 * @param loss How much to decrement the gameclock. Can be a negative number
 */
void Gameclock::downtick(int loss) {    
    timeleft = timeleft - loss;
}
/**
 * Gives the current number of turns remaining.
 * @return Turns remaining.
 */
int Gameclock::currtime() {             
    return(timeleft);
}
/**
 * Initializes the game clock to a random number of turns.
 */
void Gameclock::initialize() {
    srand(time(NULL));
    timeleft = 20 + (rand()%20);
}

/**
 * This class lets me roll a dice from anywhere in the function.
 */
class Dice {                    
public: 
    int roll (int);             ///< roll dice of (size).
};
/**
 * The function within Dice that actually rolls the dice. A little overly complex
 * in order to demonstrate memory allocation.
 * @param size How large the "dice" is -- ie 6 is a 6 sided dice, 100 is a 100 sided dice.
 * @return A random number between 1 and size.
 */
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

/**
 * Tracks and displays high scores.
 */
struct Highscore {          
    int score;      ///< Score as based off of the total from truthstold and liestold.
    string name;    ///< Players name.
} scores[10];

#endif	/* CLASSES_H */

