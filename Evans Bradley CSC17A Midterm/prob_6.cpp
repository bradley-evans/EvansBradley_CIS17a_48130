#include "prob_6.h"

void solution_6() {
    cout    << "2.125_10    base 2  -> 10.001" << endl
            << "            base 8  ->  2.02 " << endl
            << "            base 16 ->  2.2  " << endl
            << " In float representation:     " << endl
            << " [01000100|00000000|00000000|00000010]" << endl
            << " In 8-digit hex: 44000002" << endl;
    
    cout    << "-2.125_10 would be represented as:   " << endl
            << " [11000100|00000000|00000000|00000010]" << endl
            << " In 8-digit hex: C4000002" << endl; 
    
    cout    << "0.06640625  base 2  -> 0.00010001" << endl
            << "            base 8  -> 0.042 " << endl
            << "            base 16 -> 0.11 "  << endl
            << " In float representation:   " << endl
            << " [01000100|00000000|00000000|10000011]" << endl
            << " In 8-digit hex: 440000F3" << endl
            << "From hex to decimal:" << endl
            << "46666601 -> 1.099999904632568" << endl
            << "46666602 -> 2.199999809265136" << endl
            << "B9999AFE -> -4.43734 x 10e-32" << endl;
            
    
}
