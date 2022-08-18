#include "header.h"
#include "selection_sort.cpp"
#include "counting_sort.cpp"
#include "insertion_sort.cpp"
#include "quick_sort.cpp"
#include "radix_sort.cpp"
#include "shaker_sort.cpp"
#include "merge_sort.cpp"
#include "bubble_sort.cpp"
#include "shell_sort.cpp"
#include "heap_sort.cpp"
#include "flash_sort.cpp"

// Check string is a number
bool isNumber(char s[]){
   for ( long long  i = 0; i < strlen(s); i++)
      if (!(s[i] >= '0' && s[i] <= '9'))
         return false;
   return true;
}
// Copy Array
 long long  *copyArray( long long  a[],  long long  n){
    long long  *temp = new  long long  [n];
   for ( long long  i = 0; i < n; i++)
      temp[i] = a[i];
   return temp;
}

// read vector in file
 long long  * readFile(char *filename,  long long  &n){
    long long  * temp;
   fstream f (filename);
   f >> n;
   temp = new  long long  [n];
   for ( long long  i = 0; i < n; i++){
       long long  number;
      f >> number;
      temp[i] = number;
   }
   f.close();
   return temp;
}

//Create an Array
 long long  *createArray( long long  n, char *typeArray){
    long long *temp = new   long long   [n];
   if (strcmp(typeArray,"-rand") == 0)
      GenerateRandomData(temp,n);
   if (strcmp(typeArray,"-nsorted") == 0)
      GenerateNearlySortedData(temp,n);
   if (strcmp(typeArray,"-sorted") == 0)
      GenerateSortedData(temp,n);
   if (strcmp(typeArray,"-rev") == 0)
      GenerateReverseData(temp,n);
   return temp;
}

// Store Array to file
void ArrayToFile( long long  a[],  long long  n, string fileName){
   fstream f;
   f.open(fileName, ios::out);
   f << n << endl;
   for ( long long  i = 0; i < n; i++)
      f << a[i] << " ";
   f.close();
}

