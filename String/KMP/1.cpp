#include <bits/stdc++.h>
using namespace std;

void solve(string txt, string pat)
{
    // compute prefix function
    int n = txt.size();
    int m = pat.size();

    vector<int> prefix(n, 0);
    prefix[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int j = prefix[i - 1];

        while (j > 0 and pat[i] != pat[j])
        {
            j = prefix[j - 1];
        }

        if (pat[i] == pat[j])
            j++;
        prefix[i] = j;
    }

    int i = 0;
    int j = 0;
    // string matching
    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = prefix[j - 1];
            }
            else
            {
                i++;
            }
        }

        if (j == m)
        {
            cout << i - m << endl;
            break;
        }
    }
}

int main()
{
    string txt = "abcacb";
    string pat = "acb";
    solve(txt, pat);
    return 0;
}