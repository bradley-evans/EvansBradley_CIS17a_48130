/* 
 * File:   functions.h
 * Author: Bradley Evans
 *
 * Created on October 10, 2014, 3:32 PM
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H
// Function dependencies --
#include <iostream>
#include <string>
#include <cstring>
#include "classes.h"
#include "verbs.h"
#include "classes.h"
#include "cmdtree.h"
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

void readInput (char* &command, int MAXL, string &noun, string &verb) // take in the user's command
{
    int     i = 0;      // iterator 1
    int     n = 0;      // iterator 2
    
    char    cstrnoun[MAXL];         // cstring for the inbound noun
    char    cstrverb[MAXL];         // cstring for the inbound verb
    char    *nounptr = cstrnoun;    // cstring pointer, noun
    char    *verbptr = cstrverb;    // cstring pointer, verb
    bool    invalidInput;           // is the input valid?
    int     inputLength;            // total length of the string
        
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
}


char verifyExit(char exitChoice)
{
    bool loop;
    cout    << "\nAre you sure you want to quit? You will lose all progress! [Y/N]" << endl
            << "> ";
    cin     >> exitChoice;
    do {
        switch (exitChoice) {
            case 'y':   return('E');
            case 'Y':   return('E');
            case 'n':   return('0');
            case 'N':   return('0');
        }
    } while (loop);
}

char validateInput (Verb verb, Noun noun)
{
    char exitChoice = 'n';
    char control;       // control char
    if (verb == Verb::invalid) {
        return('X');
    } else if (verb == Verb::quit) {
        return(verifyExit(exitChoice));
    }
    if (noun == Noun::invalid) {
        return('X');
    }
}


void initializeSuspect()
{
    Dice dice;
    
    suspect.minimize    = 50 + dice.roll(50);
    suspect.silence     = 50 + dice.roll(50);
    suspect.distort     = 50 + dice.roll(50);
    suspect.distract    = 50 + dice.roll(50);
    suspect.comply      = 50 + dice.roll(50);
    suspect.honest      = 50 + dice.roll(50);
    suspect.deception   = 50 + dice.roll(50);
    
    // debug
    cout    << "Minimize: " << suspect.minimize
            << "Silence:  " << suspect.silence;
}
void introduction()
{
    cmd_look_suspect();
}

#endif	/* FUNCTIONS_H */

