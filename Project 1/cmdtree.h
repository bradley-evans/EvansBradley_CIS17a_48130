/* 
 * File:   cmdtree.h
 * Author: Bradley Evans
 *
 * Created on October 19, 2014, 5:12 PM
 */

#ifndef CMDTREE_H
#define	CMDTREE_H

#include "functions.h"
#include <iostream>
#include "classes.h"
using namespace std;

// SYNTAX cmd_[noun]_[verb] ()

void cmd_ask_name() {
    Dice dice;
    int result = 0;
    result = dice.roll(100);
    cout << "\nI wonder if I can call suspect attributes..." << suspect.minimize;
    cout << "\nHe told you his name!" << endl;          
}

#endif	/* CMDTREE_H */

