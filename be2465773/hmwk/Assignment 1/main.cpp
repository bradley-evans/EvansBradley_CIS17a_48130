/*
Week 1 - 2

Bradley Evans
*/

//Includes
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string> 
#include <time.h>
#include <limits>
using namespace std;	

//Function Prototypes
	void displayMenu (char& choice);	//Display menu. Validate input.
        bool replayFunc (char& localChoice);         //See if user wants to run func again.
        void localPause ();                     // local pause function
        
        // Functions for homework questions.
	void genArray (int* &arr, int &arrSize, int &uniqueSize);   // Generate an array
        void displayArray (int arr[], int &arrSize, int &uniqueSize, bool isSorted);   // Function for Ch. 3 #13
	float findMean (int arr[], int &arrSize);   // Function for Ch. 4 #10
        int findMode (int arr[], int &arrSize);   // Function for Ch. 5 #11
        float findMedian  (int arr[], int &arrSize);   // Function for Ch. 6 #7
        void sortArray (int* &arr, int arrSize, bool &isSorted);   // Sorts the array
        void solution9_11(int arr[], int arrSize);
        void solution9_10(int arr[], int arrSize);
        void solution9_2();
        void solution9_12(int arr[], int arrSize);
//Main
int main() 				
{
	char    choice;             // menu option selected by user
	bool    isExit = false;     // Did the user select 'exit'?
        int     *arr;               // Dynamic array
        int     arrSize;            // Size of array
        int     uniqueSize = 0;     // length of unique string in array
        bool    isSorted = false;   // Is the array sorted?
        bool    isArray = false;

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
                                genArray(arr, arrSize, uniqueSize);
                                isSorted = false;
                                isArray = true;
                                cout << isSorted;
				break;
                        case '2':
                                cout	<< endl;
                                if (!isArray) { 
                                    cout << "No array in memory!\n"; 
                                    localPause();
                                    break; 
                                }
                                displayArray(arr, arrSize, uniqueSize, isSorted);
                                break;
                        case '3':
                                cout	<< endl;    
                                cout	<< endl;
                                if (!isArray) { 
                                    cout << "No array in memory!\n"; 
                                    localPause();
                                    break; 
                                }
				cout << "The MEAN of the array in memory is " << findMean(arr, arrSize) << "." << endl;
                                localPause();
                                break; 
                        case '4':
                                cout	<< endl;
                                                                cout	<< endl;
                                if (!isArray) { 
                                    cout << "No array in memory!\n";
                                    localPause();
                                    break; 
                                }
                                sortArray(arr, arrSize, isSorted);
                                cout << "The MODE of the array in memory is " << findMode(arr, arrSize) << ".";
                                localPause();
                                break;
                        case '5':
                                cout	<< endl;
                                sortArray(arr, arrSize, isSorted);
                                cout	<< endl;
                                if (!isArray) { 
                                    cout << "No array in memory!\n";
                                    localPause();
                                    break; 
                                }
                                cout << "The MEDIAN of the array in memory is " << findMedian(arr, arrSize) << ".\n";
                                localPause();
                                break;
                        case '6':
                                cout	<< endl;
                                cout	<< endl;
                                if (!isArray) { 
                                    cout << "No array in memory!\n"; 
                                    localPause();
                                    break; 
                                }
                                solution9_11(arr, arrSize);
                                break;
                        case '7':
                                cout	<< endl;
                                solution9_2();
                                break;
                        case '8':
                                cout	<< endl;
                                if (!isArray) { 
                                    cout << "No array in memory!\n"; 
                                    localPause();
                                    break;
                                }
                                solution9_10(arr, arrSize);
                                break;
                        case '9':
                                cout    << endl;
                                if (!isArray) { 
                                    cout << "No array in memory!\n"; 
                                    localPause();
                                    break;
                                }
                                solution9_12(arr, arrSize);
                                break;
                        case '0':
                                cout	<< endl;
                                isExit = true;
                                break;
                }
	} while (!isExit);
	
	cout << "Now exiting the program...\n";
        localPause();
        exit(0);
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
                        << "[1] - Generate an array" << endl
                        << "[2] - Display an array" << endl
                        << "[3] - Take the mean of the array" << endl
                        << "[4] - Take the mode of the array" << endl
                        << "[5] - Take the median of the array" << endl
                        << "[6] - Programming Challenge 9-11" << endl
                        << "[7] - Programming Challenge 9-2 and 9-3" << endl
                        << "[8] - Programming Challenge 9-10" << endl
                        << "[9] - Programming Challenge 9-12" << endl                        
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

