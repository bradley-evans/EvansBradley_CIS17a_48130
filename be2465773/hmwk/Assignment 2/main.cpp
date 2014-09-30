/*
Week 1 - 2

Bradley Evans
*/

//Includes
#include <iostream>
#include <string>
#include <string.h>
#include <cctype>
using namespace std;	

//Function Prototypes
	void displayMenu (char& choice);	//Display menu. Validate input.
        bool replayFunc (char& localChoice);    //See if user wants to run func again.
        void localPause ();                     // local pause function
        
        // Functions for homework questions.
        void takeCString (char charArray[], int &cstrLength);  // Take the string as input.
        void wordCount (char charArray[], int cstrLength);    // Get a word and character count.
        void reverseString (char charArray[], int cstrLength); // Reverse the string
        void sentenceCaps (char charArray[], int cstrLength); // Capitalize sentences.
        void morseTrans (char charArray[], int cstrLength); // Translate string into morse code.
        void freqCounter (char charArray[],int cstrLength); // Frequency analysis of characters.

        const int MAXLENGTH = 200;                 // Length of character arrays.
        
//Main
int main() 				
{
	char    choice;             // menu option selected by user
	bool    isExit = false;     // Did the user select 'exit'?
        int i = 0;                  // iterator
        
        // Variables related to homework begin --------------
        char charArray[MAXLENGTH] = "this is a placeholder. string.";   // Character array
        char *chptr = charArray;                                        // Character pointer
        int cstrLength = 30;                                            // cstring Length
        
        
	cout	<< "Programmed by:" << endl
                << "Bradley Evans, Student #2465773" << endl
                << "For Prof. M. Lehr, CIS 17A, 14FAL" << endl
                << endl
                << "All solutions are from the 8th edition." << endl; 
        
	do {
		displayMenu (choice);
		switch (choice)	{
			case '1':
                                cout	<< endl;
                                takeCString(chptr,cstrLength);
                                localPause();
				break;
                        case '2':
                                cout	<< endl;
                                wordCount(chptr,cstrLength);
                                localPause();
                                break;
                        case '3':
                                cout	<< endl;    
                                reverseString(chptr,cstrLength);
                                localPause();
                                break; 
                        case '4':
                                cout	<< endl;
                                sentenceCaps(chptr,cstrLength);
                                localPause();
                                break;
                        case '5':
                                cout	<< endl;
                                morseTrans(chptr,cstrLength);
                                localPause();
                                break;
                        case '6':
                                cout	<< endl;
                                freqCounter(chptr,cstrLength);
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
                        << "[1] - Input a C-string." << endl
                        << "[2] - Word and Character Count" << endl
                        << "[3] - Reverse the String" << endl
                        << "[4] - Capitalize sentences." << endl
                        << "[5] - Morse Code Translator" << endl 
                        << "[6] - Frequency Analysis" << endl                 /*
                        << "[7] - " << endl
                        << "[8] - " << endl
                        << "[9] - " << endl                                     */       
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

void takeCString (char charArray[], int &cstrLength) // take user string.
{
    cout    << "Please type out a string to store in memory: ";
    cin.ignore();
    cin.getline(charArray,MAXLENGTH);
    cout    << "\nThe string stored in memory is [ " << charArray << " ]" << " with length " << strlen(charArray);
    cstrLength = strlen(charArray);   
    cout    << endl;
}

void wordCount (char charArray[], int cstrLength) // count letters and words in the string
{
    int i = 0;  // iterator
    int chars = 0; // charcount
    int words = 1; // wordcount
    
    for (i=0;i<cstrLength;i++) {
        if (charArray[i]==' ') {
            words++;
        } else if (charArray[i]!='\0') {
            chars++;
        }
    }
    cout    << endl
            << "Characters: " << chars << endl
            << "Words:      " << words << endl
            << endl;
    
}

void reverseString (char charArray[], int cstrLength) // reverse the string
{
    char front;
    char back;
    int i = 0;
    int j = (cstrLength-1);
    int mid = cstrLength / 2;
    
    cout << "Original string:  [ " << charArray << " ]\n";
    
    for (i=0;i<mid;i++){
        front = charArray[i];
        back = charArray[j];
        charArray[i] = back;
        charArray[j] = front;
        j--;
    }
    
    cout << " Reversed string: [ " << charArray << " ]\n";
    
    j = (cstrLength-1);         // get everything back to normal for other stuff
    for (i=0;i<mid;i++){
        front = charArray[i];
        back = charArray[j];
        charArray[i] = back;
        charArray[j] = front;
        j--;
    }
}

void sentenceCaps (char charArray[], int cstrLength) // assuming input is good, correct sentences
{
    int i = 0;
    cout << "Assuming you input a sensible phrase with some periods, the sentence is corrected as: \n"
         << "Original string: [ " << charArray << " ]" << endl;
    
    charArray[0]=toupper(charArray[0]);
    for (i=1;i<cstrLength;i++) {
        if (charArray[i]=='.') {
            if (charArray[i+1]==' ') {
                charArray[i+2]=toupper(charArray[i+2]);
            } else {
                charArray[i+1]=toupper(charArray[i+1]);
            }
        }
    }
    
    cout << "Corrected array: [ " << charArray << " ]\n";
}

void morseTrans (char charArray[], int cstrLength)
{
    int i=0;
    int j=0;
    int match;
    bool isMatch = false;
    string morse[41] =    {" ", "--..--", ".-.-.-","..--..",                  // space, comma, period, ?
                        "-----",".----","..---","...--","....-","....."     // 0,1,2,3,4,5
                        "-....","--...","---..","----.",                    // 6,7,8,9
                        ".-","-...","-.-.","-..",".","..-.","--.","...."    // ABCDEFGH
                        "..",".---","-.-",".-..","--","-.","---",".--."     // IJKLMNOP
                        "--.-",".-.","...","-","..-","...-",".--","-..-"    // QRSTUVWX
                        "-.--","--.."};                                     // YZ
    char alphabet[41] =   " ,.?0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // First, get string into all caps
    for (i=0;i<cstrLength;i++){
        charArray[i]=toupper(charArray[i]);
    }
    cout << "Translating [ " << charArray << " ] into morse code:\n";
    for (i=0;i<cstrLength;i++){
        match = 0;
        for (j=0;j<41;j++){
            if (charArray[i]==alphabet[j]){
                match=j;
            }
        }
        cout << morse[match];
    }
    cout << "\nEND OF MORSE CODE.";
    localPause();
          
}
            
void freqCounter (char charArray[],int cstrLength)
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int freqArray[26]= {00000000000000000000000000};
    int i=0;
    int j=0;
    int max = 0;
    int min = 0;
    char cmax = ' ';
    char cmin = ' ';   
    
    // First, get string into all caps
    for (i=0;i<cstrLength;i++){
        charArray[i]=toupper(charArray[i]);
    }
    // Conduct frequency analysis.
    for (i=0;i<cstrLength;i++){
        for (j=0;j<27;j++) {
            if (charArray[i]==alphabet[j]) {
                freqArray[j] = freqArray[j]+1;
            }
        }
    }
    // Sort results
    
    for (i=0;i<26;i++) {
        for (j=(i+1);j<26;j++) {
            if (freqArray[i]<freqArray[j]) {
                max = freqArray[j];
                min = freqArray[i];
                freqArray[i] = max;
                freqArray[j] = min;
                cmax = alphabet[j];
                cmin = alphabet[i];
                alphabet[i] = cmax;
                alphabet[j] = cmin;   
            }                
        }
    }
    cout    << "The top ten most commonly occuring letters, as ranked, are: " << endl
            << alphabet[0] << " with " << freqArray[0] << " occurrences.\n"
            << alphabet[1] << " with " << freqArray[1] << " occurrences.\n"
            << alphabet[2] << " with " << freqArray[2] << " occurrences.\n"
            << alphabet[3] << " with " << freqArray[3] << " occurrences.\n"
            << alphabet[4] << " with " << freqArray[4] << " occurrences.\n"
            << endl;
    
}