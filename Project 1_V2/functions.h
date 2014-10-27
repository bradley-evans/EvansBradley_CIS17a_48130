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

/**
 * A local pause function to replace cstdlib's system(pause), which doesn't work
 * for me for whatever reason.
 */
void localPause ()      
{
        cout << endl;
        cin.ignore();
        cout << "Press [ENTER] to continue...";
        cin.get();
        cout << endl;
}

/**
 * Accepts the user's input as a cstring and turns it into two std::strings, 
 * named noun and verb. Assumes the first word up until the first space is a
 * verb, and the second word is a noun. All subsequent words are ignored.
 * @param command The command input by the user.
 * @param MAXL Global constant, max command length
 * @param noun String output of the noun found in the command.
 * @param verb String output of the verb found in the command.
 */
void readInput (char* &command, const int MAXL, string &noun, string &verb) 
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

/**
 * Verifies that the user actually wants to exit.
 * @param exitChoice
 * @return A command character that tells the main function that it's OK to exit.
 */
char verifyExit() ///< Verifies you Really Really want to exit.
{
    char exitChoice;
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

/**
 * After parsing, if the verb or noun was not found, then an enumerated value
 * of 'invalid' is given. This function detects an invalid value and tells the
 * user if one is encountered.
 * @param verb Enumerated verb.
 * @param noun Enumerated noun.
 * @return Control character to tell the main function that it is okay to proceed
 */
char validateInput (Verb verb, Noun noun) 
{
    char exitChoice = 'n';
    if (verb == Verb::invalid) {
        return('X');
    } else if (verb == Verb::quit) {
        return(verifyExit());
    }
    if (noun == Noun::invalid) {
        return('X');
    }
    return('0');
}

/**
 * Initializes the suspect with randomly generated attributes.
 */
void initializeSuspect() 
{
    Dice dice;
    
    suspect.minimize    = 50 + dice.roll(50);
    suspect.silence     = 50 + dice.roll(50);
    suspect.distort     = 50 + dice.roll(50);
    suspect.distract    = 50 + dice.roll(50);
    suspect.comply      = dice.roll(10);
    suspect.honest      = dice.roll(10);
    suspect.deception   = dice.roll(10);
}

/**
 * Plays an introduction.
 */
void introduction()
{
    cmd_look_suspect();
}

/**
 * Initializes a truth table held in the suspect_s structure to zero. This table
 * will hold the user's "score," tracking how many truths or lies have been told.
 */
void zeroScores() {     ///< Zeroes out the truth tables, initializing them for a new game.
    int i = 0;
    for (i=0;i<15;i++) {
        suspect.truthtold[i]=0;
        suspect.liestold[i]=0;
    }
}

/**
 * Show and record the high scores. Demonstrates array of structures funcitonality.
 */
void totalScores() {   
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

