/* 
 * File:   nouns.h
 * Author: Bradley Evans
 *
 * Created on October 18, 2014, 8:33 PM
 */

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

/*
 * The verb.h header has a function which determines what verb is being used.
 * nouns.h will then decide what to do with the verb as it pertains to a particular
 * noun, which is passed from the verb parser.
 */

#ifndef NOUNS_H
#define	NOUNS_H

#include <iostream>
#include <map>
#include <string>

#include "classes.h"
#include "functions.h"
#include "cmdtree.h"

enum class Noun
{
    // Interrogation subjects
    name,                   // ask the subject his name
    base,                   // where is the rebel base?
    attack,                 // when will the attack be?
    suspect,                // The person you're interrogating
    
    invalid
};

std::map < std::string, Noun > knownNouns = 
{
    {   "name",         Noun::name          },
    {   "base",         Noun::base          },
    {   "attack",       Noun::attack        },
    {   "suspect",      Noun::suspect       }
    
};
 
Noun parseNoun(std::string &noun)
{
    auto n = knownNouns.find(noun);
    if ( n == knownNouns.end() ) {
        return Noun::invalid;
    }
    return n->second;
}

void ask (Noun noun);
void look (Noun noun);

#endif	/* NOUNS_H */

