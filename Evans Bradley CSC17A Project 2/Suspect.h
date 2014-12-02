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

class Suspect {
private:
    // PRIMARY STATS //
    int intelligence;
    int deception;
    int loyalty;
    int honesty;
    int exhaustion; 
    int trust;
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
    void showStats();
    virtual ~Suspect();
};

#endif	/* SUSPECT_H */

