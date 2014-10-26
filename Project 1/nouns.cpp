#include "nouns.h"

using namespace std;

Cmd::Noun parseNoun(std::string &noun)
{
    auto n = knownNouns.find(noun);
    if ( n == knownNouns.end() ) {
        return cmd::Noun::invalid;
    }
    return n->second;
}

void ask (Noun noun) 
{
    switch (noun) {
        case Noun::name:    cmd_ask_name();    // "ask name"
        case Noun::base:    break;
        case Noun::attack:  break;
        case Noun::suspect: break;
        default:            cout << "\nYou should think of a better question." << endl;
        
    }
}

void look (Noun noun)
{
    switch (noun) {
        case Noun::invalid: cout << "\nI don't see anything like that here." << endl;
                            break;
        case Noun::suspect: cmd_look_suspect();     // look suspect
        case Noun::attack: break; //invalid
        case Noun::base: break; //invalid
        case Noun::name: break; //invalid
    }
}

