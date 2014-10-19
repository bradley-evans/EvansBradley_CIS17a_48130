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
#include <string>
#include <cstring>
#include "classes.h"
using namespace std;
// ------------------------
void localPause ()
{
        cout << endl;
        cin.ignore();
        cout << "Press [ENTER] to continue...";
        cin.get();
        cout << endl;
}

void statHeader() // display suspect stats in realtime
{
    cout    << "\n------------------------------------------------------------" << endl;
    cout    << "CURRENT SUSPECT STATS (DEBUG MODE):" << endl
            << "FEAR: " << suspect.fear << " || HATRED:      " << suspect.hatred << " || FATIGUE:    " << suspect.stamina << endl
            << "PAIN: " << suspect.pain << " || DESPERATION: " << suspect.desperation << " || WILLPOWER: " << suspect.willpower << endl;
    cout    << "------------------------------------------------------------" << endl;
    
}

void readInput (char* &command, int MAXL) // take in the user's command
{
    int     i = 0;      // iterator 1
    int     n = 0;      // iterator 2
    
    char    cstrnoun[MAXL];         // cstring for the inbound noun
    char    cstrverb[MAXL];         // cstring for the inbound verb
    char    *nounptr = cstrnoun;    // cstring pointer, noun
    char    *verbptr = cstrverb;    // cstring pointer, verb
    bool    invalidInput;           // is the input valid?
    int     inputLength;            // total length of the string
    
    string  noun = " ";
    string  verb = " ";
    
    cin.clear();
    cout    << "\nPlease enter your command. Use a verb followed by a noun such as 'ask name.'" << endl
            << "> ";
    cin.getline(command,MAXL);          // get your command
    inputLength = cin.gcount();         // how long was last input?
    cout    << "\nYour command was: " << command << endl;
    
    // Parse the command into a noun or a verb.
    
    do {
        cstrverb[i]=command[i];        
        i++;
    } while (command[i] != ' ');
    cstrverb[i] = '\0';             // place a delimiter character at the end of the noun
    i++;
    
    do {
        cstrnoun[n]=command[i];
        i++;
        n++;
    } while (i < inputLength);
    for (i=0;i<n;i++) {
        if (cstrnoun[i]==' ') {
            cstrnoun[i] = '\0';
            i=n;
        }
    }
          
        noun = nounptr;
        verb = verbptr;
        cout    << "change ok 1114\n";
        cout    << "Verb: " << verb << endl
                << "Noun: " << noun << endl;
    
}
       

#endif




#ifdef	__cplusplus

#endif

#endif	/* FUNCTIONS_H */

