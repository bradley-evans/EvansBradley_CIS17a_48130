/* 
 * File:   Suspect.cpp
 * Author: Bradley Evans
 * 
 * Created on November 25, 2014, 1:48 PM
 */

#include "Suspect.h"

Suspect::Suspect() {
    srand(clock());
    trust = (rand()%5);
    if ((rand()%2)==0) {
        trust = 0 + (rand()%5);
    } else {
        trust = trust - (rand()%5);
    }
    intelligence = rand()%10;
    deception = rand()%10;
    loyalty = rand()%5;
    if ((rand()%2)==0) {
        loyalty = 0 + (rand()%5);
    } else {
        loyalty = loyalty - (rand()%5);
    }
    honesty = rand()%5;
    if ((rand()%2)==0) {
        honesty = 0 + (rand()%5);
    } else {
        honesty = honesty - (rand()%5);
    }
    exhaustion = rand()%5;
}
Suspect::~Suspect() {
}

