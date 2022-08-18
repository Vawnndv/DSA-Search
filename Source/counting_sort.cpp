#include "header.h"

void countSort( long long a[],  long long n){
    long long max = a[0];
    long long min = a[0];
   for ( long long i = 0; i < n; i++){
      if (max <= a[i])
      max = a[i];
      if (min >= a[i])
      min = a[i];
   }
    long long range = max - min + 1;
    long long *count = new  long long [range] {0};
    long long *output = new  long long [n];
   for ( long long i = 0; i < n; i++)
      count[a[i] - min]++;
   //tang dan
   for ( long long i = 1; i < range; i++)
      count[i] += count[i - 1];
   //giam dan
   //for ( long long i = range - 2; i >=0; i--)
   //   count[i] += count[i + 1];
   for ( long long i = n - 1; i >= 0; i--) {
      output[count[a[i] - min] - 1] = a[i];
      count[a[i] - min]--;
   }
   for ( long long i = 0; i < n; i++)
      a[i] = output[i];
}

void countSort_OperatorCouting( long long a[],  long long n, long long &count_compare){
   count_compare = 0;
    long long max = a[0];
    long long min = a[0];
   for ( long long i = 0; ++ count_compare && i < n; i++){
      if (++count_compare && max <= a[i])
         max = a[i];
      if (++count_compare && min >= a[i])
         min = a[i];
   }
    long long range = max - min + 1;
    long long *count = new  long long [range] {0};
    long long *output = new  long long [n];
   for ( long long i = 0; ++count_compare && i < n; i++)
      count[a[i] - min]++;
   //tang dan
   for ( long long i = 1; ++count_compare && i < range; i++)
      count[i] += count[i - 1];
   //giam dan
   //for ( long long i = range - 2; i >=0; i--)
   //   count[i] += count[i + 1];
   for ( long long i = n - 1; ++count_compare && i >= 0; i--) {
      output[count[a[i] - min] - 1] = a[i];
      count[a[i] - min]--;
   }
   for ( long long i = 0; ++count_compare && i < n; i++)
      a[i] = output[i];
}
