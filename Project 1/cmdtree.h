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

void printLine(string filename, int line)
{
    char        descrip[11][500] = {0};
    char        *ch_arr = descrip[0];
    char        cbuffer;
    fstream     text;
    bool        isNewline = false;
    int         x = 0;
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
    cout    <<" " ch_arr << endl;
        
}
// SYNTAX cmd_[noun]_[verb] ()

// ask
void cmd_ask_name() {       // ask name
    Dice dice;
    int result = 0;
    result = dice.roll(100);
    cout << "\nHe told you his name!" << endl;          
}

// look
void cmd_look_suspect()     // look suspect
{
    int         i = 0;  // iterator
    int         statePosture;
    string      descfile;
    
    // Pull statePosture line from suspect_posture.txt.
    statePosture    = ((suspect.comply + suspect.silence) / 20);
    descfile        = "suspect_posture.txt";
    
    printLine(descfile,statePosture);
    
}

#endif	/* CMDTREE_H */

