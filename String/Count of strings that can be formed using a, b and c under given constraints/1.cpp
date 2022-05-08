#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given a length n, count the number of strings of length n that can be made using ‘a’, ‘b’ and ‘c’ with at-most one ‘b’ and two ‘c’s allowed.
Examples :


Input : n = 3
Output : 19
Below strings follow given constraints:
aaa aab aac aba abc aca acb acc baa
bac bca bcc caa cab cac cba cbc cca ccb

Input  : n = 4
Output : 39

*/

/* O(N) due to factorial function  */

int countStr(int n)
{
    int ans = 0;
    if(n>=1)
    {
      // case 1: all a
    ans += 1;
    // case 2: (1b, all a)
    ans += n;
    // case 2:  (1c,all a)
    ans += n;

    // case 3: (2c,all a)
    ans += (((n) * (n - 1)) / 2);

    // case 4: (1b,1c,all a)
    ans += (n * (n - 1));

    // case 5: (1b,2c,all a)
    ans += ((n * (n - 1) * (n - 2)) / 2);
    }

    return ans;
    
}

int main()
{
    int n = 3; // Total number of characters
    cout << countStr(n);
    return 0;
}