bool replayFunc(char& localChoice) {
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
        cout << "Press [ENTER] to continue...";
        cin.get();
        cin.ignore();
        cout << endl;
}
    
void genArray (int *&arr, int &arrSize, int &uniqueSize)
{
    int lengthUnique    = 0;    // length of unique number
    int numRepeat       = 0;    // number of repetitions
    int i=0;                      // iterator
    int n=0;                      // iterator
    int currPos=0;                // track where in the array I am
    int tgtlength=0;              // length I need for the next repetition
    int s=0;                      // iterator
        
    cout    << "Specify a length for the repeating element of the array: ";
    cin     >> lengthUnique;
    cout    << endl
            << "Specify the number of repetitions:                       ";
    cin     >> numRepeat;
    cout    << endl;
    
    srand (time(NULL));     // use current time to seed rand()
    
    arrSize = 0;            // initialize array size and current pos as 0
    currPos = 0;
    
    for (i=0; i<lengthUnique; i++) {
        arr[i] = (rand()%10);
        arrSize++;
        currPos++;
    }
    s = 1;
    do {    

        tgtlength=currPos+lengthUnique;
        n=0;
        for (i=currPos;i<tgtlength;i++) {
            arr[i] = arr[n];
            n++;
            arrSize++;
            currPos++;
        }
        s++;
        
    } while (s<numRepeat);
    
    uniqueSize = lengthUnique;
    
    cout << "\nArray generation complete.";
    localPause();
}

void displayArray(int arr[], int &arrSize, int &uniqueSize, bool isSorted)
{
    int i;      // iterator
    int rptTest; // test for a repetition
    
    cout << endl;
    if (isSorted) {
        cout << "Array has been previously sorted!\n";
            for (i=0;i<arrSize;i++){
                cout << arr[i] << " ";
            }        
    } else {       
        cout << "Warning: Array has not been sorted!\n";
        for (i=0;i<arrSize;i++){
            cout << arr[i] << " ";
            rptTest = ((i+1) % uniqueSize);
            if (rptTest == 0 && i != 0) { cout << "(repeat) "; }
        }
    }
    
    cout << endl << endl;
    cout << "End of array.";
    localPause();
}

float findMean(int arr[], int &arrSize)
{
    int i=0;
    int total = 0;
    float mean = 0;
    
    for (i=0;i<arrSize;i++) {
        total = ( total + arr[i] );
    }
    mean = (float(total) / float(arrSize));
    return (mean);
}

int findMode (int arr[], int &arrSize)
{
    int i=0;
    float mode=0;
    int currNumber=0;
    int count=0;
    int maxcount=0;
    int numRepeats=1;
        
    for (i=0;i<arrSize;i++) {   
        if ( currNumber == arr[i] ) {
            count++;
        }
        if ( count > maxcount ) {
            mode = currNumber;
            maxcount = count;
        }/*
        if ( count == maxcount && count > 1) {
            numRepeats++;
            mode = (float(currNumber)+float(mode))/numRepeats;
        }*/
        if ( currNumber != arr[i]) {
            currNumber++;
            count = 0;
        }
    }
    return(mode);
}


