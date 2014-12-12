/* 
 * File:   Prob2Sort.h
 * Author: Bradley Evans
 *
 * Created on December 12, 2014, 1:17 PM
 */

#ifndef PROB2SORT_H
#define	PROB2SORT_H

template<class T>
class Prob2Sort
{
	private:
		int *index;                                 //Index that is utilized in the sort
	public:
		Prob2Sort(){index=0;};                      //Constructor
		~Prob2Sort(){delete []index;};              //Destructor
		T * sortArray(const T*,int,bool);           //Sorts a single column array
		T * sortArray(T*,int,int,int,bool);         //Sorts a 2 dimensional array
};

template<class T>
T *Prob2Sort<T>::sortArray(T* a, int b, int c, int d, bool e)
{
    d--;
    int temp;
    bool p;
    index=new int[b];
    for(int i=0; i<b; i++)
    {
        index[i]=a[d+(17*i)];
    }
    /*
    for(int i=0; i<b; i++)
    {
        for(int j=0; j<c; j++)
        {
            temp=a[(b*17)+j];
            a[(b*17)]=a[(b*17)+(j+1)];
            a[(b*17)+(j+1)]=temp;
        }
    }
     */
    do{
        p=false;
        for(int i=0; i<b-1; i++)
        {
            if(index[i]<index[i+1])
            {
                p=true;
                temp=index[i];
                index[i]=index[i+1];
                index[i+1]=temp;
                for(int k=0; k<c-1; k++)
                {
                    temp=a[k+(17*i)];
                    a[k+(17*i)]=a[k+(17*(i+1))];
                    a[k+(17*(i+1))]=temp;
                }
            }
        }
    }while(p!=false);
    return a;
    
}
template<class T>
T *Prob2Sort<T>::sortArray(const T* a, int b, bool c)
{
    
}

#endif	/* PROB2SORT_H */

