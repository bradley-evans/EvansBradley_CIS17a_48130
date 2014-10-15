/* 
 * File:   functions.h
 * Author: Bradley Evans
 *
 * Created on October 10, 2014, 3:32 PM
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#ifdef	__cplusplus

// Function dependencies --
#include <iostream>
#include "classes.h"
using namespace std;
// ------------------------
void testFunc()
{
    cout << "Header file 'functions.h' linked successfully.\n";
}

void statHeader() // display suspect stats in realtime
{
    cout    << "\n------------------------------------------------------------" << endl;
    cout    << "CURRENT SUSPECT STATS (DEBUG MODE):" << endl
            << "FEAR: " << suspect.fear << " || HATRED:      " << suspect.hatred << " || FATIGUE:    " << suspect.stamina << endl
            << "PAIN: " << suspect.pain << " || DESPERATION: " << suspect.desperation << " || WILLPOWER: " << suspect.willpower << endl;
    cout    << "------------------------------------------------------------" << endl;
    
}

#endif




#ifdef	__cplusplus

#endif

#endif	/* FUNCTIONS_H */

