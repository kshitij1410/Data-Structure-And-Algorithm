#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given a string and an integer k, find the number of substrings in which all the different characters occur exactly k times.

Examples:

Input : s = "aabbcc"
        k = 2
Output : 6
The substrings are aa, bb, cc,
aabb, bbcc and aabbcc.

Input : s = "aabccc"
        k = 2
Output : 3
There are three substrings aa,
cc and cc

*/

/* logic: iterate by two for loop and check whether all distinct elemennt are eqaul to k then inncrement ans  */

/* tc- O(26*n*n)*/

/* it can be optimized further*/

int substrings(string s, int k)
{
    int n = s.size();
    unordered_map<char, int> mp;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            mp[s[j]] += 1;
            int flag = 0;

            // check all mp[s[j]] is equal to k or 0 then result++
            for (auto ele : mp)
            {
                if (ele.second != k)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                ans++;
            }
        }
        mp.clear();
    }

    return ans;
}

int main()
{
    string s = "aabbcc";
    int k = 2;
    cout << substrings(s, k) << endl;

    s = "aabcbc";
    k = 2;
    cout << substrings(s, k) << endl;
}