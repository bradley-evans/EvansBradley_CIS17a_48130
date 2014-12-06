#include "Noun.h"
using namespace std;

Noun::Noun(string in_noun) {
    nounstr = in_noun;
}
Noun::~Noun() {
}
void Noun::parseNoun() {
    map <string,EnumNoun> knownNouns;
    knownNouns["name"] = EnumNoun::name;
    knownNouns["suspect"] = EnumNoun::suspect;
    knownNouns["debug"] = EnumNoun::debug;
           
    auto n = knownNouns.find(nounstr);        
    if (n == knownNouns.end()) { 
        noun = EnumNoun::invalid; 
    } else {
        noun = n->second;
    }
}
EnumNoun Noun::getNounEnum() {
    return noun;
}

