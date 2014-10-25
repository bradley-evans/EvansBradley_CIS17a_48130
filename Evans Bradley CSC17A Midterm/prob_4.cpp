/*
 A company wants to transmit data over the telephone, but they are 
concerned that their phones may be tapped. All of their data is 
transmitted as four-digit integers. However, they utilize the digits 
0,1,2,3,4,5,6,7 only. They have asked you to write a program that 
will encrypt their data so that it may be transmitted more securely.
Your application should read a four-digit integer with the numbers 
0 to 7 entered by the user in an input dialog and encrypt it as 
follows: Replace each digit by (the sum of that digit plus 3) modulus 8. 
Then swap the first digit with the second, and swap the third digit 
with the fourth. Then print the encrypted integer. Write a separate 
application that inputs an encrypted four-digit integer and decrypts 
it to form the original number.
Note:  sometimes errors occur and the digits 8, and 9 might appear.  
Detect this condition and flag the error.  Can't read in numbers 
individually.  All the digits must be read with one cin statement.
 */

#include "prob_4.h"


void solution_4() {
    char **pt;
    char charstore;
    int rows = 0;
    int i = 0;
    int j = 0;
    bool isValid = false;
    int **pt_int;
    
    
    cout    << "Number of four digit integers you wish to encrypt:" << endl
            << "> ";
    cin     >> rows;
    pt = new char*[rows];
    for (i=0;i<rows;i++){
        pt[i] = new char[4];
    }
    clearbuffer();
    cout    << "ENTER THE INTEGERS FOR ENCRYPTION. ONLY FOUR DIGIT INTEGERS FROM 1-7 ARE ACCEPTED:" << endl;
    takeArray(pt,rows);
    pt_int = new int*[rows];
    for (i=0;i<rows;i++){
        pt_int[i] = new int[4];
    }
    for (i=0;i<rows;i++){
        for (j=0;j<4;j++) {
            charstore = pt[i][j];
            pt_int[i][j] = ((int)charstore - 48);
        }
    }
    for (i=0;i<rows;i++) {
        delete []pt[i];
    }
    delete []pt;
    encrypt(pt_int,rows);
    decrypt(pt_int,rows);
    
    
    //showArray(pt,rows);
    for (i=0;i<rows;i++) {
        delete []pt_int[i];
    }
    delete []pt_int;
}

void encrypt(int** &pt, int rows) {
    int i = 0;
    int j = 0;
    int num1 = 0;
    
    cout    << "PT: ";
    for (i=0;i<rows;i++) {
        for (j=0;j<4;j++) {
            cout << pt[i][j];
        }
        cout << " | ";
        for (j=0;j<4;j++) {
            pt[i][j] = (pt[i][j] + 3)%8;
        }
        num1 = pt[i][0];
        pt[i][0]= pt[i][1];
        pt[i][1]= num1;    
        num1 = pt[i][2];
        pt[i][2]= pt[i][3];
        pt[i][3]= num1;
    }
    cout    << endl;
    cout    << "CT: ";
    for (i=0;i<rows;i++) {
        for (j=0;j<4;j++) {
            cout << pt[i][j];
        }
        cout << " | ";
    }
    cout << endl;
}

void decrypt(int** &pt, int rows) {
    int i = 0;
    int j = 0;
    int num1 = 0;
    
    cout    << endl
            << "Decrypting:" << endl;
    
    cout    << "CT: ";
    for (i=0;i<rows;i++) {
        for (j=0;j<4;j++) {
            cout << pt[i][j];
        }
        cout << " | ";
        for (j=0;j<4;j++) {
            switch (pt[i][j]) {
                case 0: pt[i][j] = 5;break;
                case 1: pt[i][j] = 6;break;
                case 2: pt[i][j] = 7;break;
                case 3: pt[i][j] = 8;break;
                case 4: pt[i][j] = 1;break;
                case 5: pt[i][j] = 2;break;
                case 6: pt[i][j] = 3;break;
                case 7: pt[i][j] = 4;break;
                case 8: cout << "Error!"; return;
                case 9: cout << "Error!"; return;
            }
        }
        num1 = pt[i][0];
        pt[i][0]= pt[i][1];
        pt[i][1]= num1;    
        num1 = pt[i][2];
        pt[i][2]= pt[i][3];
        pt[i][3]= num1; 
    }
    cout << endl;
    cout << "PT: ";
    for (i=0;i<rows;i++) {
        for (j=0;j<4;j++) {
            cout << pt[i][j];
        }
        cout << " | ";
    }
    cout << endl;
}
// By "all the digits" I assume you mean "all the digits of a single integer," so here...
void takeArray(char** &pt, int rows) {
    int i = 0;
    int j = 0;
    int counter = 1;
    bool isValid;
    
    for (i=0;i<rows;i++) {
        do {
            isValid = true;
            cout << "INPUT INTEGER " << counter << ": ";
            cin.getline(pt[i],1000);
            j = cin.gcount();
            if (j > 5) {
                cout << "INVALID INPUT DETECTED! Please re-enter ";
                isValid = false;
            }
            for (j=0;j<5;j++) {
                if ( pt[i][j] == '8' || 
                    pt[i][j] == '9' || 
                    pt[i][j] == '0' ) {
                    cout << "INVALID INPUT DETECTED! Only use numbers 1-7! " << endl;
                    isValid = false;
                    j=5;
                }
            }
            for (j=0;j<4;j++) {
                if (!isdigit(pt[i][j])) { 
                    isValid = false;
                    cout << "INVALID INPUT DETECTED! Please re-enter ";
                    j=5;
                }
            }
        } while (!isValid);
        cout << "INTEGER " << counter << " VERIFIED AS " << pt[i] << endl;   
        counter++;
    }
}

