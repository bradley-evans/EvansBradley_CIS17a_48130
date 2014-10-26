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

std::map < std::string, Cmd::Verb > knownVerbs =
{                                       // synonyms for:
    {   "ask",      Cmd::Verb::ask       },  // ask
    {   "quit",     Cmd::Verb::quit      },  // quit
    {   "exit",     Cmd::Verb::quit      },
    {   "look",     Cmd::Verb::look      },  // look
    {   "examine",  Cmd::Verb::look      }
};

Verb parseVerb(const std::string &verb);
int verbProc (Cmd::Noun noun, Cmd::Verb verb);

#endif	/* VERBS_H */

