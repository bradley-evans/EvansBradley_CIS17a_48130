#include <iostream>
#include <string>
using namespace std;

#include <boost/regex.hpp>
using namespace boost;
bool regexValidate (string expr, string teststring) 
{
    boost::regex ex(expr);
    cout << teststring;
    //if ( boost::regex_match (teststring,ex) ) {
    //    cout << "true";
    //    return true;
    //}
    //} else if (regex_match (teststring,regex("^\s*\d*d\d*\s*$"))) {
    //    cout << "true";
    //    return true;
    //}
    return false;
}

int main()
{
    string  diceexpr = "^\\s*\\d{1,}d\\d{1,}\\s*$";
    string  teststr = "10d10";
    string  teststr1 = "1d10";
    string  teststr2 = " 10d10 ";
    
    cout << teststr << " is ";
    if (regexValidate(diceexpr,teststr)) {
        cout << " valid!" << endl;
    } else {
        cout << " invalid!" << endl;
    }
    cout << teststr1 << " is ";
    if (regexValidate(diceexpr,teststr1)) {
        cout << " valid!" << endl;
    } else {
        cout << " invalid!" << endl;
    }
    cout << teststr2 << " is ";
    if (regexValidate(diceexpr,teststr2)) {
        cout << " valid!" << endl;
    } else {
        cout << " invalid!" << endl;
    }
    return 0;
}