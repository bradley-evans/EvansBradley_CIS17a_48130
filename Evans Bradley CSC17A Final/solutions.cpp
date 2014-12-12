#include "solutions.h"

void driver1()  {
char n=5;
	char rndseq[]={16,34,57,79,121};
	int ntimes=100000;
	Prob1Random a(n,rndseq);
        unsigned seed=time(0);
        srand(seed);
	for(int i=1;i<=ntimes;i++)
	{       
		a.randFromSet(rand()%n);
	}
	int *x=a.getFreq();
	const char *y=a.getSet();
	for(int i=0;i<n;i++)
	{
		cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
	}
	cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;

}

void driver2() {
        
	int column;
        bool ascending=true;
        ifstream infile;
    
        cout<<"The start of Problem 2, the sorting problem"<<endl;
	Prob2Sort<char> rc;
        int k=0;
	infile.open("Problem2.txt",ios::in);
	char *ch2=new char[10*17];
	char *ch2p=ch2;
	while(infile.get(*ch2)) {
            k++;
            cout<<*ch2;
            ch2++;
        }
	infile.close();
	cout<<endl;
	cout<<"Which column would you like to sort by?"<<endl;     
	cin>>column;
	char *zc=rc.sortArray(ch2p,10,17,column,ascending);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<17;j++)
		{
			cout<<zc[i*17+j];
		}
	}
	delete []zc;
	cout<<endl;
}

void driver3() {
        cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    int array[5][6]={   100,101,102,103,104,105,
                        106,107,108,109,110,111,
                        112,113,114,115,116,117,
                        118,119,120,121,122,123,
                        124,125,126,127,128,129 };
    Prob3TableInherited<int> tab(array,rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
            for(int j=0;j<cols;j++)
            {
                    cout<<naugT[i*cols+j]<<" ";
            }
            cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
            for(int j=0;j<=cols;j++)
            {
                    cout<<augT[i*(cols+1)+j]<<" ";
            }
            cout<<endl;
    }
} 

void driver4() {
  
}

void driver5() {
   
}
void driver6() {
   
}