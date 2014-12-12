/* 
 * File:   Prob3Table.cpp
 * Author: Bradley Evans
 * 
 * Created on December 12, 2014, 1:45 PM
 */

#include "Prob3Table.h"

template<class T>
Prob3Table<T>::Prob3Table(int c[][6],int a,int b) {
    rows=a;
    cols=b;
    table=new int[a*b];
    table=c;
    
}
template<class T>
void Prob3Table<T>::calcTable() {
    
}
