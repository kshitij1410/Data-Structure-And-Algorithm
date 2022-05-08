#include <bits/stdc++.h>
using namespace std;

/*
Q1
We need to make a string of size n. Each character of the string is either ‘R’, ‘B’ or ‘G’. In the final string there needs to be at least r number of ‘R’, at least b 
number of ‘B’ and at least g number of ‘G’ (such that r + g + b <= n). We need to find number of such strings possible.
Examples:


Input : n = 4, r = 1,
        b = 1, g = 1.
Output: 36
No. of 'R' >= 1,
No. of ‘G’ >= 1,
No. of ‘B’ >= 1 and
(No. of ‘R’) + (No. of ‘B’) + (No. of ‘G’) = n
then following cases are possible:
1. RBGR and its 12 permutation
2. RBGB and its 12 permutation
3. RBGG and its 12 permutation
Hence answer is 36.

*/

/* O(N*N)  */

int possibleStrings(int n, int r, int b, int g)
{
    int *fact = new int[n + 1];

    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i;

    int ans = 0;
    int left = n - (r + g + b);
    int sum=0;

    /*
    n=7 r=1,g=1,b=1
    left=4

    iteration1  iteration 2
    gggg  || rggg
    gggb  || rbgg
    ggbb  || rbbg
    gbbb  || rbbb  and soon....
    bbbb  ||



   Basically we fixed r then take a possible combination of g,b


    */

    for (int rval = 0; rval <= left; rval++) /*place r from no r present to all r present in the remaining position */
    {
        for (int bval = 0; bval <= left - rval; bval++)
        {
            int gval = left - rval - bval;

            sum += (fact[n] / (fact[rval + r] * fact[bval + b] * fact[gval + g]));
        }
    }

    return sum;
}

int main()
{
    int n = 4, r = 2;
    int b = 0, g = 1;
    cout << possibleStrings(n, r, b, g);
    return 0;
}