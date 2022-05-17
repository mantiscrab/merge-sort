#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void mergesort(int* tab, int n);

int main()
{
    int ile;
    cout << "Podaj ile elementow w tablicy: "; cin >> ile;
    int* tablica=new int [ile];

    srand(time(NULL));
    for (int i=0;i<ile;i++)
    {
        tablica[i]=rand()%100+1;
    }

    mergesort(tablica, ile);

    delete [] tablica;

    return 0;
}

void mergesort(int* tab, int n)
{
    if (n>1)
    {
        int it1=n/2, it2=n-n/2;
        int *t1=tab, *t2=tab+it1;
        int *b=new int[n];
        if(it1>1)
        {
            mergesort(t1, it1);
        }
        if(it2>1)
        {
            mergesort(t2, it2);
        }

        int h=0;
        int k=0, kmax=it1-1;
        int l=0, lmax=it2-1;

        while (h<n)
        {
            if      (k>kmax)            {b[h]=t2[l]; h++; l++;}
            else if (l>lmax)            {b[h]=t1[k]; h++; k++;}
            else if (t1[k]<t2[l])       {b[h]=t1[k]; h++; k++;}
            else                        {b[h]=t2[l]; h++; l++;}
        }

        for(int i=0;i<n;i++)
        {
            tab[i]=b[i];
        }
        delete [] b;
    }
}





