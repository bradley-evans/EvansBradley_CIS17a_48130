/* 
 * File:   cmdtree.h
 * Author: Bradley Evans
 *
 * Created on November 23, 2014, 9:42 PM
 */

#ifndef CMDTREE_H
#define	CMDTREE_H
#include <iostream>
#include <fstream>
using namespace std;
#include "Noun.h"
#include "Verb.h"
#include "Dice.h"
#include "Game.h"

void testNoun(EnumNoun);
void testVerb(EnumVerb);
// VERBS
void verbTree(EnumVerb,EnumNoun,Game&);
// NOUNS
void askTree(EnumNoun,Game&);
void lookTree(EnumNoun,Game&);
// COMMANDS
void cmd_ask_name(Game&);

#endif	/* CMDTREE_H */

