/* 
 * File:   conditions.h
 * Author: Bradley Evans
 *
 * Created on December 4, 2014, 10:57 AM
 */

#ifndef GAMESTATE_H
#define	GAMESTATE_H

#include <ctime>
#include <cstdlib>

/** \brief Stores the state of different game conditions
 * Stores game states such as if an action has been taken, how much time
 * is left, if a question was asked, and so on. */
struct Gamestate {
    const int     NUMOBJECTS = 15;
    int     clock;
    int     pain = 0;
    bool    toldName = false,
            toldAge = false,
            gaveExtension = false,
            truthCapture = false,
            liedCapture = false,
            truthAccent = false,
            liedAccent = false
    ;
    
};

extern Gamestate gamestate;

void startClock();

#endif	/* GAMESTATE_H */

