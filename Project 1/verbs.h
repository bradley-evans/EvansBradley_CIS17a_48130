/* 
 * File:   verbs.h
 * Author: Bradley Evans
 *
 * Created on October 18, 2014, 8:39 PM
 */

#ifndef VERBS_H
#define	VERBS_H
#include <iostream>
#include <map>
#include <string>
#include "classes.h"
#include "functions.h"
#include "nouns.h"
using namespace std;

/*
 * See the nouns.h header for better documentation on what exactly this
 * is doing.
 */

enum class Verb
{
    ask,        // ask a question
    quit,       // quit the game
    
    
    invalid     // verb was invalid
            
};

map < string, Verb > knownVerbs;
knownVerbs["ask"]   = Verb::ask;
knownVerbs["quit"]  = Verb::quit;
knownVerbs["exit"]  = Verb::quit;

Verb parseVerb(string &verb)
{
    auto n = knownVerbs.find(verb);
    if ( n == knownVerbs.end() ) {
        return Verb::invalid;
    }
    return n->second;
}

#endif	/* VERBS_H */

