/* 
 * File:   functions.h
 * Author: Bradley Evans
 *
 * Created on October 10, 2014, 3:32 PM
 */

#ifndef FUNCTIONS_H     // if not defined
#define	FUNCTIONS_H     // then define
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
void localPause ()      ///< A local pause function to replace cstdlib's system(pause), which doesn't work for me for whatever reason.
{
        cout << endl;
        cin.ignore();
        cout << "Press [ENTER] to continue...";
        cin.get();
        cout << endl;
}

void readInput (char* &command, const int MAXL, string &noun, string &verb) ///< Accepts the user's input as a cstring and turns it into two std::strings, named noun and verb.
{
    int     i = 0;      // iterator 1
    int     n = 0;      // iterator 2
    
    char    cstrnoun[MAXL];         // cstring for the inbound noun
    char    cstrverb[MAXL];         // cstring for the inbound verb
    char    *nounptr = cstrnoun;    // cstring pointer, noun
    char    *verbptr = cstrverb;    // cstring pointer, verb
    int     inputLength;            // total length of the string
        
    cin.clear();
    cin.ignore(10000,'\n');
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


char verifyExit(char exitChoice) ///< Verifies you Really Really want to exit.
{
    bool loop = true;
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
    return ('0');
}

char validateInput (Verb verb, Noun noun) ///< Input validation, which occurs *after* parsing.
{
    char exitChoice = 'n';
    if (verb == Verb::invalid) {
        return('X');
    } else if (verb == Verb::quit) {
        return(verifyExit(exitChoice));
    }
    if (noun == Noun::invalid) {
        return('X');
    }
    return('0');
}


void initializeSuspect() ///< Iniitalizes the suspect's statistics.
{
    Dice dice;
    
    suspect.minimize    = 50 + dice.roll(50);
    suspect.silence     = 50 + dice.roll(50);
    suspect.distort     = 50 + dice.roll(50);
    suspect.distract    = 50 + dice.roll(50);
    suspect.comply      = dice.roll(10);
    suspect.honest      = dice.roll(10);
    suspect.deception   = dice.roll(10);
    
    // debug
    cout    << "Minimize: " << suspect.minimize
            << "Silence:  " << suspect.silence;
}
void introduction() ///< Play an introduction.
{
    cmd_look_suspect();
}

void zeroScores() {     ///< Zeroes out the truth tables, initializing them for a new game.
    int i = 0;
    for (i=0;i<15;i++) {
        suspect.truthtold[i]=0;
        suspect.liestold[i]=0;
    }
}

void totalScores() {    ///< Show and record the high scores. Demonstrates array of structures funcitonality.3
    int total=1;
    int position;
    int i=0;
    for (i=0;i<15;i++) {
        total = total + suspect.truthtold[i];
        total = total - suspect.liestold[i];
    }
    i = 0;
    do {
        if (scores[i].score > total) {
            i++;
        } else if (scores[i].score < total ) {
            position = i;
            i=16;
        }
    } while (i<15);
    if (position < 16) {
        for (i=(position+1);i<10;i++) {
            scores[i].score = scores[i-1].score;
            scores[i].name = scores[i-1].score;
        }
        scores[position].score = total;
        cout << "\nPlease enter your name: ";
        cin >> scores[position].name;
    }
    cout << "High Scores" << endl;
    for (i=0;i<10;i++) {
        cout << scores[i].name << " " << scores[i].score << " | ";
        if (i==5) { cout << endl; }
    }
    cout << endl;
}
#endif	/* FUNCTIONS_H */

