/* 
 * File:   classes.h
 * Author: Bradley Evans
 *
 * Created on October 10, 2014, 3:32 PM
 */

#ifndef CLASSES_H
#define	CLASSES_H

struct Suspect_s {
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

class Gameclock {                       // To demonstrate the ability to use a class
    int timeleft    = 100;
public:
    void downtick(int);
    int currtime();
};
void Gameclock::downtick(int loss) {
    timeleft = timeleft - loss;
}
int Gameclock::currtime() {
    return(timeleft);
}
#endif	/* CLASSES_H */

