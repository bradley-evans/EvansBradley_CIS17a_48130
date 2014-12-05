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
#include "gamestate.h"
#include "Game.h"

void intro();
void debug(Game);
void testNoun(EnumNoun);
void testVerb(EnumVerb);
// VERBS
void verbTree(EnumVerb,EnumNoun,Game&);
// NOUNS
void askTree(EnumNoun,Game&);
void lookTree(EnumNoun,Game&);
// COMMANDS
void cmd_ask_name(Game&);
void cmd_look_suspect(Game&);
void cmd_save_game(Game);
void cmd_load_game(Game&);

#endif	/* CMDTREE_H */

