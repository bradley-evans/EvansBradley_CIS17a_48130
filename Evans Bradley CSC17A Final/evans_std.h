/* 
 * File:   evans_std.h
 * Author: Bradley Evans
 *
 * Created on November 15, 2014, 3:45 PM
 */

#ifndef EVANS_STD_H
#define	EVANS_STD_H

#include <iostream>
#include <string>
using namespace std;
#include <boost/regex.hpp>
using namespace boost;

    void displayMenu (char& choice);                        //Display menu. Validate input
    bool replayFunc (char& localChoice);                    //See if user wants to run func again
    void localPause ();                                     // local pause function
    bool regexValidate (string expr, string teststring);    // Regex Validator

#endif	/* EVANS_STD_H */

