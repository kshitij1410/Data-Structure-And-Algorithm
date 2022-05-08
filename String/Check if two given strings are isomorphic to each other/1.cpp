#include <bits/stdc++.h>
using namespace std;

/*
Q1
Two strings str1 and str2 are called isomorphic if there is a one-to-one
 mapping possible for every character of str1 to every character of str2.
 And all occurrences of every character in ‘str1’ map to the same character in ‘str2’.

Input:  str1 = "aab", str2 = "xxy"
Output: True
'a' is mapped to 'x' and 'b' is mapped to 'y'.

Input:  str1 = "aab", str2 = "xyz"
Output: False
One occurrence of 'a' in str1 has 'x' in str2 and
other occurrence of 'a' has 'y'.

*/

bool areIsomorphic(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();

    if (n1 != n2)
        return false;

    unordered_map<char, char> mp;
    int flag = 0;

    for (int i = 0; i < n1; i++)
    {
        if (mp.find(s1[i]) == mp.end())
        {
            mp[s1[i]] = s2[i];
        }
        else
        {
            char mpchar = mp[s1[i]];
            if (mpchar != s2[i])
            {
                flag = 1;
                break;
            }
        }
    }
     mp.clear();

    int flag1=0;
    for (int i = 0; i < n1; i++)
    {
        if (mp.find(s2[i]) == mp.end())
        {
            mp[s2[i]] = s1[i];
        }
        else
        {
            char mpchar = mp[s2[i]];
            if (mpchar != s1[i])
            {
                flag1 = 1;
                break;
            }
        }
    }



    if (flag ==1 or flag1==1)
        return false;
    return true;
}

int main()
{
    cout << areIsomorphic("pijthbsfy", "fvladzpbf") << endl;
    cout << areIsomorphic("aab", "xyz") << endl;
    return 0;
}
