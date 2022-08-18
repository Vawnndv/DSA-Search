#include "header.h"

void bubbleSort( long long  *& a,  long long  n)
{
	for ( long long  i = 0; i < n - 1; i++)
		for ( long long  j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				Swap(a[j], a[j - 1]);
}

long long comp_bubbleSort( long long *& a,  long long  n)
{
	long long count = 0;
	for ( long long  i = 0; ++count && i < n - 1; i++)
		for ( long long  j = n - 1; ++count && j > i; j--)
		{
			if (++count && a[j] < a[j - 1])
				Swap(a[j], a[j - 1]);
		}
	return count;
}
