#include "header.h"

void insertSort( long long * a,  long long  n)
{
	long long k = 1;
	while (k < n)
	{
		long long i = k - 1;
		while (i > -1 && a[i] > a[k])
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = a[k];
		k++;
	}
}

long long comp_insertSort( long long * a,  long long  n)
{
	long long k = 1;
	long long countCompare = 0;
	while (++countCompare && k < n)
	{
		long long i = k - 1;
		while (++countCompare && i > -1 && ++countCompare && a[i] > a[k])
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = a[k];
		k++;
	}
	return countCompare;
}

 long long  getClass( long long  x,  long long  maxValue,   long long  minValue,  long long  m) 
{
    long long res = (long long)(m - 1) * (x - minValue) / (maxValue - minValue);
    return res;
}

void flashSort( long long  *& a,  long long  n)
{
     long long  m = ( long long )(0.43 * n);

     long long  maxValue, minValue;
    maxValue = minValue = a[0];

    for ( long long  i = 1; i < n; i++)
    {
        maxValue = max(maxValue, a[i]);
        minValue = min(minValue, a[i]);
    }

     long long * L = new  long long [m];
    memset(L, 0, m * sizeof( long long ));

    for ( long long  i = 0; i < n; i++)
    {
         long long  k = getClass(a[i], maxValue, minValue, m);
        L[k]++;
    }

    for ( long long  i = 1; i < m; i++)
    {
        L[i] += L[i - 1];
    }
    for ( long long  i = 0; i < n; i++)
    {
         long long  k = getClass(a[i], maxValue, minValue, m);

        if (i > L[k] - 1) continue;

        while (i < L[k]) 
        {
            swap(a[i], a[L[k] - 1]);
            L[k]--;
            k = getClass(a[i], maxValue, minValue, m);
        }
    }

    for ( long long  i = 0; i < m - 1; i++)
    {
        insertSort(a + L[i], L[i + 1] - L[i]);
    }
    delete[] L;
}

long long comp_flashSort( long long  *& a,  long long  n)
{
    long long count = 0;
     long long  m = ( long long )(0.43 * n);

     long long  maxValue, minValue;
    maxValue = minValue = a[0];

    for ( long long  i = 1; ++count && i < n; i++)
    {
        maxValue = max(maxValue, a[i]);
        minValue = min(minValue, a[i]);
        count += 2;
    }

     long long * L = new  long long [m];
    memset(L, 0, m * sizeof( long long ));

    for ( long long  i = 0; ++count && i < n; i++)
    {
         long long  k = getClass(a[i], maxValue, minValue, m);
        L[k]++;
    }

    for ( long long  i = 1; ++count && i < m; i++)
    {
        L[i] += L[i - 1];
    }
    for ( long long  i = 0; ++count && i < n; i++)
    {
         long long  k = getClass(a[i], maxValue, minValue, m);

        if (++count && i > L[k] - 1)
            continue;

        while (++count && i < L[k])
        {
            swap(a[i], a[L[k] - 1]);
            L[k]--;
            k = getClass(a[i], maxValue, minValue, m);
        }
    }

    for ( long long  i = 0; ++count && i < m - 1; i++)
    {
        count += comp_insertSort(a + L[i], L[i + 1] - L[i]);
    }
    delete[] L;
    return count;
}
