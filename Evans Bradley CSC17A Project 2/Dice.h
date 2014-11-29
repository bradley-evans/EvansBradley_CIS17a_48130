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

template <class T1, class T2> 
class Dice {
private:
    T1 numDice;
    T2 numSides;
public:
    Dice(T1,T2);
};
template <>
class Dice <int,int> {
private:
    int numDice;
    int numSides;
};

#endif	/* DICE_H */

