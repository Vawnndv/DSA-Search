#include "header.h"

void mergeSort( long long  a[],  long long  l,  long long  r)
{
	if(l<r)
	{
		 long long  m = l + (r-l) / 2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		 long long  i,j,k=l;
		 long long  n1= m-l+1;
		 long long  n2 = r - m;
		 long long  *L = new  long long [n1];
		 long long  *R= new  long long [n2];
		for(i = 0;i < n1; i++)
		{
			L[i] = a[l+i];
		}
		for(j = 0; j < n2; j++)
		{
			R[j] = a[m+j+1];
		}
		i=0; j=0;
		while(i<n1 && j<n2)
		{
			a[k++] = (L[i]<=R[j]) ? L[i++] : R[j++];
		}
		while(i<n1)
		{
			a[k++] = L[i++];
		}
		while(j<n2)
		{
			a[k++] = R[j++];
		}
	}
}

void countComparisons_MergeSort ( long long  &countcompare,  long long  a[],  long long  l,  long long  r)
{
		if(++countcompare && l<r)
	{
		 long long  m = l + (r-l) / 2;
		countComparisons_MergeSort(countcompare,a,l,m);
		countComparisons_MergeSort(countcompare,a,m+1,r);
		 long long  i,j,k=l;
		 long long  n1= m-l+1;
		 long long  n2 = r - m;
		 long long  *L = new  long long [n1];
		 long long  *R= new  long long [n2];
		for(i = 0;++countcompare && i < n1; i++)
		{
			L[i] = a[l+i];
		}
		for(j = 0;++countcompare && j < n2; j++)
		{
			R[j] = a[m+j+1];
		}
		i=0; j=0;
		while(++countcompare && ++countcompare && i<n1 && j<n2)
		{
			a[k++] = (++countcompare && L[i]<=R[j]) ? L[i++] : R[j++];
		}
		while(++countcompare && i<n1)
		{
			a[k++] = L[i++];
		}
		while(++countcompare && j<n2)
		{
			a[k++] = R[j++];
		}
	}
}
