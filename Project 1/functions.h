/* 
 * File:   functions.h
 * Author: Bradley Evans
 *
 * Created on October 10, 2014, 3:32 PM
 */

#ifndef FUNCTIONS_H     // if not defined
#define	FUNCTIONS_H     // then define

// Function dependencies --
#include <iostream>
#include <string>
#include <cstring>
#include "classes.h"
#include "verbs.h"
#include "classes.h"
#include "cmdtree.h"
using namespace std;

void localPause ();
void readInput (char* &command, const int MAXL, std::string &noun, std::string &verb);
char verifyExit(char exitChoice);
char validateInput (Cmd::Verb verb, Cmd::Noun noun);
void initializeSuspect();
void introduction();

#endif	/* FUNCTIONS_H */

