/* 
 * File:   nouns.h
 * Author: Bradley Evans
 *
 * Created on October 18, 2014, 8:33 PM
 */

#ifndef NOUNS_H
#define	NOUNS_H
#include <iostream>
#include <map>
#include <string>
#include "classes.h"
#include "functions.h"
#include "verbs.h"
#include "cmdtree.h"
using namespace std;

/*
 * This header file's principle purpose is to map the noun input by the user
 * to an integer for ease of handling.
 */

enum class Noun
{
    // Interrogation subjects
    name,                   // ask the subject his name
    base,                   // where is the rebel base?
    attack,                 // when will the attack be?
    suspect,                // The person you're interrogating
    
    invalid
};

/*
 * Using a map to list out possible permutations of commands, and associate
 * each command to a member of the enum class Noun, which I will then associate
 * to various actions in my final implementation of a parser.
 * 
 * A lot of help on building this text parsing function came from:
 * http://www.cplusplus.com/forum/general//119658
 * 
 * and users at StackExchange in the following thread:
 * http://stackoverflow.com/questions/26455952/error-c-map-does-not-name-a-type/26455995#26455995
 * 
 * My use of the "auto" variable in parseNoun() is documented in the below:
 * http://www.cprogramming.com/c++11/c++11-auto-decltype-return-value-after-function.html
 *
 */

map < string, Noun > knownNouns = 
{
    {   "name",         Noun::name          },
    {   "base",         Noun::base          },
    {   "attack",       Noun::attack        },
    {   "suspect",      Noun::suspect       }
    
};
 
Noun parseNoun(string &noun)
{
    auto n = knownNouns.find(noun);
    if ( n == knownNouns.end() ) {
        return Noun::invalid;
    }
    return n->second;
}

/*
 * The verb.h header has a function which determines what verb is being used.
 * nouns.h will then decide what to do with the verb as it pertains to a particular
 * noun, which is passed from the verb parser.
 */

void ask (Noun noun) 
{
    switch (noun) {
        case Noun::name:    cmd_ask_name();    // "ask name"
        case Noun::base:    break;
        case Noun::attack:  break;
        default:            cout << "\nYou should think of a better question." << endl;
        
    }
}

void look (Noun noun)
{
    switch (noun) {
        case Noun::invalid: cout << "\nI don't see anything like that here." << endl;
                            break;
        case Noun::suspect: cmd_look_suspect();     // look suspect
    }
}
#endif	/* NOUNS_H */

