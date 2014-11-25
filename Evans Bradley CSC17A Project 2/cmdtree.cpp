/* 
 * File:   cmdtree.cpp
 * Author: Bradley Evans
 * 
 * Created on November 23, 2014, 9:42 PM
 */

#include "cmdtree.h"

void testNoun(EnumNoun noun) {
    switch (noun) {
        case EnumNoun::name: 
            cout << "Successfully parsed [name]!" << endl;
            break;
        case EnumNoun::invalid:
            cout << "Successfully parsed [invalid]!" << endl;
            break;
        default:
            cout << "Made it to the switch, but couldn't parse out anything." << endl;
            break;
    }
}

void testVerb(EnumVerb verb) {
    switch (verb) {
        case EnumVerb::ask: 
            cout << "Successfully parsed [ask]!" << endl;
            break;
        case EnumVerb::invalid:
            cout << "Successfully parsed [invalid]!" << endl;
            break;
        default:
            cout << "Made it to the switch, but couldn't parse out anything." << endl;
            break;
    }
}

void verbTree (EnumVerb verb, EnumNoun noun) {
    switch (verb) {
        case EnumVerb::ask:
            askTree(noun);
            break;
        case EnumVerb::quit:
            break;
        case EnumVerb::look:
            lookTree(noun);
            break;
        default:
            cout << "You're not really sure how to do that." << endl;
    }
}

void askTree (EnumNoun noun) {
    switch (noun) {
        case EnumNoun::name: 
            cout << "[ASK NAME] command detected!" << endl;
            break;
        default: 
            cout << "You're not really sure how to ask about that." << endl;
    }
}

void lookTree (EnumNoun noun) {
    switch (noun) {
        case EnumNoun::suspect:
            cout << "[LOOK SUSPECT] command detected!" << endl;
            break;
        default:
            cout << "Not much to see there." << endl;
    }
}
