/* 
 * File:   cmdtree.h
 * Author: Bradley Evans
 *
 * Created on October 19, 2014, 5:12 PM
 */

#ifndef CMDTREE_H
#define	CMDTREE_H
#include <iostream>
#include "functions.h"
#include "classes.h"

// SYNTAX cmd_[noun]_[verb] ()

void cmd_ask_name() {
    int result;
    result = diceroller(10);
    cout << "\n" << result << " was the diceroll for this action...\n";            
    cout << "\nHe told you his name!" << endl;
            
}



#endif	/* CMDTREE_H */

