/* 
 * File:   functions.h
 * Author: Bradley Evans
 *
 * Created on October 10, 2014, 3:32 PM
 */

#ifndef FUNCTIONS_H     // if not defined
#define	FUNCTIONS_H     // then define

#include <iostream>
#include <string>
#include <cstring>

#include "classes.h"
#include "verbs.h"
#include "nouns.h"
#include "classes.h"
#include "cmdtree.h"

void localPause ();
void readInput (char* &command, const int MAXL, std::string &noun, std::string &verb);
char verifyExit(char exitChoice);
char validateInput (Verb verb, Noun noun);
void initializeSuspect();
void introduction();

#endif	/* FUNCTIONS_H */

