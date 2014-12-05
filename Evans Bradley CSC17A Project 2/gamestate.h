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

struct Gamestate {
    const int NUMOBJECTS = 3;
    int     clock;
    bool    toldName = false,
            toldAge = false;
} gamestate;

#endif	/* GAMESTATE_H */

