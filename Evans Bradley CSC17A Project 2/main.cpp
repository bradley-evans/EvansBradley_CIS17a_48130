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
#include "gamestate.h"
#include "cmdtree.h"
using namespace std;

void parse(string,EnumNoun&,EnumVerb&); ///< Function which runs different parsing functions in ParseCmd, Noun, and Verb to find enumerated values for the input.
void getinput(string&);                 ///< Takes the user's input and ensures that it is valid.

int main() {
    string cmd;
    EnumNoun noun;
    EnumVerb verb;
    Game game;
    intro(game);
    do {
        getinput(cmd);
        parse(cmd,noun,verb);
        verbTree(verb,noun,game);
        if (gamestate.clock == 0) { timeout(game,verb); }
        if (gamestate.pain > 5) { game.setTru(0); } 
    } while (verb!=EnumVerb::quit);
    cmd_save_game(game);
    return 0;
}
/** \brief Sequence of commands which parses out commands.
 *  */
void parse(string cmd,EnumNoun &noun,EnumVerb &verb) { 
    ParseCmd command(cmd);
    Verb cmdverb(command.getVerb());
    cmdverb.parseVerb();
    Noun cmdnoun(command.getNoun());
    cmdnoun.parseNoun();
    verb = cmdverb.getVerbEnum();
    noun = cmdnoun.getNounEnum();            
    if (!command.isValid()) { cout << "Invalid!" << endl; }
}

/** \brief Take user input and validate it.
 *  */
void getinput(string& cmd) {
    bool isValid;
    do {
        cout << "> ";
        getline(cin,cmd);
        ParseCmd check(cmd);
        isValid = check.isValid();
    } while (!isValid);
}

