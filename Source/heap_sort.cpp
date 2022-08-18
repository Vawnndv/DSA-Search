#include "header.h"

void heapify( long long  *& a,  long long  n,  long long  i)
{
     long long  largest = i;
     long long  l = 2 * i + 1;
     long long  r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) 
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort( long long *& a,  long long  n)
{
    for ( long long  i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i); 

    for ( long long  i = n - 1; i > 0; i--) 
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void comp_heapify( long long *& a,  long long  n,  long long  i, long long temp)
{
     long long  largest = i;
     long long  l = 2 * i + 1;
     long long  r = 2 * i + 2;

    if (++temp && l < n && a[l] > a[largest])
        largest = l;

    if (++temp && r < n && a[r] > a[largest])
        largest = r;

    if (++temp && largest != i)
    {
        swap(a[i], a[largest]);
        comp_heapify(a, n, largest, temp);
    }
}

long long comp_heapSort( long long *& a,  long long  n)
{
    long long count = 0, temp = 0;
    for ( long long  i = n / 2 - 1; ++count && i >= 0; i--)
    {
        temp = 0;
        comp_heapify(a, n, i, temp);
        count += temp;
    }

    for ( long long  i = n - 1; ++count && i > 0; i--)
    {
        temp = 0;
        swap(a[0], a[i]);
        comp_heapify(a, i, 0 , temp);
        count += temp;
    }
    return count;
}
