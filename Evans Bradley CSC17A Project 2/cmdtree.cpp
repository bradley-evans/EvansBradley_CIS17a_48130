/* 
 * File:   cmdtree.cpp
 * Author: Bradley Evans
 * 
 * Created on November 23, 2014, 9:42 PM
 */

#include "cmdtree.h"
using namespace std;

void intro () {
    startClock();
}

/** Initializes the game clock.
 */
void startClock() {
    srand(clock());
    gamestate.clock = 15 + (rand()%15);
}

void debug(Game game) {
    cout << gamestate.clock << " turns remaining!" << endl;
}

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
    line++;
    if (!text.is_open()) {         
        cout << "<ERROR: Could not open " << filename << ".>" << endl;
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

void cmd_save_game (Game game) {
    int *ptr;
    int i = 0;
    ptr = new int[gamestate.NUMOBJECTS];
    // SAVE SUSPECT DATA
    ptr[i] = game.getDec();
    ptr[++i] = game.getExh();
    ptr[++i] = game.getHon();
    ptr[++i] = game.getInt();
    ptr[++i] = game.getLoy();
    ptr[++i] = game.getTru();
    // SAVE GAMESTATE
    ptr[++i] = gamestate.clock;
    ptr[++i] = gamestate.toldAge;
    ptr[++i] = gamestate.toldName;
    
    fstream save;
    string filename = "savegame.bin";
    save.open(filename,ios::out);
    if (save.is_open()) {
        for (i=0;i<gamestate.NUMOBJECTS;i++) {
            
        }
    }
}

void cmd_load_game (Game &game) {
    
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
        case EnumVerb::save:
            cmd_save_game(game);
        case EnumVerb::load:
            cmd_load_game(game);
        default:
            cout << "You're not really sure how to do that." << endl;
    }
}

void askTree (EnumNoun noun,Game& game) {
    switch (noun) {
        case EnumNoun::name: 
            cmd_ask_name(game);
            break;
        default: 
            cout << "You're not really sure how to ask about that." << endl;
    }
}

void lookTree (EnumNoun noun,Game& game) {
    switch (noun) {
        case EnumNoun::suspect:
            cmd_look_suspect(game);
            break;
        default:
            cout << "Not much to see there." << endl;
    }
}

void cmd_ask_name(Game& game) {     
    Dice<string> dice;
    int result;
    int diff;
    cout << "\"Let's try something simple,\" you ask. \"What is your name?\"" << endl;
    result = dice.roll("1d20");
    diff = (game.getDec()) - (game.getTru() + game.getHon() + game.getExh());
    if (diff > result) {
        cout << "The suspect sits there quietly." << endl;
    } else if (gamestate.toldName == true) {
        cout    << "\"I have already told you my name,\" he says, in his out-of-place [accent]. Hamad watches you intently." << endl
                << "\"Why don't you just humor me. Tell me again,\" you insist." << endl
                << "\"Hamad Anwar, as I just said,\" he repeats. \"Aren't you in a [hurry]?\" he says mockingly, \"Maybe you should try asking better [questions].\"" << endl;
    } else {
        cout << "\"My name is Hamad Anwar,\" the man says softly. His voice has a trace British -- maybe South African? -- [accent]." << endl;       
        gamestate.toldName = true;
        game.setExh( game.getExh() + 1 );
    }
}

void cmd_look_suspect(Game& game)     ///< Command: look suspect
{
    int         statePosture;
    string      descfile;
    
    // Pull exhaustion descriptor...
    statePosture    = ( game.getExh()/5 );
    descfile        = "suspect_exh.txt";
    printLine(descfile,statePosture);
    
}