/*
 * Chapter 12 Solutions
 *
 * Bradley Evans
 */

//Includes
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // std::transform
using namespace std;	

//Function Prototypes
	void displayMenu (char& choice);	//Display menu. Validate input
        bool replayFunc (char& localChoice);    //See if user wants to run func again
        void localPause ();                     // local pause function
        
        // Functions for homework questions.
        void setFileName(string &filename);         // Open a file specified by user
        int  displayFile(string &filename);         // Display file contents
        void searchString(string &filename);        // Search the file for a string
        
        
//Main
int main() 				
{
	char    choice;             // menu option selected by user
	bool    isExit = false;     // Did the user select 'exit'?
        int     i = 0;                  // iterator
        
        // Variables related to homework begin --------------
        bool        isFileOpen = false;     // Is a file currently open?
        string      filename = "NONE";      // Filename currently in use.
        string      filename_2 = "NONE";    // Secondary filename.

        
	cout	<< "Programmed by:" << endl
                << "Bradley Evans, Student #2465773" << endl
                << "For Prof. M. Lehr, CIS 17A, 14FAL" << endl
                << endl
                << "All solutions are from the 8th edition." << endl; 
        
	do {
		displayMenu (choice);
                cout    << "CURRENT FILE IN USE: " << filename  // For the CH12 solution set
                        << endl;
		switch (choice)	{
			case '1':
                                cout	<< endl;
                                setFileName(filename);
                                localPause();
				break;
                        case '2':
                                cout	<< endl;
                                
                                localPause();
                                break;
                        case '3':
                                cout	<< endl;    
                                
                                localPause();
                                break; 
                        case '4':
                                cout	<< endl;
                                
                                localPause();
                                break;
                        case '5':
                                cout	<< endl;
                                
                                localPause();
                                break;
                        case '6':
                                cout	<< endl;
                                
                                localPause();
                                break;
                        case '7':
                                cout	<< endl;
                            
                                break;
                        case '8':
                                cout	<< endl;
                            
                                break;
                        case '9':
                                cout    << endl;
                            
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
                        << "[4] - Encrypt/decrypt the file" << endl
                        << "[5] - Write a pointer array of integers to the file" << endl 
                        << "[6] - Write text to the file" << endl                
                        << "[7] - " << endl
                        << "[8] - " << endl
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
}

void localPause ()
{
        cout << endl;
        cin.ignore();
        cout << "Press [ENTER] to continue...";
        cin.get();
        cout << endl;
}

/* Begin functions for
 * homework assignments.
 */

void setFileName(string &filename) // User chooses and sets a filename.
{
    fstream testFile; 
    
    cout    << "Enter the name of a text file.\n"
            << "     - Do not include a file extension!\n"
            << "     - If the file does not exist, it will be created.\n"
            << "> ";
    // Get the filename to all lowercase, add .txt, for ~consistency~
    cin     >> filename;
    filename = filename + ".txt";
    std::transform(filename.begin(),filename.end(),filename.begin(),::tolower);
    
    testFile.open(filename.c_str(), ios::in);
    if (testFile.fail()) {                      // If the file doesn't exist, create it.
        cout << "\nCreating " << filename << "..." << endl;
        testFile.open(filename.c_str(), ios::out);     
    } else {                                    // Else, acknowledge that the file exists.
        cout << "File [ " << filename << " ] is open!" << endl;
    }   
    
}

int displayFile(string &filename) // Displays contents of selected file, one line at a time.
{
    int         i = 0;          // iterator
    int         numLines = 1;   // number of lines
    string      output;         // character stream
    
    fstream     fileOutput;        
    
    fileOutput.open(filename.c_str(),ios::in);
    
    if (fileOutput.fail()) {
        cout << filename << " could not be opened! Please select another file.\n";
        return(0);
    }
    cout    << "Displaying [ " << filename << " ]";
    while (fileOutput >> output) 
    {
        cout    << output;
    }
        
    return(0);
}

void searchString(string &filename)
{
    ifstream    inFile;
    string      searchterm;
    
    inFile.open(filename.c_str());
    
    cout    << "Please enter the string you wish to search for:\n"
            << "> ";
    cin     >> searchterm;
    
 
}