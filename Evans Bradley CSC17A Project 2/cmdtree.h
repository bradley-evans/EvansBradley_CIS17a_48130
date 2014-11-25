/* 
 * File:   cmdtree.h
 * Author: Bradley Evans
 *
 * Created on November 23, 2014, 9:42 PM
 */

#ifndef CMDTREE_H
#define	CMDTREE_H
#include <iostream>
using namespace std;
#include "Noun.h"
#include "Verb.h"

void testNoun(EnumNoun);
void testVerb(EnumVerb);
void verbTree(EnumVerb,EnumNoun);
// NOUNS
void askTree(EnumNoun);
void lookTree(EnumNoun);

#endif	/* CMDTREE_H */

