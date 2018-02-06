#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

void zapolnenie(int *a,int *br, int n)
{  for(int i=0; i<n; i++)
    {   a[i]=rand()%11;
        br[i]=a[i]; }
}

void out(int *a, int n)
{   for(int i=0; i<15; i++)
    cout << "matrix[" << i << "]= " << a[i] <<endl;
    for(int i=n-15; i<n; i++)
    cout << "matrix[" << i << "]= " << a[i] <<endl;
}

void selection(int *a, int n)
{   clock_t start = clock();
    int i, j, mx, nmx;
    for(i = 0; i < n-1; i++)
    {   mx=a[i];
        nmx=i;
        for(j = i+1; j < n; j++)
        {   if (a[j]<mx)
            {   mx=a[j];
                nmx=j; } }
        a[nmx]=a[i];
        a[i]=mx; }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
}

void radix(int *ar, int *br, int *cr, int sizeC, int sizeAB)
{   clock_t start = clock();
    int i,k,n;
    k = sizeC;
    n = sizeAB;
    for (i = 0; i <= k; i++)
        cr[i]=0;
    for (i = 0; i < n; i++)
        cr[ar[i]]+=1;
    for (i = 1; i < k+1; i++)
        cr[i]+=cr[i-1];
    for (i = n-1; i >= 0; i--)
    {
        br[cr[ar[i]]-1]=ar[i];
        cr[ar[i]]-=1;  }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
}


int main()
{   int *a, *br, *cr, n, sizeC=10;
    setlocale (LC_ALL, "RUS");
    cout << "Введите количество элементов:";
    cin >> n;

    a=new int[n];
    br=new int[n];
    cr=new int[10];

    zapolnenie(a,br,n);
    out(a,n);
 selection(a,n);
    cout <<endl;
    out(a,n);
   cout <<endl;
   out(br,n);
    radix(a,br,cr,sizeC,n);
    cout <<endl;
    out(br,n);
    getch();
    return 0;
}

