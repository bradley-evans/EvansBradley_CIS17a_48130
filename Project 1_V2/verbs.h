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

enum class Verb     ///< Enumerated class defines valid verbs.
{
    ask,        // ask a question
    quit,       // quit the game
    look,       // look at a thing
    
    invalid     // verb was invalid
            
};

map < string, Verb > knownVerbs =       ///< Map defines valid verb inputs
{                                       // synonyms for:
    {   "ask",      Verb::ask       },  // ask
    {   "quit",     Verb::quit      },  // quit
    {   "exit",     Verb::quit      },
    {   "look",     Verb::look      },  // look
    {   "examine",  Verb::look      }
};

Verb parseVerb(const string &verb)      ///< Parse verb by comparing it to a map, and returning 
{
    auto n = knownVerbs.find(verb);
    if ( n == knownVerbs.end() ) {
        return Verb::invalid;
    }
    return n->second;
}

/*
 * Send the verb off to be paired with nouns.
 */

void verbProc (Noun noun, Verb verb) {          ///< Switch cases which determine how the verb will be paired with nouns.
    switch (verb) {
        case Verb::ask:     ask(noun);
        case Verb::look:    look(noun);
    }
}
#endif	/* VERBS_H */

