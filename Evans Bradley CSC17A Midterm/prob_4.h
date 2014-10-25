/* 
 * File:   prob_1.h
 * Author: Bradley Evans
 *
 * Created on October 24, 2014, 2:00 AM
 */

#ifndef PROB_4_H
#define	PROB_4_H

#include <iostream>
#include <cctype>
#include <cstdlib>
#include "evans_standard.h"
using namespace std;

void solution_4();
void encrypt(int** &pt, int rows);
void decrypt(int** &pt, int rows);
void takeArray(char** &pt, int rows);

#endif	/* PROB_1_H */

