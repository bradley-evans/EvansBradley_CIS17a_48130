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

#include "nouns.h"
#include "classes.h"
#include "functions.h"
/*
 * See the nouns.h header for better documentation on what exactly this
 * is doing.
 */

enum class Verb
{
    ask,        // ask a question
    quit,       // quit the game
    look,       // look at a thing
    
    invalid     // verb was invalid
            
};

std::map < std::string, Verb > knownVerbs =
{                                       // synonyms for:
    {   "ask",      Verb::ask       },  // ask
    {   "quit",     Verb::quit      },  // quit
    {   "exit",     Verb::quit      },
    {   "look",     Verb::look      },  // look
    {   "examine",  Verb::look      }
};

Verb parseVerb(const std::string &verb);

int verbProc (Noun noun, Verb verb);

#endif	/* VERBS_H */

