/* 
 * File:   prob_1.h
 * Author: Bradley Evans
 *
 * Created on October 24, 2014, 2:00 AM
 */

#ifndef PROB_2_H
#define	PROB_2_H

#include <iostream>
#include <string>
using namespace std;

struct Paychart {
    string  name;       ///< Employee name.
    int     hours;      ///< Number of hours worked.
    float   wage;       ///< Hourly wage for an employee.
    float   earnings;   ///< Earnings for employee this period
} ;

void solution_2 () ;

void collectEmployee(Paychart* &employee, int i, int &counter);

int findEarnings (float wage, int hours) ;


#endif	/* PROB_2_H */

