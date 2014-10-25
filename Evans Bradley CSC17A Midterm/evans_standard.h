/* 
 * File:   evans_standard.h
 * Author: Bradley Evans
 * Standard set of functions common across homework assignments.
 * Created on October 24, 2014, 12:55 AM
 */

#ifndef EVANS_STANDARD_H
#define	EVANS_STANDARD_H

#include <iostream>
using namespace std;

void displayMenu (char& choice);        ///< Displays the primary menus.
bool replayFunc (char& localChoice);    ///< Manages do-while loops for replaying functions.
void localPause ();                     ///< Replaces cstdlib pause.
void clearbuffer ();                    ///< clears the input buffer

#endif	/* EVANS_STANDARD_H */

