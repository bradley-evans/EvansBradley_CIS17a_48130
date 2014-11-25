/* 
 * File:   ParseCmd.cpp
 * Author: Bradley Evans
 * 
 * Created on November 23, 2014, 5:54 PM
 */
#include "ParseCmd.h"

ParseCmd::ParseCmd(string command) {
    regex ex("^\\s*(((?<verb>[a-z]*)\\s(?<noun>[a-z]*)|((?<verb>[a-z]*))))\\s*$");
    smatch what;
    if (regex_match(command,what,ex)) {
        noun = what["noun"];
        verb = what["verb"];
        valid = true;
    } else {
        valid = false;
    }
    
}
string ParseCmd::getNoun() {
    return noun;
}
string ParseCmd::getVerb() {
    return verb;
}
bool ParseCmd::isValid() {
    return valid;
}
ParseCmd::~ParseCmd() {
}

