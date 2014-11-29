/* 
 * File:   Suspect.h
 * Author: Bradley Evans
 *
 * Created on November 25, 2014, 1:48 PM
 */

#ifndef SUSPECT_H
#define	SUSPECT_H

#include <cstdlib>
#include <time>

class Suspect {
public:
    Suspect();
    
    virtual ~Suspect();
private:
    // PRIMARY STATS //
    int intelligence;
    int deception;
    int honesty;
    int exhaustion; 
    int trust;

};

#endif	/* SUSPECT_H */

