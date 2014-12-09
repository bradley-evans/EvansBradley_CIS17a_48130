/* 
 * File:   Dice.cpp
 * Author: Bradley Evans
 * 
 * Created on November 25, 2014, 1:23 PM
 */

#include "Dice.h"

void Dice<string>::parseDice() {
    regex ex("^\\s*(?<numDice>[\\d{1,}]*)d(?<numSides>[\\d{1,}]*)\\s*$");
    smatch what;
    string num = "";
    string sides = "";
    regex_match(input,what,ex);
    num = what["numDice"];
    sides = what["numSides"];
    numDice = atoi(num.c_str());
    numSides = atoi(sides.c_str());
}
int Dice<string>::roll(string in) {
    input = in;
    parseDice();
    srand(time(NULL));
    result = 0;
    int diceroll = 0;
    for (int i=0;i<numDice;i++) {
        diceroll = ((rand() % numSides) + 1);
        result = result + diceroll;
    }
    return result;
}