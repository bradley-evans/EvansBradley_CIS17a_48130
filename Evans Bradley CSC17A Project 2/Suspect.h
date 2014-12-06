/* 
 * File:   Suspect.h
 * Author: Bradley Evans
 *
 * Created on November 25, 2014, 1:48 PM
 */

#ifndef SUSPECT_H
#define	SUSPECT_H

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

/**\brief Class which stores details about the suspect.
 * The virtual function showStats() also makes this an abstracted
 * class, with the child class being Game.
 */
class Suspect {
private:
    // PRIMARY STATS //
    int intelligence;   ///< Suspect's ability to reason.
    int deception;  ///< Suspect's ability to form lies.
    int loyalty;    ///< Suspect's loyalty to his group.
    int honesty;    ///< Suspect's willingness to tell the truth to the investigator.
    int exhaustion;  ///< Reflects the length of the interrogation.
    int trust;      ///< Building trust with the suspect.
public:
    Suspect();
    int getInt() { return intelligence; } ///< Intelligence accessor.
    int getDec() { return deception; } ///< Deception accessor.
    int getLoy() { return loyalty; } ///< Loyalty accessor
    int getHon() { return honesty; } ///< Honesty accessor
    int getExh() { return exhaustion; } ///< Exhaustion accessor.
    int getTru() { return trust; } ///< Trust accessor.
    void setLoy(int mod) { loyalty = mod; } ///< Intelligence mutator
    void setTru(int mod) { trust = mod; } ///< Trust mutator
    void setExh(int mod) { exhaustion = mod; } ///< Exhaustion mutator
    void setHon(int mod) { honesty = mod; } ///< Honesty mutator
    void setInt(int mod) { intelligence = mod; } ///< Intelligence mutator
    void setDec(int mod) { deception = mod; } ///< Deception mutator.
    virtual void showStats() {}; ///< Shows suspects statistics. Debugger.
    virtual ~Suspect();
    friend class Game;
};

#endif	/* SUSPECT_H */

