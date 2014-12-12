/* 
 * File:   ParseCmd.h
 * Author: Bradley Evans
 *
 * Created on November 23, 2014, 5:54 PM
 */

#ifndef PARSECMD_H
#define	PARSECMD_H

#include <iostream>
#include <string>
using namespace std;
#include <boost/regex.hpp>
using namespace boost;
#include "Noun.h"

/** \brief Accepts a string as input for its constructor, parses the string into two seperate strings for a noun and verb, and sends these outputs to classes Noun and Verb.
 *  */
class ParseCmd {
public:
    ParseCmd(string);
    string getNoun();
    string getVerb();
    bool isValid();
    virtual ~ParseCmd();
private:
    string noun;
    string verb;
    bool valid;  
};

#endif	/* PARSECMD_H */

