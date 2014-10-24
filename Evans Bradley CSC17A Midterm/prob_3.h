/* 
 * File:   prob_1.h
 * Author: Bradley Evans
 *
 * Created on October 24, 2014, 2:00 AM
 */

#ifndef PROB_3_H
#define	PROB_3_H

#include <iostream>
#include <iomanip>
using namespace std;

struct statsResult  ///< Struct required by problem description.
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

void solution_3();

#endif	/* PROB_3_H */

