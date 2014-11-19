/* 
 * File:   main.cpp
 * Author: Bradley Evans
 *
 * Created on November 15, 2014, 3:44 PM
 */

#include <iostream>
#include "evans_std.h"
#include "solutions.h"
using namespace std;

int main() 
{
    char    choice;             ///*menu option selected by user
    bool    isExit = false;     ///*Is the user ready to exit?        
    string  regexpr = " ";      ///*A regular expression.    

    cout    << "Programmed by:" << endl
            << "Bradley Evans, Student #2465773" << endl
            << "For Prof. M. Lehr, CIS 17A, 14FAL" << endl
            << endl
            << "All solutions are from the 8th edition." << endl; 

    do {
        displayMenu (choice);
        switch (choice)	{
            case '1':               ///* Dice Roller
                cout	<< endl;
                solution13_3();
                localPause();
                break;
            case '2':
                cout	<< endl;
                solution13_4();
                localPause();
                break;
            case '3':
                cout	<< endl;    
                solution13_8();
                localPause();
                break; 
            case '4':
                cout	<< endl;
                solution13_9();
                localPause();
                break;
            case '5':
                cout	<< endl;
                solution14_2();
                localPause();
                break;
            case '6':
                cout	<< endl;
                solution14_3();
                localPause();
                break;
            case '7':
                cout	<< endl;
                solution14_4();
                localPause();
                break;
            case '8':
                cout	<< endl;
                solution14_5();
                break;
            case '9':
                cout	<< endl;

                localPause();
                break;
            case '0':
                cout	<< endl;
                isExit = true;
                break;
            }
        } while (!isExit);
        
    return 0;
}

