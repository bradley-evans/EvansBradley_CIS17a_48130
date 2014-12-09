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
#include "gamestate.h"

void debug(Game);
void cmd_save_game(Game);
void cmd_load_game(Game&);
void intro(Game);   
string printLine(string,int);
// VERBS
void verbTree(EnumVerb,EnumNoun,Game&);
// NOUNS
void askTree(EnumNoun,Game&);   ///< Associated with verb ask
void lookTree(EnumNoun,Game&);  ///< Associated with verb look
// COMMANDS
void cmd_ask_name(Game&);       ///<  ask name
void cmd_ask_capture(Game&);    ///<  ask capture
void cmd_ask_accent(Game&);     ///<  ask accent
void cmd_look_suspect(Game&);   ///<  look suspect, also called in introduction
void cmd_hit(EnumNoun,Game&);   ///<  hit the suspect -- triggers torture flags

void timeout(Game&, EnumVerb&);
#endif	/* CMDTREE_H */

