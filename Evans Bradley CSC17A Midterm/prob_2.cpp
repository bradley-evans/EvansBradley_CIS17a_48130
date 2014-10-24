
/**
 * Develop an application using an array of structures that will 
 * determine the gross pay for any number of employees input. The company pays 
 * "straight-time" for the first 20 hours worked, double time for 
 * all hours worked in excess of 20 hours but less than 40 hours, 
 * and triple time for any hours worked over 40 hours.
 * 
 * The program should be able to loop and input the employee's name, 
 * hours worked, and the rate of pay.  Once this has been done then 
 * the gross pay should be calculated.  Output all the pertinent information
 * with respect to the employee as a check and the process starts all over 
 * again until you input an invalid rate of pay or hours worked.  This
 * means a negative rate of pay or negative number of hours worked is
 * not acceptable.
 * 
 */

#include "prob_2.h"



void solution_2 () {
    int         num = 0;
    int         i = 0;
    int         counter = 1;
    int         netWages = 0;
    
    cin.clear();
    cin.ignore(10000,'\n');
    cout.setf( ios::fixed );
    cout.precision(2);    
    cout    << "How many records would you like to enter?" << endl
            << "> ";
    cin     >> num;
    cout    << endl;
    
    Paychart *employee = new Paychart[num];     ///< Enjoy this special just for you dynamic array of structs.

    for (i=0;i<num;i++) {
        cin.clear();                        // clear the buffer to prevent errors
        cin.ignore(10000,'\n');             // when the string is read into memory
        cout    << endl
                << "Employee #" << counter << endl
                << "NAME:          ";
        getline(cin, employee[i].name);
        cout    << endl
                << "HOURLY WAGE:   $";
        cin     >> employee[i].wage;
        cout    << endl
                << "HOURS WORKED:  ";
        cin     >> employee[i].hours;
        cout    << endl;
        employee[i].earnings = findEarnings(employee[i].wage,employee[i].hours);
        if (employee[i].earnings < 1) {
            cout    << "Warning! The earnings for an employee cannot be zero or a negative value!" << endl;
            netWages = 0;
            i = num + 1;
            cout    << "An error has occurred. Please try again." << endl;
        } else {
            cout    << "Total earnings for " << employee[i].name << " this period: $" << employee[i].earnings
                    << endl;
            netWages = netWages + employee[i].earnings;
            counter++;
        }  
    }
    delete []employee;
    cout << "Total wages paid out this period: $" << netWages << endl; 
    
}

int findEarnings (float wage, int hours) {
    int straighttime;
    int doubletime;
    int tripletime;
    float earnings;
    if (hours > 20 && hours < 40) {
        straighttime = 20;
        doubletime = hours - 20;
        tripletime = 0;
    } else if (hours > 20 && hours > 40)  {
        straighttime = 20;
        doubletime = 20;
        tripletime = hours - 40;
    } else if (hours < 20) {
        straighttime = hours;
        doubletime = 0;
        tripletime = 0;
    }
    earnings = wage * (straighttime + (2*doubletime) + (3*tripletime));
    return earnings;
}