#include "header.h"

void Quicksort(  long long *& a,  long long l,  long long r)
{
	 long long key = a[(l + r) / 2];
	 long long i = l;
	 long long j = r;
	if (l <= r)
	{
		while (i <= j)
		{
			while (a[j] > key)
				j--;
			while (a[i] < key)
				i++;
			if (i <= j)
			{
				 long long temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				i++;
				j--;
			}

		}
		if (l < j)
			Quicksort(a, l, j);
		if (r > i)
			Quicksort(a, i, r);
	}
}

long long CountConpare_Quicksort(  long long * a,  long long l,  long long r)
{
	 long long count1 = 0, count2 = 0;
	 long long key = a[(l + r) / 2];
	 long long i = l;
	 long long j = r;
	 long long countCompare = 0;
	if (++countCompare && l <= r)
	{
		while (++countCompare && i <= j)
		{
			while (++countCompare && a[j] > key)
				j--;
			while (++countCompare && a[i] < key)
				i++;
			if (++countCompare && i <= j)
			{
				 long long temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				i++;
				j--;
			}

		}
		if (++countCompare && l < j)
			count1 = CountConpare_Quicksort(a, l, j);
		if (++countCompare && r > i)
			count2= CountConpare_Quicksort(a, i, r);
	}
	return countCompare + count1 + count2;

}
