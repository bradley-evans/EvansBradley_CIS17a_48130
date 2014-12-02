/* 
 * File:   cmdtree.cpp
 * Author: Bradley Evans
 * 
 * Created on November 23, 2014, 9:42 PM
 */

#include "cmdtree.h"
#include "Suspect.h"

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
        case EnumVerb::quit:
            break;
        default:
            cout << "Made it to the switch, but couldn't parse out anything." << endl;
            break;
    }
}

void printLine(string filename, int line)       
{
    char        descrip[11][500] = {0};     ///< 2D array that takes in the line.
    char        *ch_arr = descrip[0];       ///< Pointer.
    fstream     text;                       ///< Text coming in from the file.
    int         y = 0;                      ///< Iterator.
    
    text.open(filename,ios::in);
    if (!text.is_open()) {         
        cout << "\<ERROR: Could not open " << filename << ".\>" << endl;
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

void verbTree (EnumVerb verb, EnumNoun noun, Game& game) {
    switch (verb) {
        case EnumVerb::ask:
            askTree(noun,game);
            break;
        case EnumVerb::quit:
            break;
        case EnumVerb::look:
            lookTree(noun,game);
            break;
        default:
            cout << "You're not really sure how to do that." << endl;
    }
}

void askTree (EnumNoun noun,Game& game) {
    switch (noun) {
        case EnumNoun::name: 
            cout << "[ASK NAME] command detected!" << endl;
            cmd_ask_name(game);
            break;
        default: 
            cout << "You're not really sure how to ask about that." << endl;
    }
}

void lookTree (EnumNoun noun,Game& game) {
    switch (noun) {
        case EnumNoun::suspect:
            cout << "[LOOK SUSPECT] command detected!" << endl;
            break;
        default:
            cout << "Not much to see there." << endl;
    }
}

void cmd_ask_name(Game& game) {     
    Dice<string> dice;
    int result;
    int diff;
    result = dice.roll("1d20");
    diff = (game.getDec()) - (game.getTru() + game.getHon() + game.getExh());
    if (diff > result) {
        cout << "The suspect sits there quietly." << endl;
    } else {
        cout << "\"My name is Hamad Anwar,\" the man says softly. His voice has a faint British -- maybe South African? -- [accent]." << endl;       
    }
    game.setExh( game.getExh()+1 );
}