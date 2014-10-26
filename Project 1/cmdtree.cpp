#include "cmdtree.h"
using namespace std;

void printLine(string filename, int line)
{
    char        descrip[11][500] = {0};
    char        *ch_arr = descrip[0];
    fstream     text;
    int         y = 0;
    
    cout << "\nfile: " << filename << " line: " << line << endl;
    
    text.open(filename,ios::in);
    if (!text.is_open()) {         
        cout << "\nCould not open " << filename << "." << endl;
    } else {
        while (!text.eof())
        {
            ch_arr = descrip[y];
            text.getline(ch_arr,500);
            y++;
        }                
    }
    text.close();
    ch_arr = descrip[line];
    cout    << " " << ch_arr << endl;
        
}
// SYNTAX cmd_[noun]_[verb] ()

// ask
void cmd_ask_name() {       // ask name
    Dice dice;
    int result;
    result = dice.roll(100);
    if ((suspect.silence - suspect.comply - suspect.exhaustion) > result) {
        cout << "\nThe suspect sits there quietly." << endl;
    } else if ((suspect.silence - suspect.comply - suspect.exhaustion) <= result) {
        result = dice.roll(100);
        if (result > (suspect.deception - suspect.exhaustion)) {
            cout << "He gives you his real name!" << endl;
        } else {
            cout << "He lies about his name." << endl;
        }
    }
    suspect.exhaustion++;                
}
        
// look
void cmd_look_suspect()     // look suspect
{
    int         statePosture;
    string      descfile;
    
    // Pull statePosture line from suspect_posture.txt.
    statePosture    = ((suspect.comply + suspect.silence) / 20);
    descfile        = "suspect_posture.txt";
    
    printLine(descfile,statePosture);
    
}


