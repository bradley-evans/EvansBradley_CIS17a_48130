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
    
    invalid
};

/*
 * Using a map to list out possible permutations of commands, and associate
 * each command to a member of the enum class Noun, which I will then associate
 * to various actions in my final implementation of a parser.
 * 
 * A lot of help on building this text parsing function came from:
 * http://www.cplusplus.com/forum/general//119658
 * and users at StackExchange in the following thread:
 * http://stackoverflow.com/questions/26455952/error-c-map-does-not-name-a-type/26455995#26455995
 * 
 * My use of the "auto" variable is documented below:
 * http://www.cprogramming.com/c++11/c++11-auto-decltype-return-value-after-function.html
 *
 */
map < string, Noun > knownNouns;
knownNouns["name"]      = Noun::name;
knownNouns["base"]      = Noun::base;
knownNouns["attack"]    = Noun::attack;

Noun parseNoun(string &noun)
{
    auto n = knownNouns.find(noun);
    if ( n == knownNouns.end() ) {
        return Noun::invalid;
    }
    return n->second;
}


#endif	/* NOUNS_H */

