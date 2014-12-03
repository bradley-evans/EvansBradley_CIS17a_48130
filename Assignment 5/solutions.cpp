#include "solutions.h"

void solution15_1()  {
    cout    << "This class demonstrates the Employee class and " << endl
            << "its derivations." << endl;
    string name = "John Smith";
    int num = 123456;
    string date = "July 1, 2010";
    Employee employee(name,num,date);
    cout    << "Data from standard EMPLOYEE class: " << endl
            << "============================================" << endl
            << "NAME:       " << employee.getName() << endl
            << "EMPLOYEE #: " << employee.getNum() << endl
            << "DATE:       " << employee.getDate() << endl
            << "============================================" << endl;
    char shift = '1';
    float wage = 25.00;
    ProductionWorker worker(shift,wage,name,num,date);
    cout    << "Data from standard PRODUCTIONWORKER class: " << endl
            << "============================================" << endl
            << "NAME:       " << worker.getName() << endl
            << "EMPLOYEE #: " << worker.getNum() << endl
            << "DATE:       " << worker.getDate() << endl
            << "WAGE:       $" << worker.getWage() << endl
            << "SHIFT:      " << worker.getShift() << endl
            << "============================================" << endl;
    localPause();
    float salary = 50000.00;
    float bonus = 3000.00;
    ShiftSupervisor supervisor(name,num,date,salary,bonus);
    cout    << "Data from standard SHIFTSUPERVISOR class: " << endl
            << "============================================" << endl
            << "NAME:       " << supervisor.getName() << endl
            << "EMPLOYEE #: " << supervisor.getNum() << endl
            << "DATE:       " << supervisor.getDate() << endl
            << "SALARY:     $" << supervisor.getSalary() << endl
            << "BONUS:      $" << supervisor.getBonus() << endl
            << "============================================" << endl;
    localPause();
    int trainingMin = 30;
    int trainingDone = 20;
    TeamLeader leader(name,num,date,wage,bonus,trainingMin,trainingDone);
    cout    << "Data from standard PRODUCTIONWORKER class: " << endl
            << "============================================" << endl
            << "NAME:       " << leader.getName() << endl
            << "EMPLOYEE #: " << leader.getNum() << endl
            << "DATE:       " << leader.getDate() << endl
            << "WAGE:       $" << leader.getWage() << endl
            << "BONUS:      $" << leader.getBonus() << endl
            << "TRNG MIN:   " << leader.getTrainingMin() << " hours." << endl
            << "TRNG DONE:  " << leader.getTrainingDone() << " hours." << endl
            << "============================================" << endl;
    localPause();
    cout    << "Program complete." << endl;
}

void solution15_4() {
    cout << "Inputting 24-hour time 1535:45..." << endl;
    int miltime = 1535;
    int milsec = 45;
    if (miltime < 2400) {
        MilTime time(miltime,milsec);
        cout    << "=================================================" << endl
                << "ORIGINAL INPUT TIME: " << miltime << ":" << milsec << endl
                << endl
                << "CONVERTED TIME: " << time.getHour() << ":" << time.getMin() << " and " << time.getSec() << " seconds." << endl
                << "=================================================" << endl;
    } else {
        cout << miltime << " is an invalid time!" << endl;
    }
    localPause();
    cout << "Setting start time to 1430..." << endl;
    int start = 1430;
    cout << "Setting end time to 1525..." << endl;
    int end = 1525;
    TimeClock clock(start,end);
    clock.getElapsed();
    cout    << "=================================================" << endl
            << "START TIME: " << start << "   END TIME: " << end << endl
            << endl
            << "ELAPSED: " << clock.getHour() << ":" << clock.getMin() << " and " << clock.getSec() << " seconds." << endl
            << "=================================================" << endl;
    localPause();
    cout << "Program complete.";
            
            
}

