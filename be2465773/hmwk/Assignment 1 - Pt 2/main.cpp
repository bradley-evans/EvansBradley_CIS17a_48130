#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string> 
#include <time.h>
using namespace std;

int main ()
{
    int numScores = 0;
    int *arr;
    int i;
    int lowestScore=100;
    int total=0;
    int average=0;
    
    cout    << "Dynamically generating some test scores.\n"
            << "How many test scores? ";
    cin     >> numScores;
    cout    << endl;
    // Random test scores.
    srand(time(NULL));
    for (i=0;i<numScores;i++) {
        arr[i]=(rand()%100);
    }
    // Display the test scores.
    cout << "\nThe test scores in the system are:";
    for (i=0;i<numScores;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;        
    // Decide which one is lowest
    for (i=0;i<numScores;i++) {
        if (arr[i]<lowestScore) {
            lowestScore = arr[i];
        }
    }
    cout << "\nThe lowest test score is " << lowestScore;
    // Total the score, average, drop lowest test score.
    total = 0;
    for (i=0;i<numScores;i++) {
        total = total + arr[i];
    }
    average = (total - lowestScore) / (numScores - 1);
    cout << "\nThe final average is " << average << endl;
    
}