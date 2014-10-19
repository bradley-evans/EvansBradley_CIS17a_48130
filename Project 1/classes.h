/* 
 * File:   classes.h
 * Author: Bradley Evans
 *
 * Created on October 10, 2014, 3:32 PM
 */

#ifndef CLASSES_H
#define	CLASSES_H
// Dependant Files
#include <time.h>       // to seed random function
using namespace std;

struct Suspect_s {                      // Defines the suspect's statistics.     
    // Primary Attributes
    int fear;                       // coercion -- affects fatigue, desperation
    int hatred;                     // random, represents suspect's likelihood to cooperate
    int stamina;                    // affects fatigue loss
    int intelligence;               // reason -- affects ability to form deceptions
    int loyalty;                    // threaten -- represents suspect's likelihood to lie
    int willpower;                  // represents suspect's resistance to coercion
    // Derived Attributes
    int deception;                  // intelligence, loyalty, hatred
    int desperation;                // fear, fatigue, pain
    int pain;                       // user manipulated
    int fatigue;                    // stamina
} suspect;

class Gameclock {                       // Tracks in game time remaining
    int timeleft;
public:
    void downtick(int);
    int currtime();
    void initialize();
};
void Gameclock::downtick(int loss) {    // To decrement the time counter.
    timeleft = timeleft - loss;
}
int Gameclock::currtime() {             // Displays time remaining.
    return(timeleft);
}
void Gameclock::initialize() {
    int randTime;
    srand(time(NULL));
    timeleft = 20 + (rand()%20);
}

// VERBS
st
#endif	/* CLASSES_H */

