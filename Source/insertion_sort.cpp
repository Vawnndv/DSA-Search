#include "header.h"

void Insertsort( long long *& a,  long long n)
{
    long long k = 1;
    while (k <= n)
    {
        long long i = k - 1;
        long long value = a[k];
        while (i > -1 && a[i] > value)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = value;
        k++;
    }
}

void CountCompare_Insertsort(  long long * a,   long long  n,  long long  &countCompare)
{
	countCompare = 0;
    long long k = 1;
    while (++countCompare && k < n)
    {
        long long i = k - 1;
        long long value = a[k];
        while (++countCompare && i > -1 && ++countCompare && a[i] > value)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = value;
        k++;
    }
}
