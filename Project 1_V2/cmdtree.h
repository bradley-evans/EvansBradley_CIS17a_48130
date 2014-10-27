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

/**
 * Print a specific line from a given text filename. Allows me to list 
 * descriptions in a text file and print line 1 for a value 1 of the suspects
 * attributes, etc. If, for example, an attribute fear is defined from 1-100, I can
 * print line 5 for a value from 50-59 to describe the suspect as he might look
 * at a fear level from 50-59.
 * A 2D array is also described here.
 * @param filename Filename passed to the function which defines where the description is coming from.
 * @param line Line number from the file to print.
 */
void printLine(string filename, int line)       
{
    char        descrip[11][500] = {0};     ///< 2D array that takes in the line.
    char        *ch_arr = descrip[0];       ///< Pointer.
    fstream     text;                       ///< Text coming in from the file.
    int         y = 0;                      ///< Iterator.
    
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
//////////////////////////////
// SYNTAX cmd_[noun]_[verb] ()
//////////////////////////////

/**
 * Command: ask name
 */
void cmd_ask_name() {     
    Dice dice;
    int result;
    result = dice.roll(100);
    if ((suspect.silence - suspect.comply - suspect.exhaustion) > result) {
        cout << "\nThe suspect sits there quietly." << endl;
    } else if ((suspect.silence - suspect.comply - suspect.exhaustion) <= result) {
        result = dice.roll(100);
        if (result > (suspect.deception - suspect.exhaustion)) {
            cout << "He gives you his real name!" << endl;
            suspect.truthtold[0]++;                    
        } else {
            cout << "He lies about his name." << endl;
            suspect.liestold[0]++;
        }
    }
    suspect.exhaustion++;                
}
        
/**
 * Command: look suspect
 */
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

