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
#include "evans_standard.h"
using namespace std;

void solution_4();
void encryptApp();
void decryptApp();
void encrypt(char** &pt, int rows);
void decrypt(char** &pt, int rows);
void showArray(char** pt, int rows);
void takeArray(char** &pt, int rows);

#endif	/* PROB_1_H */

