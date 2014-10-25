/*
 * MIDTERM -- 24 OCT 2014
 *
 * Bradley Evans
 */

//INCLUDE
#include <iostream>

//HEADERS
#include "evans_standard.h"
#include "prob_1.h"
#include "prob_2.h"
#include "prob_3.h"
#include "prob_4.h"
#include "prob_5.h"
#include "prob_6.h"
using namespace std;	

int main() 				
{
	char    choice;             // menu option selected by user
	bool    isExit = false;     // Did the user select 'exit'?

	cout	<< "Programmed by:" << endl
                << "Bradley Evans, Student #2465773" << endl
                << "For Prof. M. Lehr, CIS 17A, 14FAL" << endl
                << endl
                << "MIDTERM SOLUTIONS -- OCT 24 2014" << endl; 
        
	do {
		displayMenu (choice);
                switch (choice)	{
			case '1':
                                cout	<< endl;
                                solution_1();
                                localPause();
				break;
                        case '2':
                                //cout	<< endl;
                                solution_2();
                                localPause();
                                break;
                        case '3':
                                cout	<< endl;
                                solution_3();
                                localPause();
                                break; 
                        case '4':
                                cout	<< endl;
                                solution_4();
                                localPause();
                                break;
                        case '5':
                                cout	<< endl;
                                solution_5();
                                localPause();
                                break;
                        case '6':
                                cout	<< endl;
                                solution_6();
                                localPause();
                                break;
                        case '7':
                                cout	<< endl;
                                localPause();
                                break;
                        case '8':
                                cout	<< endl;
                                localPause();
                                break;
                        case '9':
                                cout    << endl;
                                localPause();
                                break;
                        case '0':
                                cout	<< endl;
                                isExit = true;
                                break;
                }
	} while (!isExit);
	cout << "Now exiting the program...\n";
        localPause();
        return(0);
}
