/* 
 * File:   Prob1Random.h
 * Author: Bradley Evans
 *
 * Created on December 12, 2014, 2:37 AM
 */

#ifndef PROB1RANDOM_H
#define	PROB1RANDOM_H

#include <cstdlib>
#include <iostream>
#include <ctime>

class Prob1Random {
private:
        char*   set;      //The set of numbers to draw random numbers from
        char    nset;     //The number of variables in the sequence
        int*    freq;     //Frequency of all the random numbers returned
        int     numRand;  //The total number of times the random number function is called
public:
        Prob1Random(char,char*);            // Constructor
        ~Prob1Random(void);                 // Destructor
        char    randFromSet(int);           // Returns a random number from the set
        int     *getFreq(void);             // Returns the frequency histogram
        char    *getSet();                  // Returns the set used
        int     getNumRand(void);           // Gets the number of times randFromSet has
                                            // been called
};
/* Changes made to original specification:
 * Primarily, I removed consts because I wasn't sure what they were needed for.
 * Other than that, the specification is largely the same.
 */

#endif	/* PROB1RANDOM_H */

