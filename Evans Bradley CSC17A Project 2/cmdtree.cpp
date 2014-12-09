/* 
 * File:   cmdtree.cpp
 * Author: Bradley Evans
 * 
 * Created on November 23, 2014, 9:42 PM
 */

#include "cmdtree.h"

/** \brief Initialize certain variables and play intro
 * Initializes certain game variables, such as the clock, and begins the game. */
void intro(Game game) {
    startClock();
    cout    << "==================================================" << endl
            << " CAMP XRAY: A Game about Interrogation " << endl
            << "==================================================" << endl
            << endl
            << "You observe your [suspect] through a grainy webcam image in a small window on your laptop screen. The laptop has a short debriefing report open detailing the operation that resulted in your suspect's [capture]. Apparently, he was found in a building that contained a [cache] of obviously stolen weapons and equipment, including valuable [radio] gear. He claimed his [name] was Hamad." << endl
            << endl
            << "You have been assigned as this subject's interrogator. He's being processed for transfer, at which time your unit will lose access to him and he'll disappear into the hands of the CIA. You have been told that you have just under a half hour before this happens." << endl
            << endl
            << "You enter the room and seat yourself across from the suspect, opening up a dossier and glancing over some of your notes. More of a show than anything. The notes don't say anything substantial. You prepare to start your interrogation..." << endl
            << endl;
    cmd_look_suspect(game);
    cout    << endl;
    cout    << "Enter commands in the form of a noun followed by a verb, such as 'ask name.'" << endl;
}

/** \brief Functions for a debugging mode.
 * Contains debugging code.
 */
void debug(Game game) {
    game.showStats();
    cout << "Time Remaining: " << gamestate.clock << endl;
}
/** \brief Prints a specific line from a text file, used for dynamic descriptions of the suspect.
 * Writes a specific line of a text file in to create descriptions that are based on a certain
 * statistic of the suspect. In other words, dynamically generated descriptions based
 * on changing conditions in the game. 
 */
string printLine(string filename, int line)       
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
    string str(ch_arr);
    return str;
        
}

/** \brief Saves the game
 * Writes the current state of the game and the suspects statistics to a character
 * array, which is in turned saved to a binary file.
 * Demonstrates binary input/output.
 */
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
    ptr[i] = static_cast<char>(gamestate.pain); i++;
    ptr[i] = gamestate.toldAge; i++;
    ptr[i] = gamestate.toldName; i++;
    ptr[i] = gamestate.gaveExtension; i++;
    ptr[i] = gamestate.truthCapture; i++;
    ptr[i] = gamestate.liedCapture; i++;
    ptr[i] = gamestate.truthAccent; i++;
    ptr[i] = gamestate.liedAccent; i++;
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
/** \brief Loads a saved game.
 * Searches for a saved game in savegame.bin and loads a previously-saved
 * game state into memory.
 *  */
void cmd_load_game (Game& game) {
    char *ptr;
    int i = 0;
    ptr = new char[gamestate.NUMOBJECTS];
    
    string filename = "savegame.bin";
    ifstream load;
    load.open(filename,ios::in|ios::binary);
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
    gamestate.pain = ptr[++i];
    gamestate.toldAge = ptr[++i];
    gamestate.toldName = ptr[++i];
    gamestate.gaveExtension = ptr[++i];
    gamestate.truthCapture = ptr[++i];
    gamestate.liedCapture = ptr[++i];
    gamestate.truthAccent = ptr[++i];
    gamestate.liedAccent = ptr[++i];
    
    load.close();
    delete[] ptr;

}
/** \brief A tree which contains verbs used by the program.
 * Called first, then passes an EnumNoun to the corresponding noun tree for the
 * verb detected.
 *  */
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
        case EnumVerb::hit:
            cmd_hit(noun,game);
            break;
        default:
            cout << "You're not really sure how to do that." << endl;
    }
}

