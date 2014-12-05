/* 
 * File:   main.cpp
 * Author: Bradley Evans
 *
 * Created on November 23, 2014, 5:49 PM
 */

#include <iostream>
#include <string>
#include <boost\regex.hpp>
#include "ParseCmd.h"
#include "Noun.h"
#include "Verb.h"
#include "Game.h"
#include "cmdtree.h"
using namespace std;

void parse(string,EnumNoun&,EnumVerb&); ///< Function which runs different parsing functions in ParseCmd, Noun, and Verb to find enumerated values for the input.
void getinput(string&);                 ///< Takes the user's input and ensures that it is valid.

int main() {

    string cmd = "ask name";
    EnumNoun noun;
    EnumVerb verb;
    Game game;
    intro();
    do {
        getinput(cmd);
        parse(cmd,noun,verb);
        debug(game);
        verbTree(verb,noun,game);
    } while (verb!=EnumVerb::quit);
    return 0;
}

void parse(string cmd,EnumNoun &noun,EnumVerb &verb) {
    
    ParseCmd command(cmd);
    Verb cmdverb(command.getVerb());
    cmdverb.parseVerb();
    Noun cmdnoun(command.getNoun());
    cmdnoun.parseNoun();
    verb = cmdverb.getVerbEnum();
    noun = cmdnoun.getNounEnum();            
    
    //if (command.isValid()) { 
    //    cout << "Valid!" << endl; 
    //    cout << "Verb:" << command.getVerb() << endl;
    //    cout << "Noun:" << command.getNoun() << endl;
    //}
    if (!command.isValid()) { cout << "Invalid!" << endl; }
}

void getinput(string& cmd) {
    bool isValid;
    do {
        cout << "> ";
        getline(cin,cmd);
        ParseCmd check(cmd);
        isValid = check.isValid();
    } while (!isValid);
}

