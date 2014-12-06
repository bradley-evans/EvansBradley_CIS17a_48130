/* 
 * File:   Game.cpp
 * Author: Bradley Evans
 * 
 * Created on December 2, 2014, 11:24 AM
 */

#include "Game.h"


Game::~Game() { }

void Game::showStats() {    
    cout    << "================================" << endl
            << "Suspect Statistics (Debug Mode):" << endl
            << "Intelligence: " << intelligence << endl
            << "Deception: " << deception << endl
            << "Loyalty: " << loyalty << endl
            << "Honesty: " << honesty << endl
            << "Exhaustion: " << exhaustion << endl
            << "Trust: " << trust << endl
            << "================================" << endl;
}

