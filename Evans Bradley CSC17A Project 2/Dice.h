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

enum class DiceTypes {
    d4,
    d6,
    d10,
    d20,
    d100,
    passfail,
    invalid
};

class Dice {
public:
    ParseDice();
    int getDice();
private:
    string dicestr;
    int numDice;
    DiceType numSides;
    int result;
};

template <class Dice> class DiceRoller {
public:
    Dice();
    virtual ~Dice();
private:
};

#endif	/* DICE_H */
