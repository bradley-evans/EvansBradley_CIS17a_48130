/* 
 * File:   prob_3.h
 * Author: Bradley Evans
 *
 * Created on October 24, 2014, 2:00 AM
 */

#ifndef PROB_3_H
#define	PROB_3_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "evans_standard.h"
using namespace std;

void solution_3() ;
void displayResult() ;
void takeIntArray(int* &intarray, int &intcount) ;
float findMedian (int *arr, int arrSize) ;
float findMean(int *arr, int arrSize) ;
void findMode (int *arr, int size, int* &listmodes, int &currMax, int &numModes);
void sortArray (int *&arr, int arrSize) ;
void avgmedmode_(int *listmodes, int numModes, float mean, float median, int maxoccurs) ;

#endif	/* PROB_3_H */

