/* 
 * File:   Prob1Random.cpp
 * Author: Bradley Evans
 * 
 * Created on December 12, 2014, 2:37 AM
 */

#include "Prob1Random.h"

Prob1Random::Prob1Random(char a,char* b) {   
    nset = a;
    set = b;
    freq = new int[nset];
    for(int i=0;i<nset;i++) {
        freq[i] = 0;
    }
    numRand = 0;
}
Prob1Random::~Prob1Random()
{
    delete[] freq;
    freq = NULL;
}

char Prob1Random::randFromSet(int a) {
    numRand++;
    char chosen;
    for(int i=0;i<nset;i++) {
        if(a == i) {
            chosen = set[a];
            freq[a]++;
            i = nset;
        }
    }
    return chosen;
}
int *Prob1Random::getFreq() { return freq; }
char *Prob1Random::getSet() { return set; }
int Prob1Random::getNumRand() { return numRand; }
