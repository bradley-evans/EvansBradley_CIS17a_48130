/* 
 * File:   Dice.h
 * Author: Bradley Evans
 *
 * Created on November 25, 2014, 1:23 PM
 */

#ifndef DICE_H
#define	DICE_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include <boost\regex.hpp>
using namespace boost;

enum class DiceTypes {
    d4,
    d6,
    d10,
    d20,
    d100,
    passfail,
    invalid
};

template <class T> 
class Dice {
private:
    T input;
    int numDice;
    int numSides;
    int result;
public:
    Dice(T in) {input = in;}    
    int getnumDice() { return numDice; }
    int getnumSides() { return numSides; }
};
template <>
class Dice <string> {
private:
    string input;
    int numDice;
    int numSides;
    int result;
public:
    Dice() {}
    Dice(string in) {
        input = in;
    }   
    int getnumDice() { return numDice; }
    int getnumSides() { return numSides; }
    void parseDice();
    int roll(string);
};
template <>
class Dice <DiceTypes> {
    private:
    DiceTypes input;
    int numDice;
    int numSides;
    int result;
public:
    Dice(DiceTypes in) { input = in; }   
    int getnumDice() { return numDice; }
    int getnumSides() { return numSides; }
};

#endif