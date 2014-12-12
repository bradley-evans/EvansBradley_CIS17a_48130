/* 
 * File:   Prob3Table.h
 * Author: Bradley Evans
 *
 * Created on December 12, 2014, 1:45 PM
 */

#ifndef PROB3TABLE_H
#define	PROB3TABLE_H

template<class T>
class Prob3Table {
protected:
    int     rows;                   //Number of rows in the table
    int     cols;                   //Number of cols in the table
    T       *rowSum;                //RowSum array
    T       *colSum;                //ColSum array
    T       *table;                 //Table array
    T       grandTotal;             //Grand total
    void    calcTable(void);        //Calculate all the sums
public:
    Prob3Table(int[][6],int,int);               //Constructor then Destructor
    ~Prob3Table() {
        delete[] table;
        delete[] rowSum;
        delete[] colSum;
    };
    const T *getTable(void) { return table; };
    const T *getRowSum(void) {return rowSum; };
    const T *getColSum(void) {return colSum; };
    T getGrandTotal(void) {return grandTotal; };
};

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
	protected:
		T *augTable;                                        //Augmented Table with sums
	public:
		Prob3TableInherited(int [][6],int,int);             //Constructor
		~Prob3TableInherited(){delete [] augTable;};        //Destructor
		const T *getAugTable(void){return augTable;}; 
};
template <class T>
Prob3TableInherited<T>::Prob3TableInherited(int a[][6], int b, int c):Prob3Table<T>(a,b,c) {
    augTable=new int[(a+1)*(b+5)];    
}

#endif	/* PROB3TABLE_H */

