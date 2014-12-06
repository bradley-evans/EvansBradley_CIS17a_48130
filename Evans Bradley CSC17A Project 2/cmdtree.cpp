/* 
 * File:   cmdtree.cpp
 * Author: Bradley Evans
 * 
 * Created on November 23, 2014, 9:42 PM
 */

#include "cmdtree.h"
using namespace std;

void debug(Game game) {
    game.showStats();
}

/** \brief Prints a specific line from a text file, used for dynamic descriptions of the suspect.
 * Writes a specific line of a text file in to create descriptions that are based on a certain
 * statistic of the suspect. In other words, dynamically generated descriptions based
 * on changing conditions in the game. */
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
    char *ptr;
    int i = 0;
    ptr = new char[gamestate.NUMOBJECTS];
    // SAVE SUSPECT DATA
    ptr[i] = static_cast<char>(game.getDec()); i++;
    ptr[i] = static_cast<char>(game.getExh()); i++;
    ptr[i] = static_cast<char>(game.getHon()); i++;
    ptr[i] = static_cast<char>(game.getInt()); i++;
    ptr[i] = static_cast<char>(game.getLoy()); i++;
    ptr[i] = static_cast<char>(game.getTru()); i++;
    // SAVE GAMESTATE
    ptr[i] = static_cast<char>(gamestate.clock); i++;
    ptr[i] = gamestate.toldAge; i++;
    ptr[i] = gamestate.toldName;
    cout << ptr;
    
    ofstream save;
    string filename = "savegame.bin";
    save.open(filename,ios::out | ios::binary);
    if (save.is_open()) {
        save.seekp(ios::beg);
        save.write(ptr, gamestate.NUMOBJECTS);
        if (save) { cout << "Save successful." << endl; } else { cout << "Save error..." << endl; }
    } else if (!save.is_open()) {
        cout << "Failed to save to file savegame.bin" << endl;
    }
    save.close();
    delete[] ptr;
}

void cmd_load_game (Game& game) {
    char *ptr;
    int i = 0;
    ptr = new char[gamestate.NUMOBJECTS];
    
    string filename = "savegame.bin";
    ifstream load(filename,ifstream::binary);
    load.open(filename,ios::in);
    if (load.is_open()) {
        load.seekg(ios::beg);
        load.read(ptr, gamestate.NUMOBJECTS);
        if (load) { cout << "Load successful." << endl; } else { cout << "Load error..." << "[" << load.gcount() << "]" << endl; }
    } else if (!load.is_open()) {
        cout << "Failed to load from file savegame.bin" << endl;
    }
    
    // LOAD SUSPECT DATA
    game.setDec(ptr[i]);
    game.setExh(ptr[++i]);
    game.setHon(ptr[++i]);
    game.setInt(ptr[++i]);
    game.setLoy(ptr[++i]);
    game.setTru(ptr[++i]);

    // SAVE GAMESTATE
    gamestate.clock = ptr[++i];
    gamestate.toldAge = ptr[++i];
    gamestate.toldName = ptr[++i];
    
    
    load.close();
    delete[] ptr;

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
            break;
        case EnumVerb::load:
            cmd_load_game(game);
            break;
        case EnumVerb::show:
            if (noun == EnumNoun::debug) { debug(game); }
            break;
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