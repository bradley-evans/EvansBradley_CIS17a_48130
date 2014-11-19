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
class Car {
private:
    int     yearModel;
    string  make;
    int     speed;
public:
    Car(int,string);        // Constructor
    int getyearModel();     // Accessor
    string getmake();       // Accessor
    void accelerate();      // Mutator
    void brake();           // Mutator
    int getspeed();         // Mutator
};

class PersInfo {
private:
    string name;
    string address;
    string age;
    string phone; 
public:
    PersInfo(string,string,string,string);
    string getName();
    string getAddress();
    string getAge();
    string getPhone();
    
};

class Circle {
private:
    float radius;
    float pi = 3.14;  
public:
    Circle();
    Circle(float);
    void setRadius(float);
    double getRadius();
    double getArea();
    double getDiameter();
    double getCircumference();
};

class Population {
private:
    int pop;
    int births;
    int deaths;
public:
    Population(int,int,int);
    int getPop();
    float getBirthrate();
    float getDeathrate();
};

class DayOfYear {
private:
    string monthName[12] = {"January","February","March","April","May","June","July",
                        "August","September","October","November", "December"  };
    int monthDays[12] = {  31, 59, 90, 120, 151, 181,
                         212, 243, 273, 304, 334, 365};
    int julian;
    bool valid = true;
    string month;
    int monthNum;
    int day;
    int dayOfMonth(int month) const;
public:
    DayOfYear(int);
    void parseDate();
    string getMonth();
    int getDay();
    bool testValid();
    void takeMonth(string);
    void takeDay(int);
    void parseJulian();
    int getJulian();
    ~DayOfYear() {};
};

class NumDays {
private:
    float days;
    float hours;
public:
    NumDays(int);
    NumDays();
    int getDays();
    int getHours();
    void setDays(float);
    void setHours(float);
    NumDays operator+(NumDays&);
    NumDays operator-(NumDays&);
    NumDays operator++(int);
    NumDays operator--(int);
};

class TimeOff {
private:
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;
    string id;
    string name;
public:
    TimeOff(int, int, int ,string, string);
    TimeOff();
    void takeSickday();
    void addSickday();
    void addVac();
    void takeVac();
    void addUnpaid();
    void takeUnpaid();
    string getName();
    string getID();
    float getMaxSick();
    float getTakeSick();
    float getMaxUnpaid();
    float getTakeUnpaid();
    float getMaxVac();
    float getTakeVac();
    
};

#endif	/* CLASSES_H */