void solution16_2() {
    cout    << "An exception is thrown when a bad time is entered into class MilTime." << endl
            << "Entering time 2520 into MilTime, an invalid time... " << endl;
    MilTime time(0,0);
    int hours = 2520;
    int seconds = 0;
    try {
        time.setmilHours(hours);
    } catch (MilTime::BadTime err) {
        cout    << "Error! " << err.getBad() << " is not a valid input for time!" << endl;
    }
    try {
        time.setmilSeconds(seconds);
    } catch (MilTime::BadTime err) {
        cout    << "Error! " << err.getBad() << " is not a valid input for seconds!" << endl;
    }
    cout    << "Attempting to input 61 seconds as the number of seconds..." << endl;
    hours = 2220;
    seconds = 61;
    try {
        time.setmilHours(hours);
    } catch (MilTime::BadTime err) {
        cout    << "Error!" << err.getBad() << " is not a valid input for time!" << endl;
    }
    try {
        time.setmilSeconds(seconds);
    } catch (MilTime::BadTime err) {
        cout    << "Error!" << err.getBad() << " is not a valid input for seconds!" << endl;
    }     
} 

void solution16_16() {
    cout    << "Attempting to insert an employee number of 525252 into class Employee..." << endl;
    int num = 525252;
    string name = "John Smith";
    string date = "July 1, 1992";    
            
    try {
        Employee employee(name,num,date);
    } catch (Employee::BadNum err) {
        cout    << "Invalid input detected: " << err.getNum() << endl;
    }
}

void solution16_5() {
    char choice = '0';
    cout    << "The template class Total will keep a running total. Enter 0 to exit the loop." << endl;
    cout    << "Use floats or integers?" << endl
            << "[1] INTEGERS" << endl
            << "[2] FLOAT" << endl
            << "> ";
    cin     >> choice;
    if (choice == '1') {
        int num = 0;
        Total<int> tot(num);
        cout << "Please enter some integers: " << endl;
        do {
            cout << "> ";            
            cin >> num;
            tot.setRunTot(num);
            cout << "Current Total: " << tot.getTot() << endl;
            cin.clear();
        } while (num != 0);
    } else if (choice == '2') {
        float num2 = 0;
        Total<float> tot(num2);
        cout << "Please enter some integers: " << endl;
        do {
            cout << "> ";
            cin >> num2;
            tot.setRunTot(num2);
            cout << "Current Total: " << tot.getTot() << endl;
            cin.clear();
        } while (num2 != 0);
    } else {
        cout << "Input invalid!" << endl;
    }
    cout << "Program complete." << endl;
}
void solution16_3() {
    cout    << "Demonstration of MinMaxAbs class:" << endl
            << "INTEGERS: " << endl;
    int int1 = -120;
    int int2 = 230;
    cout    << "Integer 1: " << int1 << " | Integer 2: " << int2 << endl;
    MinMaxAbs<int> withInt(int1,int2);
    cout    << "Maximum Value: " << withInt.getMax() << endl
            << "Minimum Value: " << withInt.getMin() << endl
            << "Absolute Value: " << withInt.getAbs() << endl
            << "FLOATS: " << endl;
    int float1 = -120.10;
    int float2 = 230.55;
    cout    << "Float 1: " << setprecision(2) << fixed << float1 << " | Float 2: " << float2 << endl;
    MinMaxAbs<float> withFloat(float1,float2);
    cout    << "Maximum Value: " << withFloat.getMax() << endl
            << "Minimum Value: " << withFloat.getMin() << endl
            << "Absolute Value: " << withFloat.getAbs() << endl
            << "DOUBLES: " << endl;
    double double1 = -11231235.10;
    double double2 = 1231123.55;
    cout    << "Double 1: " << setprecision(2) << fixed << double1 << " | Float 2: " << double2 << endl;
    MinMaxAbs<double> withDouble(double1,double2);
    cout    << "Maximum Value: " << withDouble.getMax() << endl
            << "Minimum Value: " << withDouble.getMin() << endl
            << "Absolute Value: " << withDouble.getAbs() << endl;         
}