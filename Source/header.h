#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <ctime>
#include <string.h>
#include <cstring>
#include <vector>
#include <sstream>
#include "DataGenerator.cpp"
using namespace std;
// Selection Sort
void selectionSort( long long a[],  long long n);
void selectionSort_OperatorCouting( long long a[],  long long n, long long &count_compare);
// Counting Sort
void countSort( long long a[],  long long n);
void countSort_OperatorCouting( long long a[],  long long n, long long &count_compare);
// Insertion Sort
void Insertsort( long long *& a,  long long n);
void CountCompare_Insertsort(  long long * a,   long long  n,  long long  &countCompare);
// Quick Sort
void Quicksort(  long long *& a,  long long l,  long long r);
long long CountConpare_Quicksort(  long long * a,  long long l,  long long r);
// Radix Sort
int chiso(long long x, long long n, long long& k); 
void Radixsort( long long  *& a,   long long  n);
int countCompare_chiso(long long x, long long n, long long& k, long long& c);
long long CountCompare_Radixsort(  long long * a,   long long  n);
// Shaker Sort
void Swap(  long long & a,   long long & b);
void Shakersort(  long long *& a,   long long  n);
void CountConpare_Shakersort(  long long *& a,   long long  n,  long long  &countCompare);
// Merge Sort
void mergeSort( long long  a[],  long long  l,  long long  r);
void countComparisons_MergeSort ( long long  &countcompare,  long long  a[],  long long  l,  long long  r);
// Bubble Sort
void bubbleSort( long long  *& a,  long long  n);
long long comp_bubbleSort( long long *& a,  long long  n);
// Shell Sort
void shellSort( long long  *& a,  long long  n);
long long comp_shellSort( long long  *& a,  long long  n);
// Heap Sort
void heapify( long long  *& a,  long long  n,  long long  i);
void heapSort( long long *& a,  long long  n);
void comp_heapify( long long *& a,  long long  n,  long long  i, long long temp);
long long comp_heapSort( long long *& a,  long long  n);
// Insertion Sort
void insertSort( long long * a,  long long  n);
long long comp_insertSort( long long * a,  long long  n);
// Flash Sort
long long  getClass( long long  x,  long long  maxValue,   long long  minValue,  long long  m);
void flashSort( long long  *& a,  long long  n);
long long comp_flashSort( long long  *& a,  long long  n);

// Check string is a number
bool isNumber(char s[]);
// Copy Array
long long  *copyArray( long long  a[],  long long  n);
// read vector in file
 long long  * readFile(char *filename,  long long  &n);
//Create an Array
 long long  *createArray( long long  n, char *typeArray);
// Store Array to file
void ArrayToFile( long long  a[],  long long  n, string fileName);
// Run Sort
void Run_Sort(char *sort,  long long  a[],  long long  n, long long  &count_compare, clock_t &time);
// Output screen
void outputScreen( long long  cmd, char *argv[],  long long  inputSize, long long  count_compare, clock_t time, long long count_compare_ran, 
long long  count_compare_near, long long  count_compare_sorted, long long  count_compare_rev, clock_t time_ran, 
clock_t time_near, clock_t time_sorted, clock_t time_rev, clock_t time_1, clock_t time_2, long long  count_compare_1, long long  count_compare_2);
// Command 1
void command_1( long long  argc, char *argv[]);
//command 2
void command_2( long long  argc, char *argv[]);
// Command 3
void command_3( long long  argc, char *argv[]);
// Command 4
void command_4( long long  argc, char *argv[]);
// Command 5
void command_5( long long  argc, char *argv[]);

#endif