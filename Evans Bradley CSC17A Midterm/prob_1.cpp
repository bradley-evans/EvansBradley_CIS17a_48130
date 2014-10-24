/**PROBLEM ONE:
 * Develop an application using structures for a customer
 * that will determine if he/she has exceeded his/her checking 
 * account balance. For each customer, the following 
 * facts are available:
 * a. Account number (Five digits only, i.e. test for this)
 * b. Balance at the beginning of the month 
 * c. Total of all checks written by this customer this month 
 *    Loop until customer is through entering checks.
 * d. Total of all deposits credited to this customer's account this 
 *    month.  Loop until customer is through entering deposits.
 * 
 * The program should input each of these facts from input dialogs as 
 * integers, store in a structure, calculate the new balance, 
 * display the new balance and debit the account $12 if overdrawn. 
 * Also, if overdrawn, tell the customer the additional $12 fee 
 * has been accessed and what the balance would be with this fee included.
 */

#include "prob_1.h"

struct Account {
    char    acctnumber[5] = "";     ///< User's account number. Must only be five digits!
    float   balance = 1000;         ///< User's bank balance at the beginning of the month.
    float   totalWithdraw = 0;      ///< Total value of all (withdrawl) checks input by user this month.
    float   totalDeposit = 0;       ///< Total value of all the user's deposits for the month
} customer;

void solution_1() {
    char control;           ///< Character control variable (runs menus, etc)
    bool isExit = false;    ///< Asks if user wants to exit this part of the program.
    
    cout    << "***********" << endl
            << " PROBLEM 1 " << endl
            << "***********" << endl
            << endl;
    
    // ** Display statistics ** //
    cout.setf( ios::fixed );
    cout.precision(2);
    do {
        cout    << "CURRENT BALANCE: $" << customer.balance << endl
                << "Please select from the following options." << endl
                << "[1] - Change / view account number" << endl
                << "[2] - Enter a new check (withdrawls)" << endl
                << "[3] - Make a deposit" << endl
                << "[4] - View balance" << endl
                << "[5] - Return to main menu" << endl
                << "> ";
        cin     >> control;
        switch (control) {
            case '1': getAcctNum(); break;
            case '2': makeWithdraw(); break;
            case '3': makeDeposit(); break;
            case '4': viewBal(); break;
            case '5': isExit=true; break;
        }
        cout    << endl;
    } while (!isExit);
    
}

void getAcctNum () {
    char    inAcct[5];              ///< Account number, as input by the user.
    char    *chptr = inAcct;        ///< Character pointer to array inAcct
    char    control = '0';          ///< Control character for menu options.
    int     chcount = 0;            ///< Number of characters from last input.
    bool    isValid = true;         ///< Is the account number valid?
    int     i = 0;                  ///< Iterator
    
    cout    << "Your account number is CHANGE listed as: " << customer.acctnumber << endl
            << "Would you like to change it? [Y/N]" << endl
            << "> ";
    cin     >> control;
    if (control == 'y' || control == 'Y') {
         do {
            cout    << "Please input an account number: " << endl
                    << "> ";
            cin.getline(chptr,256);          
            //cin.ignore(256,'\n');
            chcount = cin.gcount();              
            cout    << endl;
            isValid = true;
            if (chcount != 6) {
                    cout << "Please enter five digits exactly." << endl;
                    isValid = false;
                }
            chcount--;
            for (i=0;i<chcount;i++) {
                if (!isdigit(chptr[i])) { 
                    cout << chptr[i];
                    cout << "Please enter only numbers." << endl;
                    isValid = false; 
                }
            }
            if (isValid) {   
                for (i=0;i<chcount;i++) {
                    customer.acctnumber[i]=chptr[i];   
                }
                customer.acctnumber[i] = '\0';
                cout << "You have entered account number: " << customer.acctnumber << endl;  
            }  
        } while (!isValid);
    } else if (control == 'n' || control == 'N') { 
        cout << endl; 
    } else { 
        cin.ignore(256,'\n');
        cout << endl; 
    }
}

void makeWithdraw() {
    bool    isDone = false;     // Was the last check entered?
    float   checkAmt = 0;       // How much are we subtracting?
    int     counter = 0;        // How many checks have we entered?
    char    control = '0';      // Control character for menu options.
   
    do {
        cout    << "Please enter the value of check " << counter << endl
                << "> $";
        cin     >> checkAmt;
        cout    << endl;
        customer.balance = (customer.balance - checkAmt);
        if (customer.balance < 0) {
            cout    << "WARNING! Account " << customer.acctnumber << " has been overdrawn!" << endl
                    << "A $12 overdraw fee has been assessed to this account." << endl;
            customer.balance = customer.balance - 12;
        }
        cout    << "Your current balance is now $" << customer.balance << endl
                << "Would you like to enter another check? [Y/N]" << endl
                << "> ";
        cin     >> control;
        cout    << endl;
        if (control == 'n' || control == 'N') { isDone = true; }
        counter++;               
    } while (!isDone);
}

void makeDeposit() {
    bool    isDone = false;     // Was the last check entered?
    float   checkAmt = 0;       // How much are we subtracting?
    int     counter = 0;        // How many checks have we entered?
    char    control = '0';      // Control character for menu options.
   
    do {
        cout    << "Please enter the value of deposit " << counter << endl
                << "> $";
        cin     >> checkAmt;
        customer.balance = (customer.balance + checkAmt);
        cout    << "Your current balance is now $" << customer.balance << endl
                << "Would you like to enter another deposit? [Y/N]" << endl
                << "> ";
        cin     >> control;
        cout    << endl;
        cout    << endl;
        if (control == 'y' || control == 'Y') { isDone = true; }
        counter++;               
    } while (!isDone);
}

void viewBal() {
    char    control;
    float   newBal;
    
    cout    << "Your current balance is now $" << customer.balance << endl
            << "Would you like to correct your starting balance? [Y/N]" << endl
            << "> ";
            cin     >> control;
        cout    << endl;
            if (control == 'y' || control == 'Y') { 
                cout    << "Please enter your new starting balance." << endl
                        << "> $";
                cin     >> newBal;
                cout    << endl;
                if (newBal > 0) { 
                    customer.balance = newBal;
                    cout << "The new starting balance recorded is: $" << customer.balance << endl;
                } else {
                    cout << "You've entered a balance less than $0.00. The balance was not recorded." << endl;
                }
            }       
}