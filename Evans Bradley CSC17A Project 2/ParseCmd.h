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

