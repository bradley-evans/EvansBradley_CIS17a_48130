/* 
 * File:   newClass.cpp
 * Author: Bradley Evans
 * 
 * Created on November 16, 2014, 11:48 AM
 */

#include "classes.h"
using namespace std;

/**SOLUTION 15-1, 2, 3
 * 
 */
Employee::Employee(string in_name, int in_num, string in_date) {
    name = in_name;
    num = in_num;
    date = in_date;
}
string Employee::getName() {
    return name;
}
int Employee::getNum() {
    return num;
}
string Employee::getDate() {
    return date;
}
char ProductionWorker::getShift() {
    return shift;
}
float ProductionWorker::getWage() {
    return wage;
}
