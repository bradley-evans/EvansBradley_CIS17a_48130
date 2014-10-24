#include "evans_standard.h"

void displayMenu (char& choice)
{
	bool	choiceValid = false; // Is the menu input valid?
        bool    isArrayInMem = false; // Is there an array in memory?
	
	do {
		cout	<< endl;
		cout	<< "*****************************************" << endl
			<< "             m a i n  m e n u            " << endl
			<< "*****************************************" << endl;

		cout	<< "Please select from the following options:" << endl
                        << "[1] - Select / create a text file" << endl
                        << "[2] - Display contents of file" << endl
                        << "[3] - Search the file for a string" << endl
                        << "[4] - Encrypt/decrypt the file" << endl /*
                        << "[5] - Write a pointer array of integers to the file" << endl 
                        << "[6] - Write text to the file" << endl                
                        << "[7] - " << endl
                        << "[8] - " << endl
                        << "[9] - " << endl                                            
                        << "[0] - Exit the program." << endl        */
                        << endl;
		cin	>> choice;
                
		if	(  choice == '1'    // Available menu options
			|| choice == '2' 
			|| choice == '3' 
			|| choice == '4'        /*
			|| choice == '5'        
			|| choice == '6' 
			|| choice == '7' 
			|| choice == '8'
                        || choice == '9' 
                        || choice == '0'        */
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
        cin.ignore();
        cout << "Press [ENTER] to continue...";
        cin.get();
        cout << endl;
}