// Run Sort
void Run_Sort(char *sort,  long long  a[],  long long  n, long long  &count_compare, clock_t &time){
   if (strcmp(sort, "selection-sort") == 0){
      // Tạo mảng b có giá trị như mảng a
       long long  *b = copyArray(a,n);
      // Đếm số time
      clock_t start = clock();
      selectionSort(a,n);
      clock_t end = clock();
      time = double(end - start);
      // Đếm số phép so sánh
      selectionSort_OperatorCouting(b,n,count_compare);
   }
   if (strcmp(sort, "insertion-sort") == 0){
      // Tạo mảng b có giá trị như mảng a
       long long  *b = copyArray(a,n);
      // Đếm số time
      clock_t start = clock();
      Insertsort(a,n);
      clock_t end = clock();
      time = double(end - start);
      // Đếm số phép so sánh
      CountCompare_Insertsort(b,n,count_compare);
   }
   if (strcmp(sort, "bubble-sort") == 0){
      // Tạo mảng b có giá trị như mảng a
       long long  *b = copyArray(a,n);
      // Đếm số time
      clock_t start = clock();
      bubbleSort(a,n);
      clock_t end = clock();
      time = double(end - start);
      // Đếm số phép so sánh
      count_compare = comp_bubbleSort(b,n);
   }
   if (strcmp(sort, "shaker-sort") == 0){
      // Tạo mảng b có giá trị như mảng a
       long long  *b = copyArray(a,n);
      // Đếm số time
      clock_t start = clock();
      Shakersort(a,n);
      clock_t end = clock();
      time = double(end - start);
      // Đếm số phép so sánh
      CountConpare_Shakersort(b,n,count_compare);
   }
   if (strcmp(sort, "shell-sort") == 0){
      // Tạo mảng b có giá trị như mảng a
       long long  *b = copyArray(a,n);
      // Đếm số time
      clock_t start = clock();
      shellSort(a,n);
      clock_t end = clock();
      time = double(end - start);
      // Đếm số phép so sánh
      count_compare = comp_shellSort(b,n);
   }
   if (strcmp(sort, "heap-sort") == 0){
      // Tạo mảng b có giá trị như mảng a
       long long  *b = copyArray(a,n);
      // Đếm số time
      clock_t start = clock();
      heapSort(a,n);
      clock_t end = clock();
      time = double(end - start);
      // Đếm số phép so sánh
      count_compare = comp_heapSort(b,n);
   }
   if (strcmp(sort, "merge-sort") == 0){
      // Tạo mảng b có giá trị như mảng a
       long long  *b = copyArray(a,n);
      // Đếm số time
      clock_t start = clock();
      mergeSort(a,0,n-1);
      clock_t end = clock();
      time = double(end - start);
      // Đếm số phép so sánh
      count_compare = 0;
      countComparisons_MergeSort(count_compare,b,0,n-1);
   }
   if (strcmp(sort, "quick-sort") == 0){
      // Tạo mảng b có giá trị như mảng a
       long long  *b = copyArray(a,n);
      clock_t start = clock();
      Quicksort(a,0,n-1);
      clock_t end = clock();
      time = double(end - start);
      // Đếm số phép so sánh
      count_compare = CountConpare_Quicksort(b,0,n-1);
   }
   if (strcmp(sort, "counting-sort") == 0){
      // Tạo mảng b có giá trị như mảng a
       long long  *b = copyArray(a,n);
      // Đếm số time
      clock_t start = clock();
      countSort(a,n);
      clock_t end = clock();
      time = double(end - start);
      //hàm sort đếm ss
      countSort_OperatorCouting(b,n,count_compare);
   }
   if (strcmp(sort, "radix-sort") == 0){
      // Tạo mảng b có giá trị như mảng a
       long long  *b = copyArray(a,n);
      // Đếm số time
      clock_t start = clock();
      Radixsort(a,n);
      clock_t end = clock();
      time = double(end - start);
      // Đếm số phép so sánh
      count_compare = CountCompare_Radixsort(b,n);
   }
   if (strcmp(sort, "flash-sort") == 0){
      // Tạo mảng b có giá trị như mảng a
       long long  *b = copyArray(a,n);
      // Đếm số time
      clock_t start = clock();
      flashSort(a,n);
      clock_t end = clock();
      time = double(end - start);
      // Đếm số phép so sánh
      count_compare = comp_flashSort(b,n);
   }
}
// Output screen
void outputScreen( long long  cmd, char *argv[],  long long  inputSize, long long  count_compare, clock_t time, long long count_compare_ran, 
long long  count_compare_near, long long  count_compare_sorted, long long  count_compare_rev, clock_t time_ran, 
clock_t time_near, clock_t time_sorted, clock_t time_rev, clock_t time_1, clock_t time_2, long long  count_compare_1, long long  count_compare_2){
   if (cmd == 1 || cmd == 2 || cmd == 3)
      cout << "ALGORITHM MODE" << endl;
   else
      cout << "COMPARE MODE" << endl;
   switch (cmd){
   case 1:
      cout << "Algorithm: " << argv[2] << endl;
      cout << "Input file: " << argv[3] << endl;
      cout << "Input size: " << inputSize << endl;
      cout << "----------------------------------------" << endl;
      if (strcmp(argv[4],"-both") == 0){
         cout << "Running time (if required): " << time << endl;
         cout << "Comparisions (if required): " << count_compare << endl;
      };
      if (strcmp(argv[4],"-comp")== 0){
         cout << "Running time (if required): " << endl;
         cout << "Comparisions (if required): " << count_compare << endl;
      };
      if (strcmp(argv[4],"-time")== 0){
         cout << "Running time (if required): " << time << endl;
         cout << "Comparisions (if required): " << endl;
      };
      break;
   case 2:
      cout << "Algorithm: " << argv[2] << endl;
      cout << "Input size: " << inputSize << endl;
      cout << "Input Order: " << argv[4] << endl;
      cout << "----------------------------------------" << endl;
      if (strcmp(argv[5],"-both")== 0){
         cout << "Running time (if required): " << time << endl;
         cout << "Comparisions (if required): " << count_compare << endl;
      };
      if (strcmp(argv[5],"-comp")== 0){
         cout << "Running time (if required): " << endl;
         cout << "Comparisions (if required): " << count_compare << endl;
      };
      if (strcmp(argv[5],"-time")== 0){
         cout << "Running time (if required): " << time << endl;
         cout << "Comparisions (if required): " << endl;
      };
      break;
   case 3:
      cout << "Algorithm: " << argv[2] << endl;
      cout << "Input size: " << inputSize << endl << endl;
      cout << "Input Order: Randomize" << endl;
      cout << "----------------------------------------" << endl;
      if (strcmp(argv[4],"-both")== 0){
         cout << "Running time (if required): " << time_ran << endl;
         cout << "Comparisions (if required): " << count_compare_ran << endl;
      };
      if (strcmp(argv[4],"-comp")== 0){
         cout << "Running time (if required): " << endl;
         cout << "Comparisions (if required): " << count_compare_ran << endl;
      };
      if (strcmp(argv[4],"-time")== 0){
         cout << "Running time (if required): " << time_ran << endl;
         cout << "Comparisions (if required): " << endl << endl;
      };
      cout << endl;
      cout << "Input Order: Nearly Sorted" << endl;
      cout << "----------------------------------------" << endl;
      if (strcmp(argv[4],"-both")== 0){
         cout << "Running time (if required): " << time_near << endl;
         cout << "Comparisions (if required): " << count_compare_near << endl;
      };
      if (strcmp(argv[4],"-comp")== 0){
         cout << "Running time (if required): " << endl;
         cout << "Comparisions (if required): " << count_compare_near << endl;
      };
      if (strcmp(argv[4],"-time")== 0){
         cout << "Running time (if required): " << time_near << endl;
         cout << "Comparisions (if required): " << endl << endl;
      };
      cout << endl;
      cout << "Input Order: Sorted" << endl;
      cout << "----------------------------------------" << endl;
      if (strcmp(argv[4],"-both")== 0){
         cout << "Running time (if required): " << time_sorted << endl;
         cout << "Comparisions (if required): " << count_compare_sorted << endl;
      };
      if (strcmp(argv[4],"-comp")== 0){
         cout << "Running time (if required): " << endl;
         cout << "Comparisions (if required): " << count_compare_sorted << endl;
      };
      if (strcmp(argv[4],"-time")== 0){
         cout << "Running time (if required): " << time_sorted << endl;
         cout << "Comparisions (if required): " << endl << endl;
      };
      cout << endl;
      cout << "Input Order: Reversed" << endl;
      cout << "----------------------------------------" << endl;
      if (strcmp(argv[4],"-both")== 0){
         cout << "Running time (if required): " << time_rev << endl;
         cout << "Comparisions (if required): " << count_compare_rev << endl;
      };
      if (strcmp(argv[4],"-comp")== 0){
         cout << "Running time (if required): " << endl;
         cout << "Comparisions (if required): " << count_compare_rev << endl;
      };
      if (strcmp(argv[4],"-time")== 0){
         cout << "Running time (if required): " << time_rev << endl;
         cout << "Comparisions (if required): " << endl << endl;
      };
      break;
   case 4:
      cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
      cout << "Input file: " << argv[4] << endl;
      cout << "Input size: " << inputSize << endl;
      cout << "----------------------------------------" << endl;
      cout << "Running time : " << time_1 << " | "  << time_2 << endl;
      cout << "Comparisions : " << count_compare_1 << " | " << count_compare_2 << endl;
      break;
   case 5:
      cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
      cout << "Input size: " << inputSize << endl;
      cout << "Input file: " << argv[5] << endl;
      cout << "----------------------------------------" << endl;
      cout << "Running time : " << time_1 << " | "  << time_2 << endl;
      cout << "Comparisions : " << count_compare_1 << " | " << count_compare_2 << endl;
      break;
   default:
      break;
   }
}

