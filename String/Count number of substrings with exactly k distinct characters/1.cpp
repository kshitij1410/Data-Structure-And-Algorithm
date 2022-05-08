#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that has exactly k distinct characters.
Examples:


Input: abc, k = 2
Output: 2
Possible substrings are {"ab", "bc"}

Input: aba, k = 2
Output: 3
Possible substrings are {"ab", "ba", "aba"}

Input: aa, k = 1
Output: 3
Possible substrings are {"a", "a", "aa"}

*/























/* logic: iterate by two for loop and set will help to check k distinct character  */

int countkDist(string str, int k)
{
    unordered_set<char> s;
    int n = str.size();
    vector<string> v;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            s.insert(str[j]);

            if (s.size() > k)
                break;

            if (s.size() == k)
            {
                v.push_back(str.substr(i, j + 1));
            }
        }
        s.clear();
    }

    // for (auto ele : v)
    // {
    //     cout << ele << " ";
    // }
    // cout << endl;
    int ans = v.size();
    v.clear();
    return ans;
}

int main()
{
    string str = "aa";
    int k = 1;
    cout << countkDist(str, k) << endl;
    return 0;
}