void askTree (EnumNoun noun,Game& game) {
    switch (noun) {
        case EnumNoun::name: 
            cmd_ask_name(game);
            gamestate.clock--;
            break;
        case EnumNoun::suspect:
            cout << "What did you want to ask him?" << endl;
            break;
        case EnumNoun::capture:
            cmd_ask_capture(game);
            break;
        case EnumNoun::accent:
            cmd_ask_accent(game);
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

void cmd_hit (EnumNoun noun, Game& game) {
    Dice<string> dice;
    int result;
    if (noun == EnumNoun::suspect) {
        if (gamestate.pain == 0) {
            cout << "You decide that a little 'enhanced interrogation' is in order and move to hit the suspect in the chest. ";
        } else if (gamestate.pain > 0) {
            cout << "You strike at the suspect again. ";
        }
        result = dice.roll("1d5");
        char char_result = '0' + result;
        switch (char_result) {
            case '1' :
                cout << "The suspect doubles over in pain, groaning. He chuckles a little, and says something in Arabic you recognize as something unflattering about the size of your penis." << endl;
                gamestate.pain++;
                game.setTru(game.getTru()-1);
                break;
            case '2' :
                cout << "You knock the suspect out of his chair and he falls backward, yelping with surprise and striking his head against the back wall. He starts bleeding from a small head wound, cursing in Arabic as you roughly drag him and his seat upright." << endl;
                gamestate.pain = gamestate.pain+3;
                break;
            case '3' :
                cout << "At the last moment you stop short, pulling back your blow. The suspect watches you intently. \"Lost your nerve?\" he asks." << endl;
                game.setTru(game.getTru()+1);
                break;
            case '4' :
                cout << "Your blow connects and he gasps in pain." << endl;
                gamestate.pain++;
                break;
            case '5' :
                cout << "Your blow connects somewhere non vital. He seems surprised, but it doesn't leave any lasting damage." << endl;
                break;
        }
    } else {
        cout << "You're not sure that hitting that would be terribly productive." << endl;
    }
    gamestate.clock++;
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

void cmd_ask_capture(Game& game) {
    int result;
    int diff;
    Dice<string> dice;
    cout << "\"Why don't you tell me what you were doing out by that weapons cache?\" you ask." << endl;
    if (gamestate.truthCapture) {
        cout << "\"I already told you what I know about that.\" he replies." << endl;
    } else if (gamestate.liedCapture) {
        result = dice.roll("1d20");
        diff = game.getDec() - game.getTru() + 3;
        if (result > diff) {
            gamestate.truthCapture = true;
            gamestate.liedCapture = false;
            cout << "He scoffs. \"Fine. I was there to [fix] a few things.\"" << endl;
            cout << "You perk up. \"I thought you were just a messenger boy?\"" << endl;
            cout << "He laughs bitterly. \"Yes, a [messenger] boy.\"" << endl;
        } else {
            cout << "He sits quietly, staring ahead stoically.";
        }
    } else {
        diff = game.getDec() - game.getHon() - game.getTru() + game.getLoy();
        result = dice.roll("1d20");
        if (result > diff) {
            cout << "\"I was there to [fix] a few things,\" he says. \"The mujadeen, they are great killers of Americans but not so handy with tools,\" he says bitterly." << endl;
            gamestate.truthCapture = true;
            if (game.getTru() > 5) { cout << "\"They have my [family],\" he whispers." << endl; }
        } else if (result == diff) {
            cout << "He chuckles bitterly. \"I am just the messenger boy, infidel.\" His left eye twitches nervously." << endl;
            gamestate.liedCapture = true;
        } else {
            cout << "He chuckles bitterly. \"I am just the messenger boy, infidel.\"" << endl;
            gamestate.liedCapture = true;
        }
    }
    gamestate.clock++;
}

void cmd_ask_accent(Game& game) {
    int result;
    int diff = game.getDec() - game.getHon() - game.getTru();
    Dice<string> dice;
    result = dice.roll("1d20");
    cout << "\"Nice accent, asshole.\" you say mockingly. \"Watching a lot of BBC? Hate America, love our TV shows, huh?\"" << endl;
    if (gamestate.truthAccent) {
        cout << "\"I've already told you that sad story.\" he says, folding his arms." << endl;
    } else if (gamestate.liedAccent) {
        if (result > diff+3) { 
            gamestate.truthAccent = true;
            gamestate.liedAccent = false;
            cout << "He watches you quietly." << endl;
            cout << "\"I suppose you do look like the sort of ignorant idiot who'd burn American flags just before you settled in to watch Miami Vice.\" you say, mockingly." << endl;
            cout << "He continues staring at you. \"I studied at Oxford.\" he says. \"Where did you study, University of Pheonix?\"" << endl;
        } else {
            cout << "He sits there silently." << endl;
        }
    } else if (result > diff) {
        gamestate.truthAccent = true;
        cout <<  "\"I studied at Oxford.\" he says. \"Where did you study, University of Pheonix?\"" << endl;
    } else if (result == diff || result < diff) {
        cout << "\"Yes, exactly,\" he says, rolling his eyes. \"I just love some Miami Vice. Miami Vice number 1.\"" << endl;
    }
}

void cmd_look_suspect(Game& game)     ///< Command: look suspect
{
    string filename;
    int state;
    cout    << "The suspect seated across from you is dressed in a dirty, white robe. He's a little scuffed up from his capture, and is restrained to the chair by zip-ties, although he hasn't posed a struggle since he was plucked from the desert three hours ago." << endl;
    filename = "suspect_exh.txt";
    state = (game.getExh()/5);
    cout    << printLine(filename,state) << endl;
    filename = "suspect_int.txt";
    state = (game.getInt()/5);
    cout    << printLine(filename,state) << endl;
    if (gamestate.pain > 5) {
        state = (gamestate.pain - 4) / 3;
        filename = "suspect_pain.txt";
        cout << printLine(filename,state) << endl;
    }
    cout << endl;
}

/** \brief Defines what happens when the clock runs out.
 *  */
void timeout(Game& game, EnumVerb& verb) {
    game.setDec(game.getDec()+10);
    int result;
    Dice<string> dice;
    if (gamestate.gaveExtension) {
        cout    << "The civilian reenters the room, glancing around with a look of contempt. \"You're done. He's our prisoner, we'll be conducting the debrief from here,\" he says condescendingly. \"Thanks for your assistance. We'll require a report on your debriefing by the end of the day.\"" << endl
                << "Two other men enter, cutting the man's restraints and bringing him to his feet roughly. \"It's been fun,\" the suspect says, smiling fatally." << endl
                << "\"Fun. Send me a postcard from Guantanamo,\" you call out after him. The suspect isn't smiling anymore when he's lead out the door of the interrogation." << endl;
        verb = EnumVerb::quit;        
    } else if (!gamestate.gaveExtension) {
        gamestate.gaveExtension = true;
        result = dice.roll("1d2");
        cout    << "A heavy knock at your door interrupts your interrogation. You look up, your concentration broken, and the suspect smiles knowingly. \"What the hell--\" you start to say, before a man wearing civilian clothing enters wearing an all too familiar lanyard. \"Prisoner transfer,\" the man announces nonchalantly." << endl;
        cout    << "\"I just need five more minutes,\" you say, annoyed." << endl;
        if (result == 1) {
            result = dice.roll("1d4") + 1;
            cout << "The man grunts. \"You have " << result << " minutes.\" The door slams shut behind you, and you look back at the suspect, who is smiling smugly. \"Looks like time's up.\"" << endl;
        } else {
            cout    << "The man grunts. \"No. He's our prisoner, we'll be conducting the debrief from here,\" he says condescendingly. \"Thanks for your assistance. We'll require a report on your debriefing by the end of the day.\"" << endl
                    << "Two other men enter, cutting the man's restraints and bringing him to his feet roughly. \"It's been fun,\" the suspect says, smiling fatally." << endl
                    << "\"Fun. Send me a postcard from Guantanamo,\" you reply. The suspect isn't smiling anymore when he's lead out the door of the interrogation." << endl;
            verb = EnumVerb::quit;
        }
    }

}