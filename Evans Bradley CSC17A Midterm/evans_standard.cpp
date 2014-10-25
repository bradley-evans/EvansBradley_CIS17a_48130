#include "evans_standard.h"

void displayMenu (char& choice)
{
	bool	choiceValid = false;        // Is the menu input valid?
	
	do {
		cout	<< endl;
		cout	<< "*****************************************" << endl
			<< "             m a i n  m e n u            " << endl
			<< "*****************************************" << endl;

		cout	<< "Please select from the following options:" << endl
                        << "[1] - Problem 1" << endl
                        << "[2] - Problem 2" << endl
                        << "[3] - Problem 3" << endl
                        << "[4] - Problem 4" << endl 
                        << "[5] - Problem 5" << endl 
                        << "[6] - Problem 6" << endl                /*               
                        << "[7] - " << endl
                        << "[8] - " << endl
                        << "[9] - " << endl                         */                   
                        << "[0] - Exit the program." << endl        
                        << endl
                        << "> ";
		cin	>> choice;
                cout    << endl;
                
		if	(  choice == '1'    // Available menu options
			|| choice == '2' 
			|| choice == '3' 
			|| choice == '4'        
			|| choice == '5'        
			|| choice == '6'        /*
			|| choice == '7'        
			|| choice == '8'
                        || choice == '9'        */
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
}

void localPause ()
{
        cout << endl;
        cin.clear();                        // clear the buffer to prevent errors
        cin.ignore(10000,'\n');  
        cout << "Press [ENTER] to continue...";
        cin.get();
        cout << endl;
}

void clearbuffer()
{
    cout << "\n...clearing the buffer (press enter if you get stuck here)...\n";
    cin.ignore(10000,'\n');
    cout.setf( ios::fixed );
}
