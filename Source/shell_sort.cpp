#include "header.h"

void shellSort( long long  *& a,  long long  n)
{
    for ( long long  gap = n / 2; gap > 0; gap /= 2)
    {
        for ( long long  i = gap; i < n; i += 1)
        {
             long long  temp = a[i];
             long long  j;

            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }
}

long long comp_shellSort( long long  *& a,  long long  n)
{
     long long  count = 0;
    for ( long long  gap = n / 2; ++count && gap > 0; gap /= 2)
    {
        for ( long long  i = gap; ++count && i < n; i += 1)
        {
             long long  temp = a[i];
             long long  j;

            for (j = i; ++count && j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }
    return count;
}
