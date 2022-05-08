#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given two strings, string1 and string2, the task is to find the smallest
substring in string1 containing all characters of string2 efficiently.

Input: string = “this is a test string”, pattern = “tist”
Output: Minimum window is “t stri”
Explanation: “t stri” contains all the characters of pattern.

Input: string = “geeksforgeeks”, pattern = “ork”
Output: Minimum window is “ksfor”

*/

/* O(N) Sliding Window  */

string Minimum_Window(string s, string t)
{
    int mp[256]={0};
    // memset(mp, 0, sizeof(mp));
    int startidx = 0;

    string res = "";
    int minLen = INT_MAX;
    int count = 0;

    for (int i = 0; i < t.size(); i++)
    {
        if (mp[t[i]] == 0)
            count++;
        mp[t[i]] += 1;
    }

    int i = 0;
    int j = 0;

    while (j < s.size())
    {
        mp[s[j]]--;

        if (mp[s[j]] == 0)
            count--;

        // we find a solution
        if (count == 0)
        {
            while (count == 0)
            {
                if (minLen > j - i + 1)
                {
                    minLen = min(minLen,j - i + 1);
                    startidx = i;
                }

                mp[s[i]]++;

                if(mp[s[i]]>0)
                count++;

                i++;
            }

        }

        j++;
    }

    if(minLen!=INT_MAX)
    {
         res=s.substr(startidx,minLen);
         return res;
    }
    else{
        return "-1";
    }
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "-->Smallest window that contain all character : " << endl;
    cout << Minimum_Window(s, t);
}