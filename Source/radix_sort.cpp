#include "header.h"

int chiso(long long x, long long n, long long& k)
{
    long long b = 0;
    for (long long i = 1; i <= n; i++)
    {
        b = x % 10;
        x /= 10;
    }
    k = x;
    return b;
}

void Radixsort( long long  *& a,   long long  n)
{
    vector<vector<int>> b(10);
    int c = n;
    int k = 1;
    while (c != 0)
    {
        c = 0;
        for (int i = 0; i < n; i++)
        {
            long long test;
            int digit = chiso(a[i], k, test);
            if (test != 0)
                c++;
            b[digit].push_back(a[i]);
        }
        k++;
        memset(a, 0, n);
        int d = 0;
        for (int i = 0; i < b.size(); i++)
        {
            for (int j = 0; j < b[i].size(); j++)
            {
                a[d] = b[i][j];
                d++;
            }
            b[i].clear();
        }
    }
}

int countCompare_chiso(long long x, long long n, long long& k, long long& c)
{
    long long b = 0;
    for (long long i = 1; ++c && i <= n; i++)
    {
        b = x % 10;
        x /= 10;
    }
    k = x;
    return b;
}

long long CountCompare_Radixsort(  long long * a,   long long  n)
{
    long long countCompare = 0;
    vector<vector<int>> b(10);
    long long c = n;
    int k = 1;
    while (++countCompare && c != 0)
    {
        c = 0;
        for (int i = 0; ++countCompare && i < n; i++)
        {
            long long test;
            int digit = countCompare_chiso(a[i], k, test, countCompare);
            if (++countCompare && test != 0)
                c++;
            b[digit].push_back(a[i]);
        }
        k++;
        memset(a, 0, n);
        int d = 0;
        for (int i = 0; ++countCompare && i < b.size(); i++)
        {
            for (int j = 0; ++countCompare && j < b[i].size(); j++)
            {
                a[d] = b[i][j];
                d++;
            }
            b[i].clear();
        }
    }
    return countCompare;
}