float findMedian(int arr[], int &arrSize)
{
    bool isEven = false;    // if the number is even, take the average median
    int i = 0;              // iterators
    int j = 0;
    float median=0; 
        
    if (arrSize % 2 == 0) { isEven = true; }
    
    if (!isEven) {
        i = (arrSize / 2);
        median = arr[i];
    } else {
        i = (arrSize / 2);
        j = i + 1;
        median = ( float(arr[i])+float(arr[j]) )/2;
    }
    return(median);
}
    
    

void sortArray(int* &arr, int arrSize, bool &isSorted)  // linear sort
{
    int i=0;
    int j=0;
    int max=0;
    int min=0;
    
    for (i=0;i<arrSize;i++)
    {
        for (j=(i+1);j<arrSize;j++)
        {
            if (arr[j]<arr[i]) {
                max = arr[i];
                min = arr[j];
                arr[j] = max;
                arr[i] = min;
            }                
        }
    }
    isSorted = true;
}

void solution9_11(int arr[], int arrSize)
{

    int i = 0;
    int n = 0;
    int newSize = 0;
    // Take in the array from the previous solution, double its size.
    // Display original array
    cout << "Original array: \n";
    for (i=0;i<arrSize;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    newSize = arrSize * 2;
    n=0;
    for (i=arrSize; i<newSize; i++) {
        arr[i]=arr[n];
        n++;
    }
    cout << "New array:\n";
    for (i=0;i<newSize;i++) {
    cout << arr[i] << " ";
    }
    cout    << "\nArray is now doubled in size and repeated. This new array will not"
            << "\npass to the main function"
            << endl;
    localPause();
     
}

void solution9_2() 
{
    cout << "This solution is available as a separate file.\n";
    /*
    int *testscores;
    int i;
    int lowestScore=100;
    int total=0;
    int average=0;
    int numScores = 0;
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    cout    << "Dynamically generating some test scores." << endl
            << "How many test scores? " << endl;
    cin     >> numScores;
    cout    << "\nOutputting " << numScores << " scores." << endl;
    // Random test scores.
    for (i=0; i < numScores ;i++) {
        testscores[i]=(rand()%100);
    }
    // Display the test scores.
    cout << "\nThe test scores in the system are:";
    for (i=0;i<numScores;i++) {
        cout << testscores[i] << " ";
    }
    cout << endl;        
    // Decide which one is lowest
    for (i=0;i<numScores;i++) {
        if (testscores[i]<lowestScore) {
            lowestScore = testscores[i];
        }
    }
    cout << "\nThe lowest test score is " << lowestScore;
    // Total the score, average, drop lowest test score.
    total = 0;
    for (i=0;i<numScores;i++) {
        total = total + testscores[i];
    }
    average = (total - lowestScore) / (numScores - 1);
    cout << "\nThe final average is " << average << endl;
    */
}

void solution9_10(int arr[], int arrSize)
{
    int i = 0;
    int n = 0;
    int front = 0;
    int back = 0;
    int midpoint = arrSize/2;
    // Take in the array from the previous solution, reverse it.
    // Display original array
    cout << "Original array: \n";
    for (i=0;i<arrSize;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    n=arrSize-1;
    for (i=0; i<midpoint; i++) {
        front = arr[i];
        back = arr[n];
        arr[i] = back;
        arr[n] = front;
        n--;
    }
    cout << "New array:\n";
    for (i=0;i<arrSize;i++) {
    cout << arr[i] << " ";
    }
    cout    << "\nArray is now reversed."
            << endl;
    localPause();
}

void solution9_12(int arr[], int arrSize)
{
    int *newarr;
    int i = 0;
    int n = 0;
    // Take in the array from the previous solution, expand by one.
    // Display original array
    cout << "Original array: \n";
    for (i=0;i<arrSize;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    arrSize++;
    for (i=arrSize; i>0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0]=0;
    cout << "New array:\n";
    for (i=0;i<arrSize;i++) {
    cout << arr[i] << " ";
    }
    cout    << "\nArray is now reversed."
            << endl;
    localPause();
}