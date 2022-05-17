#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int ile;
clock_t start,stop;
double czas;

void sortowanie_babelkowe(int *tab, int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(tab[j]>tab[j+1])
            {
                int bufor=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=bufor;
            }
        }
    }
}

void quicksort(int *tab, int lewy, int prawy)
{
    int v=tab[lewy];
    int p=lewy;
    int q=prawy;
    /*
    cout << "Pivot v: " << v << endl << endl;

        do
        {
            cout << "Pivot v: " << v << endl;
            cout << "Wskaznik p: " << p << endl;
            cout << "Wzkaznik q: " << q << endl;
            for (int i=0; i<=prawy ; i++)
            {
                cout << tab[i] << " ";
            }
            cout << endl;
            while(tab[q]>v) q--;
            while(tab[p]<v) p++;
            if(p<q)
            {
                int bufor=tab[p];
                tab[p]=tab[q];
                tab[q]=bufor;
            }
        }while(p<q);
    */

    while(p<=q)
    {
        while(tab[q]>v) q--;
        while(tab[p]<v) p++;
        /*
        cout << "Wskaznik p: " << p << endl;
        cout << "Wzkaznik q: " << q << endl;

        for (int i=lewy; i<=prawy ; i++)
            cout << tab[i] << " ";
        cout << endl;
        */
        if(p<=q)
        {
            int bufor=tab[p];
            tab[p]=tab[q];
            tab[q]=bufor;
            q--;
            p++;
        }
        /*
        for (int i=lewy; i<=prawy ; i++)
            cout << tab[i] << " ";
        cout << endl;
        */
        //getchar();
    }
    if(q>lewy) quicksort(tab, lewy, q);
    if(p<prawy) quicksort(tab, p, prawy);

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

int main()
{
    cout << "Porownanie czasow sortowania v.1" << endl;

    cout<<"Ile losowych liczb w tablicy: ";
    cin>>ile;

    //dynamiczna alokacja tablicy
    int *tablica;
    tablica=new int [ile];

    int *tablica2;
    tablica2=new int [ile];

    int *tablica3;
    tablica3=new int [ile];

    //inicjowanie generatora
    srand(time(NULL));

    //wczytywanie losowych liczb do tablicy
    for(int i=0; i<ile; i++)
    {
        tablica[i] = rand()%100000+1;
        tablica2[i]=tablica[i];
        tablica3[i]=tablica[i];
    }

/*
    cout<<"Przed posortowaniem: "<<endl;
    for(int i=0; i<ile; i++)
    {
       cout<<tablica3[i]<<" ";
    }
    cout << endl;
*/
/*
    cout<<"Sortuje teraz babelkowo. Prosze czekac!"<<endl;
    start = clock();
    sortowanie_babelkowe(tablica,ile);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas sortowania babelkowego: "<<czas<<" s"<<endl;
*/
    cout<<endl<<"Sortuje teraz algorytmem quicksort. Prosze czekac!"<<endl;
    start = clock();
    quicksort(tablica2, 0, ile-1);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas sortowania quicksort: "<<czas<<" s"<<endl;

    cout<<endl<<"Sortuje teraz algorytmem mergesort. Prosze czekac!"<<endl;
    start = clock();
    mergesort(tablica3, ile);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas sortowania mergesort: "<<czas<<" s"<<endl;

/*
    cout<<"Po posortowaniu: "<<endl;
    for(int i=0; i<ile; i++)
    {
        cout<<tablica3[i]<<" ";
    }
*/
    delete [] tablica;
    delete [] tablica2;
    delete [] tablica3;

    return 0;
}
