#include "header.h"

void selectionSort( long long a[],  long long n){
   for ( long long i = 0; i < n-1; i++){
       long long min = i;
      for ( long long j = i+1; j < n; j++)
         if (a[j] < a[min])
            min = j;
       long long temp = a[min];
      a[min] = a[i];
      a[i] = temp;
   }
}

void selectionSort_OperatorCouting( long long a[],  long long n, long long &count_compare){
   count_compare = 0;
   for ( long long i = 0; ++count_compare && i < n-1; i++){
       long long min = i; 
      for ( long long j = i+1; ++count_compare && j < n; j++)
         if (++count_compare && a[j] < a[min])
            min = j;
       long long temp = a[min];
      a[min] = a[i];
      a[i] = temp;
   }
}