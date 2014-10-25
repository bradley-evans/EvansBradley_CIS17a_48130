/**
Write a function using the following structure and prototype.

struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

statsResult *avgMedMode(int *,int); 

The function takes in an integer array and the size of the array.
Then returns a pointer to a structure containing the average, median
and mode.  You will then write a printStat() function that will print
the results contained in the stats structure.  I will input a small 
array to test this out so ask for how many inputs to fill the array, 
then the values to place into the array.  Make sure you delete the 
dynamic array creation for the mode when you exit the problem.
 */

#include "prob_3.h"
using namespace std;

struct StatsResult  {       ///< Struct required by problem description.
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes 
} result_;

void solution_3() {

    int size=0;
    float mean = 0;
    float median = 0;
    int *intarray;      // this is raw input, later sorted
    int *listmodes;     // this is the processed list of only modes
    int i=0;
    int numModes=0;
    int maxoccurs=0;
    
    takeIntArray(intarray, size);
    mean = findMean(intarray,size);
    median = findMedian(intarray,size);    
    sortArray(intarray,size);
    findMode(intarray,size,listmodes,maxoccurs,numModes);
    /*
    cout << "Array sorted:    | ";
    for (i=0;i<size;i++) { cout << intarray[i] << " | "; }
    cout << endl;
    cout << "Mode array: ";
    for (i=0;i<numModes;i++) { cout << listmodes[i] << " occurs " << maxoccurs << " | "; }
    cout << endl;
    */
    //avgmedmode(listmodes,numModes,mean,median,maxoccurs); // Not exactly as described in the problem description, but there you go.
    avgmedmode_ (listmodes,numModes,mean,median,maxoccurs); // Workaround.
    
    delete []intarray;
    delete []listmodes;
}

/* This function didn't work, and I could see no obvious reason at all why, so I did a workaround.
 * Left here for you to see what I might have done wrong. 
 * 
StatsResult avgmedmode(int *listmodes, int numModes, float mean, float median, int maxoccurs) {
    StatsResult result;
    int i=0;
  
    result.avg = mean;
    result.maxFreq = numModes;
    result.median = median;
    for (i=0;i<numModes;i++) {
        result.mode[i] = listmodes[i];
    }
    result.nModes = numModes;
    result.maxFreq = maxoccurs;
    
    return (result);
}
*/

void displayResult() {
    int i = 0;
    cout    << "RESULTS ===========" << endl
            << "MEAN:            " << result_.avg << endl
            << "NUMBER OF MODES: " << result_.maxFreq << endl
            << "MODES:           ";
            for (i=0;i<result_.maxFreq;i++) {
                cout << result_.mode[i] << " " << endl;
            }
    cout    << "MEDIAN:          " << result_.median << endl
            << "MAX FREQUENCY:   " << result_.maxFreq << endl;
            
}

void takeIntArray(int* &intarray, int &intcount) { ///< Take an array as a c-string and store it as an array of integers in structure.
    char cs_intarr[90];
    char *ptrintarr = cs_intarr;
    char *cptr;
    int i = 0;
    int size  = 0;
    
    clearbuffer();
    cout    << "Please enter your array. " << endl
            << "> ";
    cin.getline(ptrintarr,90,'\n');
    size = cin.gcount();
    
    for (i=0;i<size;i++) { if (ptrintarr[i]==' ') {intcount++;} }
    intcount++;
    intarray = new int[intcount];
   
    intarray[0] = strtol(cs_intarr,&cptr,10);
    for (i=1;i<intcount;i++) {
        intarray[i] = strtol(cptr,&cptr,10);
    }
    cout << "Array in memory: | ";
    for (i=0;i<intcount;i++) { cout << intarray[i] << " | "; }
    cout << endl;
    
}

float findMedian (int *arr, int arrSize) {
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

float findMean(int *arr, int arrSize) {
    int i=0;
    int total = 0;
    float mean = 0;
    
    for (i=0;i<arrSize;i++) {
        total = ( total + arr[i] );
    }
    mean = (float(total) / float(arrSize));
    return (mean);
}

void findMode (int *arr, int size, int* &listmodes, int &currMax,int &numModes) {
    int numUnique = 1;
    int **mode;
    int i = 0;
    int j = 0;
    
    // *arr is a sorted array
    // How many unique integers do I have?
    for (i=1;i<size;i++) {
        if (arr[i] != arr[i-1]) {
            numUnique++;
        }
    }
    mode = new int*[numUnique];
    for (i=0;i<numUnique;i++) {
        mode[i] = new int[2];
        mode[i][0] = 0;
        mode[i][1] = 0;
    }
    mode[0][0]=arr[0];
    j = 0;
    // Count up the frequencies of each number and store.
    for (i=0;i<size;i++) {
        if (mode[0][j]==arr[i]) {   mode[1][j]++;
        }
        if (mode[0][j]!=arr[i]) {   j++;
                                    mode[1][j]++;
                                    mode[0][j]=arr[i];
        }
    }
    // find max mode
    for (i=0;i<numUnique;i++) {
        if (mode[1][i] > currMax) { currMax = mode[1][i];}
    }
    // find num of max mode occurances
    for (i=0;i<numUnique;i++) {
        if (mode[1][i] == currMax) { numModes++; }
    }
    j = 0;
    listmodes = new int[numModes];
    for (i=0;i<numUnique;i++) {
        if (mode[1][i]== currMax) {
            listmodes[j] = mode[0][i];
            j++;
        }
    }
    for (i=0;i<numUnique;i++) {
        delete []mode[i];
    }
    delete []mode;
    
}

void sortArray (int* &arr, int arrSize) {
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
}

/* This function didn't work either and I could see no obvious reason why. */
void avgmedmode_(int *listmodes, int numModes, float mean, float median, int maxoccurs) {    
    int i=0;   
    StatsResult result_;
 
    result_.avg = mean;      
    cout << "Mean            : " << result_.avg << endl;
    result_.median = median;
    cout << "Median          : " << result_.median << endl;
    cout << "Modes           : "; 
    result_.mode = new int[numModes];
    for (i=0;i<numModes;i++) {
        result_.mode[i]=listmodes[i];
        cout << result_.mode[i];
    }
    cout << endl;
    result_.nModes = numModes;
    cout << "Number of Modes : " << result_.nModes << endl;
    //result_.maxFreq = maxoccurs;
    //cout << "Frequency       : " << result_.maxFreq << endl;
    delete []result_.mode;
    
}