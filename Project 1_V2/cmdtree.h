/* 
 * File:   cmdtree.h
 * Author: Bradley Evans
 *
 * Created on October 19, 2014, 5:12 PM
 */

#ifndef CMDTREE_H
#define	CMDTREE_H

#include "functions.h"
#include <iostream>
#include <fstream>
#include "classes.h"
using namespace std;

void printLine(string filename, int line)       ///< Print a specific line from a given text filename. Allows me to list descriptions in a text file and print line 1 for a value 1 of the suspects attributes, etc.
{
    char        descrip[11][500] = {0};
    char        *ch_arr = descrip[0];
    fstream     text;
    int         y = 0;
    
    cout << "\nfile: " << filename << " line: " << line << endl;
    
    text.open(filename,ios::in);
    if (!text.is_open()) {         
        cout << "\nCould not open " << filename << "." << endl;
    } else {
        while (!text.eof())
        {
            ch_arr = descrip[y];
            text.getline(ch_arr,500);
            y++;
        }                
    }
    text.close();
    ch_arr = descrip[line];
    cout    << " " << ch_arr << endl;
        
}
// SYNTAX cmd_[noun]_[verb] ()

// ask
void cmd_ask_name() {       ///< Command: ask name
    Dice dice;
    int result;
    result = dice.roll(100);
    if ((suspect.silence - suspect.comply - suspect.exhaustion) > result) {
        cout << "\nThe suspect sits there quietly." << endl;
    } else if ((suspect.silence - suspect.comply - suspect.exhaustion) <= result) {
        result = dice.roll(100);
        if (result > (suspect.deception - suspect.exhaustion)) {
            cout << "He gives you his real name!" << endl;
        } else {
            cout << "He lies about his name." << endl;
        }
    }
    suspect.exhaustion++;                
}
        
// look
void cmd_look_suspect()     ///< Command: look suspect
{
    int         statePosture;
    string      descfile;
    
    // Pull statePosture line from suspect_posture.txt.
    statePosture    = ((suspect.comply + suspect.silence) / 20);
    descfile        = "suspect_posture.txt";
    
    printLine(descfile,statePosture);
    
}

#endif	/* CMDTREE_H */

