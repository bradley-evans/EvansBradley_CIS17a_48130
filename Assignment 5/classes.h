/* 
 * File:   newClass.h
 * Author: Bradley Evans
 *
 * Created on November 16, 2014, 11:48 AM
 */

#ifndef CLASSES_H
#define	CLASSES_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/**SOLUTION CH 15 1-3
 *
 */
class Employee {
private:
    string name;
    int num;
    string date;
public:
    class BadNum {
    private: int num;
    public:
        BadNum(int bad) { num = bad; }
        int getNum() { return num; }
    };
    Employee(string,int,string);
    string getName();
    int getNum();
    string getDate();
};
class ProductionWorker : public Employee {
protected:
    char shift;
    float wage;
public:
    ProductionWorker(char in_shift, float in_wage, string in_name, int in_num, string in_date) : 
        Employee(in_name,in_num,in_date) {
        shift = in_shift;
        wage = in_wage;
    }
    char getShift();
    float getWage();
};
class ShiftSupervisor : public Employee {
protected:
    float salary;
    float bonus;
public:
    ShiftSupervisor (string in_name, int in_num, string in_date, float in_salary, float in_bonus) :
        Employee (in_name,in_num,in_date) {
        salary = in_salary;
        bonus = in_bonus;
    }
    float getSalary() { return salary; }
    float getBonus() { return bonus; }
};
class TeamLeader : public Employee {
protected: 
    float wage;
    float bonus;
    int trainingMin;
    int trainingDone;
public:
    TeamLeader (string in_name, int in_num, string in_date, float in_wage, float in_bonus, int in_trainingMin, int in_trainingDone) :
    Employee (in_name,in_num,in_date) {
        wage = in_wage;
        bonus = in_bonus;
        trainingMin = in_trainingMin;
        trainingDone = in_trainingDone;
    }
    float getWage() { return wage; }
    float getBonus() { return bonus; }
    int getTrainingMin() { return trainingMin; }
    int getTrainingDone() { return trainingDone; }
};
/**SOLUTION CH 15 4-5
 * 
 */
class Time {
protected:
    int hour, min, sec;
public:
    Time() {
        hour = 0;
        min = 0;
        sec = 0;
    }
    Time(int in_hour, int in_min, int in_sec) {
        hour = in_hour;
        min = in_min;
        sec = in_sec;
    }    
    int getHour() { return hour; }
    int getMin() { return min; }
    int getSec() { return sec; }
    void setHour(int in_hour) { hour = in_hour; }
    void setMin(int in_min) { min = in_min; }
    void setSec(int in_sec) { sec = in_sec; }
};
class MilTime : public Time {
protected:
    int milHours;
    int milSeconds;
public:
    MilTime(int in_milHours, int in_milSeconds);
    MilTime(); 
    class BadTime {
    private: int bad;
    public:
        BadTime (int time) { bad = time; }
        int getBad() {return bad;}
    };
    int getmilHours() { return milHours; }
    int getmilSeconds() { return milSeconds; }
    void setmilHours(int);
    void setmilSeconds(int);
};
class TimeClock : public MilTime {
protected:
    int start;
    int end;
public:
    TimeClock (int in_start, int in_end) :
    MilTime () {
        if (in_start < 2400) { start = in_start; } else { throw BadTime(in_start); }
        if (in_end < 2400) { end = in_end; } else { throw BadTime(in_end); }
    }
    void getElapsed() {
        MilTime start_time(start,0);
        MilTime end_time(end,0);
        int totalmin_start, totalmin_end, totalmin_tot;
        totalmin_start = (start_time.getHour()*60) + start_time.getMin();
        totalmin_end = (end_time.getHour()*60) + end_time.getMin();
        totalmin_tot = (totalmin_end - totalmin_start);
        hour = (totalmin_tot/60);
        min = (totalmin_tot%60);
    }
};
template <class T>
class Total {
private:
    T tot;
public:
    Total(T) { tot = 0; }
    T getTot() { return tot; }
    T setRunTot(T num) { tot = tot+num; }
};

template <class T>
class MinMaxAbs {
private:
    T num1;
    T num2;
    T max;
    T min;
    T absval;
public:
    MinMaxAbs(T _num1,T _num2) { 
        num1 = _num1;
        num2 = _num2;
        if (num1>num2) {
            max = num1;
            min = num2;
        } else {
            max = num2;
            min = num1;
        }
        absval = abs(num1);
    }
    MinMaxAbs(T _num1) {
        num1 = _num1;
        num2 = _num1;
        if (num1>num2) {
            max = num1;
            min = num2;
        } else {
            max = num2;
            min = num1;
        }
        absval = abs(num1);
    }
    T getMax() { return max; }
    T getMin() { return min; }
    T getAbs() { return absval; }
};


#endif	/* CLASSES_H */

