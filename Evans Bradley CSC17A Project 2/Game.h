/* 
 * File:   Game.h
 * Author: Bradley Evans
 *
 * Created on December 2, 2014, 11:24 AM
 */

#ifndef GAME_H
#define	GAME_H

#include <iostream>
#include "Suspect.h"
using namespace std;

/**Game class, derived from Suspect() class.
 * 
 * 
 */
class Game :
public Suspect {
public:
    Game() :        ///< Game constructor.
        Suspect() { }  
    void showStats();
    virtual ~Game();
private:

};

#endif	/* GAME_H */

