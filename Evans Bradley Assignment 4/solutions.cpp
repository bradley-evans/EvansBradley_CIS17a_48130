#include "solutions.h"

int solution13_3()  {
    bool exit = false;
    int  modelYear;    
    string make;
    char choice;
    
    cout    << "Demonstrating Solution 13-3." << endl;
    
    cout << "Please enter a four-digit model year:" << endl;
    cout << "> ";
    cin >> modelYear;

    cout << "Please enter a vehicle make:" << endl;
    cout << "> ";
    cin >> make;

    Car car(modelYear,make);
    cout    << "You have entered vehicle:" << endl
            << "MAKE:       " << car.getmake() << endl
            << "MODEL YEAR: " << car.getyearModel() << endl;
    do {
        cout    << "Current speed is " << car.getspeed() << " MPH. Would you like to:" << endl
                << "[1] ACCELERATE" << endl
                << "[2] BRAKE" << endl
                << "[3] EXIT" << endl;
            cout << "> ";
            cin >> choice;
            switch (choice) {
                case '1': 
                    car.accelerate(); 
                    break;
                case '2': 
                    car.brake(); 
                    break;
                case '3': 
                    exit = true; 
                    break;
            }
    } while (!exit);
    return 0;
}

void solution13_4() {
    string name;
    string address;
    string age;
    string phone;
    
    cin.ignore();
    cout << "Enter name:         ";
    getline(cin,name);
    cout << "Enter address:      ";
    getline(cin,address);
    cout << "Enter age:          ";
    getline(cin,age);
    cout << "Enter phone number: ";
    getline(cin,phone);
    PersInfo person(name,address,age,phone);
    cout    << "Information saved!" << endl
            << "NAME:    " << person.getName() << endl
            << "ADDRESS: " << person.getAddress() << endl
            << "AGE:     " << person.getAge() << endl
            << "PHONE:   " << person.getPhone() << endl;
}

void solution13_8() {
    float radius;
    bool isValid = false;
    do {
        cout    << "Enter a circle's radius: ";
        cin >> radius;
        if (radius > 0) { isValid = true; }
        else { cout << "\nRadius must be greater than zero!\n"; }
    } while (!isValid);
    Circle circle(radius);
    cout    << "The circle has the following dimensions: " << endl
            << "Radius:        " << circle.getRadius() << endl
            << "Diameter:      " << circle.getDiameter() << endl
            << "Area:          " << circle.getArea() << endl
            << "Circumference: " << circle.getCircumference() << endl;          
} 

void solution13_9() {
    int pop,deaths,births;
    
    cout << "Please enter a population size:              ";
    cin >> pop;
    cout << "Please enter the number of births in period: ";
    cin >> births;
    cout << "Please enter the number of deaths in period: ";
    cin >> deaths;
    while (pop<1) {
        cout << "\nPlease enter a population size larger than 1: ";
        cin >> pop;
    }
    while (births<0||births==0) { 
        cout << "\nPlease enter a number of births greater than zero.";
        cin >> births;
    }
    while (deaths<0||deaths==0) { 
        cout << "\nPlease enter a number of deaths greater than zero.";
        cin >> deaths;
    }
    Population population(pop,deaths,births);
    cout << "The birth rate is: " << population.getBirthrate() << endl;
    cout << "The death rate is: " << population.getDeathrate() << endl;
}

void solution14_2() {
    int julian = -1;
    cout << "Please enter a Julian date: ";
    cin >> julian;
    DayOfYear date(julian);
    if (date.testValid()) {
        date.parseDate();
        cout << "The date given by julian date " << julian << " is " << date.getMonth() << " " << date.getDay() << "." << endl;
    } else {
        cout << "That was an invalid date!" << endl;
    }
}

void solution14_3() {
    string month;
    int day;
    cout << "Please enter a month: ";
    cin >> month;
    cout << "Please enter a day:   ";
    cin >> day;
    DayOfYear julian(1);
    julian.takeMonth(month);
    julian.takeDay(day);
    julian.parseJulian();
    cout << "The julian date is [" << julian.getJulian() << "]" << endl;
    
}

void solution14_4() {
    float hours;
    float days;
    NumDays result(0);
    cout << "NOTE: Overloaded iterator not functioning correctly.";
    cout << "Please enter a number of hours: ";
    cin >> hours;
    NumDays ndays1(hours);
    cout << "That equates to " << ndays1.getDays() << " work days!" << endl;
    cout << "Please enter a number of days: ";
    cin >> days;
    NumDays ndays2(0);
    ndays2.setDays(days);
    cout << "That equates to " << ndays2.getHours() << " work hours!" << endl;
    cout << "Overloaded operations:     Input1=" << ndays1.getHours() << " Input2=" << ndays2.getHours() << endl;
    result = ndays1+ndays2;
    cout << "Input1 + Input2 = " << result.getDays() << " workdays." << endl;
    result = ndays1-ndays2;
    cout << "Input1 - Input2 = " << result.getDays() << " workdays." << endl;
    cout << "Current result in hours: " << result.getHours() << endl;
    result = result++;
    cout << "result++ = " << result.getHours() << endl;
    result = result--;
    cout << "result-- = " << result.getHours() << endl;
}

void solution14_5() {
    int vac;
    int unpaid;
    int sick;
    string name;
    string id;
    cout << "Enter a current number of vacation days: ";
    cin >> vac;
    cout << "Enter a current number of unpaid vacation days: ";
    cin >> unpaid;
    cout << "Enter a current number of sick days: ";
    cin >> sick;
    cout << "Enter employee name: ";
    cin >> name;
    cout << "Enter employee ID: ";
    cin >> id;
    TimeOff result(sick,vac,unpaid,name,id);
    bool exit=false;
    char choice;
    do {
        cout    << "EMPLOYEE NAME: " << result.getName() << endl
                << "EMPLOYEE ID:   " << result.getID() << endl
                << result.getMaxSick() << " sick days accrued." << endl
                << result.getTakeSick() << " sick days used." << endl
                << result.getMaxVac() << " vacation days accrued." << endl
                << result.getTakeVac() << " vacation days used." << endl
                << result.getMaxUnpaid() << " unpaid days accrued." << endl
                << result.getTakeUnpaid() << " unpaid days used." << endl;
        cout << "[1]: Add a sick day" << endl
                << "[2]: Take a sick day" << endl
                << "[3]: Add a vacation day" << endl
                << "[4]: Take a vacation day" << endl
                << "[5]: Add an unpaid vacation day" << endl
                << "[6]: Take an unpaid vacation day" << endl
                << "[7]: Exit" << endl
                << "> ";
        cin >> choice;
        switch (choice) {
            case '1': result.addSickday(); break;
            case '2': result.takeSickday(); break;
            case '3': result.addVac(); break;
            case '4': result.takeVac(); break;
            case '5': result.addUnpaid(); break;
            case '6': result.takeUnpaid(); break;
            case '7': exit=true; break;
        }
    } while (!exit);           
            
}