/* 
 * File:   cmdtree.h
 * Author: Bradley Evans
 *
 * Created on October 19, 2014, 5:12 PM
 */

#ifndef CMDTREE_H
#define	CMDTREE_H

#include <cstdlib>      // for rand()
#include <time.h>       // to seed random function
#include <ctime>
#include "functions.h"
using namespace std;

void printLine(std::string filename, int line);
void cmd_ask_name();
void cmd_look_suspect();

#endif	/* CMDTREE_H */