// Command 1
void command_1( long long  argc, char *argv[]){
   long long  *a, n;
   long long  count_compare = 0;
   clock_t time;
   a = readFile(argv[3],n);
   Run_Sort(argv[2],a,n,count_compare,time);
   outputScreen(1,argv,n,count_compare,time,0,0,0,0,0,0,0,0,0,0,0,0);
   ArrayToFile(a,n,"output.txt");
}

//command 2
void command_2( long long  argc, char *argv[]){
    long long  n = stoi(argv[3]);
    long long  *a = createArray(n,argv[4]);
   ArrayToFile(a,n,"input.txt");
   long long  count_compare = 0;
   clock_t time;
   Run_Sort(argv[2],a,n,count_compare,time);
   outputScreen(2,argv,n,count_compare,time,0,0,0,0,0,0,0,0,0,0,0,0);
   ArrayToFile(a,n,"output.txt");
}

// Command 3
void command_3( long long  argc, char *argv[]){
    long long  n = stoi(argv[3]);
    long long  *a_ran = new  long long  [n], *a_near = new  long long  [n], *a_sorted = new  long long  [n], *a_rev = new  long long  [n];
   GenerateRandomData(a_ran,n);
   ArrayToFile(a_ran,n,"input_1.txt");
   GenerateNearlySortedData(a_near,n);
   ArrayToFile(a_near,n,"input_2.txt");
   GenerateSortedData(a_sorted,n);
   ArrayToFile(a_sorted,n,"input_3.txt");
   GenerateReverseData(a_rev,n);
   ArrayToFile(a_rev,n,"input_4.txt");
   long long  count_compare_ran = 0, count_compare_near = 0, count_compare_sorted = 0, count_compare_rev = 0;
   clock_t time_ran, time_near, time_sorted, time_rev;
   Run_Sort(argv[2],a_ran,n,count_compare_ran,time_ran);
   Run_Sort(argv[2],a_near,n,count_compare_near,time_near);
   Run_Sort(argv[2],a_sorted,n,count_compare_sorted,time_sorted);
   Run_Sort(argv[2],a_rev,n,count_compare_rev,time_rev);
   outputScreen(3,argv,n,0,0,count_compare_ran,count_compare_near,count_compare_sorted,count_compare_rev,time_ran,time_near,time_sorted,time_rev,0,0,0,0);
}

// Command 4
void command_4( long long  argc, char *argv[]){
    long long  n;
   long long  count_compare_1 = 0, count_compare_2 = 0;
   clock_t time_1, time_2;
    long long  *a = readFile(argv[4],n);
    long long  *b = copyArray(a,n);
   Run_Sort(argv[2],a,n,count_compare_1,time_1);
   Run_Sort(argv[3],b,n,count_compare_2,time_2);
   outputScreen(4,argv,n,0,0,0,0,0,0,0,0,0,0,time_1,time_2,count_compare_1,count_compare_2);
}

// Command 5
void command_5( long long  argc, char *argv[]){
    long long  n = stoi(argv[4]);
    long long  *a = createArray(n,argv[5]);
    long long  *b = copyArray(a,n);
   ArrayToFile(b,n,"input.txt");
   long long  count_compare_1 = 0, count_compare_2 = 0;
   clock_t time_1, time_2;
   Run_Sort(argv[2],a,n,count_compare_1,time_1);
   Run_Sort(argv[3],b,n,count_compare_2,time_2);
   outputScreen(5,argv,n,0,0,0,0,0,0,0,0,0,0,time_1,time_2,count_compare_1,count_compare_2);
}