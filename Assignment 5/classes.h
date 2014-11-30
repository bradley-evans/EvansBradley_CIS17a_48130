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
using namespace std;

/**SOLUTION 13-2
 *
 */
class Employee {
private:
    string name;
    int num;
    string date;
public:
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


#endif	/* CLASSES_H */

