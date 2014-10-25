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


struct statsResult  ///< Struct required by problem description.
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
} ;

statsResult *avgMedMode(int *,int); 

void solution_3() {
    int *intarray;
    int size = 0;
    float mean = 0;
    float median = 0;
    int *modeArr;
    int i=0;
    
    takeIntArray(intarray, size);
    mean = findMean(intarray,size);
    median = findMedian(intarray,size);
    modeArr = new int[size];
    for (i=0;i<size;i++) { modeArr[i]=intarray[i]; }
    sortArray(modeArr,size);
    findMode(modeArr,size);
    
    
    delete []intarray;
    delete []modeArr;
}


void takeIntArray(int* &intarray, int &size) { ///< Take an array as a c-string and store it as an array of integers in structure.
    char cs_intarr[100];
    char *ptrintarr = cs_intarr;
    char *cptr;
    int i = 0;
    int intcount = 0;

    clearbuffer();
    cout    << "Please enter your array. " << endl
            << "> ";
    cin.getline(ptrintarr,100);
    // Count up the integers by counting up spaces
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


void findMode (int *arr, int size) {
    
    int     i,j,k,m;                    ///< Iterators
    int     count;                      ///< Number of occurances of a particular integer
    int     max = 0;
    int     no_mode = 0;                ///< Tests for the absence of a mode.
    int     numModes = 0;
    int     currnum;
    int     modearr[size];
    
    for (i=0;i<size;i++) { modearr[i]=0; }
    for(k=0;k<size;k++) {                         
        count=0;
        currnum = arr[k];                         
        for(i=k; i<size; i++) {                   
            if(currnum==arr[i])
                count++;                          
        } 
        modearr[k]=count;                        
        if (count>=2) {                          
            no_mode++;
        }
    }
    if (no_mode==0) {
        modearr[0] = -1;     // Placeholder value for an array with no mode.
        return;
    }
    for(j=0;j<size;j++) {   
	if(modearr[j]>max) { max=modearr[j]; }
        
        for(m=0; m<size; m++) {
            if(max==modearr[m]) { numModes++; }
        }
        cout<<"This data set has " << numModes << " mode(s)" <<endl;//Prints out how many modes there are
        for(m=0; m<size; m++) {
            if(max==modearr[m]) {
                cout<< "The value " << arr[m] << " appeared " << modearr[m] << " times in the data set\n" << endl;
            }
        }
        return;
    }
}


void sortArray (int *arr, int arrSize) {
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
