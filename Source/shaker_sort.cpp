#include "header.h"

void Swap(  long long & a,   long long & b)
{
	 long long temp = a;
	a = b;
	b = temp;
}

void Shakersort(  long long *& a,   long long  n)
{
    long long left = 0, right = n - 1;
    long long k = 0;
    while (left < right)
    {
        for (long long j = right; j > left; j--)
        {
            if (a[j] < a[j - 1])
            {
                Swap(a[j], a[j - 1]);
                k = j - 1;
            }
        }
        left = k;
        for (long long j = left; j < right; j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(a[j], a[j + 1]);
                k = j ;
            }
        }
        right = k;
    }
}

void CountConpare_Shakersort(  long long *& a,   long long  n,  long long  &countCompare)
{
	 long long left = 0, right = n - 1;
	 long long k = 0;
	countCompare = 0;
	while (++countCompare && left < right)
	{
		for ( long long j = right; ++countCompare && j > left; j--)
		{
			if (++countCompare && a[j] < a[j - 1])
			{
				Swap(a[j], a[j - 1]);
				k = j - 1;
			}
		}
		left = k;
		for ( long long j = left; ++countCompare && j < right; j++)
		{
			if (++countCompare && a[j] > a[j + 1])
			{
				Swap(a[j], a[j + 1]);
				k = j ;
			}
		}
		right = k;
	}
}
