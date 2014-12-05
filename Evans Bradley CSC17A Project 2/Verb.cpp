/* 
 * File:   Verb.cpp
 * Author: Bradley Evans
 * 
 * Created on November 23, 2014, 5:53 PM
 */

#include "Verb.h"

Verb::Verb(string in_verb) {
    verbstr = in_verb;
}
Verb::~Verb() {
}
void Verb::parseVerb() {
    map <string,EnumVerb> knownVerbs;
    knownVerbs["ask"] = EnumVerb::ask;
    knownVerbs["quit"] = EnumVerb::quit;
    knownVerbs["exit"] = EnumVerb::quit;
    knownVerbs["look"] = EnumVerb::look;
    knownVerbs["save"] = EnumVerb::save;
    knownVerbs["load"] = EnumVerb::load;
           
    auto n = knownVerbs.find(verbstr);        
    if (n == knownVerbs.end()) {
        verb = EnumVerb::invalid; 
    } else { 
        verb = n->second;
    }
}
EnumVerb Verb::getVerbEnum() {
    return verb;
}

