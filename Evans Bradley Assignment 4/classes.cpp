/* 
 * File:   newClass.cpp
 * Author: Bradley Evans
 * 
 * Created on November 16, 2014, 11:48 AM
 */

#include "classes.h"
using namespace std;

/**SOLUTION 13-3
 * 
 */
Car::Car(int in_yearModel, string in_make) {
    yearModel = in_yearModel;
    make = in_make;
    speed = 0;
}
int Car::getyearModel() {
    return yearModel;
}
string Car::getmake() {
    return make;
}
void Car::accelerate() {
    speed = speed + 5;
}
void Car::brake() {
    if (speed > 4) { speed = speed - 5; }
}
int Car::getspeed() {
    return speed;
}
/**SOLUTION 13-4
 * 
 */
PersInfo::PersInfo(string in_name, string in_address, string in_age, string in_phone) {
    name = in_name;
    address = in_address;
    age = in_age;
    phone = in_phone;
}
string PersInfo::getName() {
    return name;
}
string PersInfo::getAddress() {
    return address;
}
string PersInfo::getAge() {
    return age;
}
string PersInfo::getPhone() {
    return phone;
}

Circle::Circle() {
     radius = 1.0;   
}
Circle::Circle(float in_radius) {
    radius = in_radius; 
}
void Circle::setRadius(float in_radius) { 
    radius = in_radius;
}
double Circle::getRadius() {
   return radius;   
}
double Circle::getArea() {
   return pi * radius * radius;
}
double Circle::getDiameter() {
      return radius * 2;
}
double Circle::getCircumference() {
     return 2 * pi * radius;   
}

Population::Population(int in_pop,int in_deaths,int in_births){
    pop = in_pop;
    deaths = in_deaths;
    births = in_births;
}
int Population::getPop(){
    return pop;
}
float Population::getBirthrate(){
    float birthrate;
    birthrate = (static_cast<float>(births) / static_cast<float>(pop));
    return birthrate;
}
float Population::getDeathrate(){
    float deathrate;
    deathrate = (static_cast<float>(deaths) / static_cast<float>(pop));
    return deathrate;
}

DayOfYear::DayOfYear(int in_julian) {
    if (in_julian > 0 && in_julian < 366) {
        julian = in_julian;
    } else {
        cout << "Date entered is invalid!";
        valid = false;                
    }
}
bool DayOfYear::testValid() {
    return valid;
}
void DayOfYear::parseDate() {
    int i = 0;
    while (julian > monthDays[i]) {
        i++;
    }
    month = monthName[i];
    day = julian - monthDays[i-1];
}
string DayOfYear::getMonth() {
    return month;
}
int DayOfYear::getDay() {
    return day;
}
void DayOfYear::takeMonth(string in_month) {
    int i = 0;
    while (in_month != monthName[i]) {
        i++;
    }
    monthNum = monthDays[i]; 
}
void DayOfYear::takeDay(int in_day) {
    day = in_day;
}
void DayOfYear::parseJulian() {
    julian = day + monthNum;
}
int DayOfYear::getJulian() {
    return julian;
}

NumDays::NumDays(int in_hours) {
    hours = in_hours;
    days = in_hours / 8;
}
NumDays::NumDays() {
    hours = 0;
    days = 0;            
}
int NumDays::getDays() {
    return days;
}
int NumDays::getHours() {
    return hours;
}
void NumDays::setDays(float in_days) {
    days = in_days;
    hours = in_days*8;
}
void NumDays::setHours(float in_hours) {
    days = in_hours/8;
    hours = in_hours;
}
NumDays NumDays::operator + (NumDays& x) {
    NumDays op;
    op.setHours(this->getHours()+x.getHours());
    return op;
}
NumDays NumDays::operator - (NumDays& x) { 
    NumDays op;
    op.setHours(this->getHours()-x.getHours());
    return op;
}  
// POSTFIX
NumDays NumDays::operator ++(int) {
    NumDays op = *this;
    this->setHours(this->getHours() + 1);
    return op;
}
NumDays NumDays::operator --(int) {
    NumDays op = *this;
    this->setHours(this->getHours() - 1);
    return op;
}

TimeOff::TimeOff(int sick, int vac, int unpaid,string _id, string _name) {
    maxSickDays.setDays(sick);
    maxVacation.setDays(vac);
    if (maxVacation.getDays() > 240) {
        cout << "\nA maximum of 240 days are allowed!\n";
        maxVacation.setDays(240);
    }
    maxUnpaid.setDays(unpaid);
    sickTaken.setDays(0);
    vacTaken.setDays(0);
    unpaidTaken.setDays(0);
    id = _id;
    name = _name;
}
string TimeOff::getName() {
    return name;
}
string TimeOff::getID() {
    return id;
}
float TimeOff::getMaxSick() {
    return maxSickDays.getDays();
}
float TimeOff::getMaxUnpaid() {
    return maxUnpaid.getDays();
}
float TimeOff::getMaxVac() {
    return maxVacation.getDays();
}
float TimeOff::getTakeSick() {
    return sickTaken.getDays();
}
float TimeOff::getTakeUnpaid() {
    return unpaidTaken.getDays();
}
float TimeOff::getTakeVac() {
    return vacTaken.getDays();
}
void TimeOff::addVac() {
    maxVacation.setDays(maxVacation.getDays()+1);
}
void TimeOff::addSickday() {
    maxSickDays.setDays(maxSickDays.getDays()+1);
}
void TimeOff::addUnpaid() {
    maxUnpaid.setDays(maxUnpaid.getDays()+1);
}
void TimeOff::takeSickday() {
    sickTaken.setDays(sickTaken.getDays()+1);
}
void TimeOff::takeVac() {
    vacTaken.setDays(vacTaken.getDays()+1);
}
void TimeOff::takeUnpaid() {
    unpaidTaken.setDays(unpaidTaken.getDays()+1);
}