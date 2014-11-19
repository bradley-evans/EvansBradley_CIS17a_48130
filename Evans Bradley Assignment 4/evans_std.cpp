#include "evans_std.h"
using namespace std;

void displayMenu (char& choice)
{
	bool	choiceValid = false; // Is the menu input valid?
	
	do {
		cout	<< endl;
		cout	<< "*****************************************" << endl
			<< "             m a i n  m e n u            " << endl
			<< "*****************************************" << endl;

		cout	<< "Please select from the following options:" << endl
                        << "[1] - Solution 13-3" << endl
                        << "[2] - Solution 13-4" << endl
                        << "[3] - Solution 13-8" << endl
                        << "[4] - Solution 13-9" << endl
                        << "[5] - Solution 14-2" << endl 
                        << "[6] - Solution 14-3" << endl                
                        << "[7] - Solution 14-4" << endl
                        << "[8] - Solution 14-5" << endl
                        << "[9] - " << endl                                            
                        << "[0] - Exit the program." << endl       
                        << endl;
		cin	>> choice;
                
		if	(  choice == '1'    // Available menu options
			|| choice == '2' 
			|| choice == '3' 
			|| choice == '4'        
			|| choice == '5'        
			|| choice == '6' 
			|| choice == '7' 
			|| choice == '8'
                        || choice == '9' 
                        || choice == '0'        
                        )
		{
			choiceValid = true;
		} else {
                    cin.ignore();
                    cout    << "**Choice invalid. Please try again.**" << endl
                            << "(nice try though)" << endl
                            << endl;
                    choiceValid = false;
		} 
	} while (!choiceValid);
}

bool replayFunc (char& localChoice) 
{
    bool isValid = false;
    
    do {
        if (localChoice == 'Y' || localChoice == 'y') {
            isValid = true;
            return false;
        } else if (localChoice == 'N' || localChoice == 'n') {
            isValid = true;
            return true;
        } else {
            cout    << endl
                    << "Invalid input. Please try again: ";
            cin     >> localChoice;               
            isValid = false;
        }           
    } while (!isValid);
    return false;
}

void localPause ()
{
        cout << endl;
        cin.ignore();
        cout << "Press [ENTER] to continue...";
        cin.get();
        cout << endl;
}

bool regexValidate (string expr, string teststring) 
{
    regex ex(expr);
    if (regex_match(teststring,ex)) {
        return true;
    }
    return false;
}