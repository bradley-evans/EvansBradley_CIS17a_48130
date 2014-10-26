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
#include "verbs.h"
#include "cmdtree.h"
using namespace std;


std::map < std::string, Cmd::Noun > knownNouns = 
{
    {   "name",         Noun::name          },
    {   "base",         Noun::base          },
    {   "attack",       Noun::attack        },
    {   "suspect",      Noun::suspect       }
    
};
 
Noun parseNoun(std::string &noun);
void ask (Cmd::Noun noun);
void look (Cmd::Noun noun);

#endif	/* NOUNS_H */

