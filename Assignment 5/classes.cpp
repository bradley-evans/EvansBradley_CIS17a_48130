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
    if (in_num < 10000) { num = in_num; } else { throw BadNum(in_num); }
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
MilTime::MilTime(int in_milHours, int in_milSeconds) : Time() {
    if (in_milHours > 2359) { throw BadTime(in_milHours); }
    if (in_milSeconds > 60) { throw BadTime(in_milSeconds); }
    milHours = in_milHours;
    milSeconds = in_milSeconds;
    hour = (milHours / 100);
    min = (milHours - (hour * 100));
    sec = milSeconds;
}
MilTime::MilTime() : Time() {
    milHours = 0;
    milSeconds = 0;
}
void MilTime::setmilHours(int in_hr) {
    if (in_hr < 2400 && in_hr > -1) {
        milHours = in_hr;
    } else {
        throw BadTime(in_hr);
    }
}
void MilTime::setmilSeconds(int in_sec) {
    if (in_sec < 61 && in_sec > -1) {
        milSeconds = in_sec;
        hour = (milHours / 100);
        min = (milHours - (hour * 100));
    } else {
        throw BadTime(in_sec);
    }
}
