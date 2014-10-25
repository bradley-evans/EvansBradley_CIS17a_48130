/**
 5)  a) Using a byte variable, what is the largest factorial that can 
be calculated.  A factorial is simply 

n! = 1 * 2 * 3 * 4 ... * (n-2) * (n-1) * n

For instance, 1! = 1,  2! = 2,  3! = 6,  4! = 24,  5! = 120 etc....

b)  What would be the largest factorial using short, int, long, float, 
double, etc...  Use all the primitive data types that you are familiar 
with.

Note:  I want you to have fun investigating this and the program you 
turn in should just print "cout" the final results.  You don't know 
how to capture errors yet so run each till it overflows then back off by 1.
Don't need the program that tests for this.
 */

#include "prob_5.h"

void solution_5() {
    int product = 0;
    
    cout    << "Using a byte variable, what is the largest factorial that can" 
            << "be calculated?" << endl;
    
    cout    << "Max value of a byte holding an unsigned integer: 255" << endl
            << "Max value of a byte holding a signed integer:    127" << endl
            << "                    1! = 0 = 1" << endl
            << "                2! = 2 * 1 = 2" << endl;
    product = (3 * 2 * 1);
    cout    << "            3! = 3 * 2 * 1 = " << product << endl;
    product = (4 * 3 * 2 * 1); 
    cout    << "        4! = 4 * 3 * 2 * 1 = " << product << endl;
    product = (5 * 4 * 3 * 2 * 1);
    cout    << "     5! = 5* 4 * 3 * 2 * 1 = " << product << endl;
    product = (6 * 5 * 4 * 3 * 2 * 1);
    cout    << "6! = 6 * 5 * 4 * 3 * 2 * 1 = " << product << endl;
    cout    << "∴ the largest factorial that " << endl
            << "can be contained in a byte is" << endl
            << "5!.                          " << endl
            << "Other factorials are:        " << endl;

    cout    << "Other data types have other maximum values: " << endl
            << "Short Int (signed):    " << numeric_limits<signed short int>::max() << "     holds 5!: " << factorial(5) << endl
            << "Short Int (unsigned):  " << numeric_limits<unsigned short int>::max() << "     holds 8!: " << factorial(8) << endl
            << "Int (signed):          " << numeric_limits<signed int>::max() << "     holds 12!: " << factorial(12) << endl
            << "Long Int (signed):     " << numeric_limits<signed long int>::max() << "     holds 12!: " << factorial(12) << endl
            << "Long Int (unsigned):   " << numeric_limits<signed long int>::max() << "     holds 12!: " << factorial(12) << endl
            << "Float:                 " << numeric_limits<float>::max() << "     holds 34! " << factorial(34) << endl
            << "Double:                " << numeric_limits<double>::max() << "     holds 170! " << factorial(170) << endl;
    
}
// Forgive me for using this double. I eventually have to 
// compare it against the max value of another double.
double factorial(int n) {
    double product = 0;
    product = n;
    n--;
    for (n;n>0;n--) { product = (product * n); }
    return (product);
}

void viewFacs() {
    for (int i=6;i<170;i++) { 
        cout << i << "! = " << factorial(i) << endl;  
        if ((i%15)==0) {
            localPause();
        }
    }
}