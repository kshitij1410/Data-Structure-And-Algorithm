#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given a text and a wildcard pattern, implement wildcard pattern matching algorithm that
finds if wildcard pattern is matched with text. The matching should cover the entire text
(not partial text).
The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

Text = "baaabab",
Pattern = “*****ba*****ab", output : true
Pattern = "baaa?ab", output : true
Pattern = "ba*a?", output : true
Pattern = "a*ab", output : false


*/

bool isMatch(string txt, string pat, int j, int i)
{
    // base case
    if (i == 0 and j > 0)
        return false;
    if (i == 0 and j == 0)
        return true;
    if (j == 0 and i > 0)
    {
        int flag = 0;
        for (int ii = 0; ii < i; ii++)
        {
            if (pat[ii] != '*')
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
            return false;
        return true;
    }

    if (txt[j - 1] == pat[i - 1] or pat[i - 1] == '?')
        return isMatch(txt, pat, j - 1, i - 1);
    else if (pat[i - 1] == '*')
    {
        return isMatch(txt, pat, j, i - 1) || isMatch(txt, pat, j - 1, i);
    }
    else
        return false;
}

bool isMatchTD(string txt, string pat, int j, int i, vector<vector<int>> &dp)
{
    // base case
    if (i == 0 and j > 0)
        return false;
    if (i == 0 and j == 0)
        return true;
    if (j == 0 and i > 0)
    {
        int flag = 0;
        for (int ii = 0; ii < i; ii++)
        {
            if (pat[ii] != '*')
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
            return false;
        return true;
    }

    if (dp[j][i] != -1)
        return dp[j][i];

    if (txt[j - 1] == pat[i - 1] or pat[i - 1] == '?')
        return dp[j][i] = isMatchTD(txt, pat, j - 1, i - 1, dp);
    else if (pat[i - 1] == '*')
    {
        return dp[j][i] = isMatchTD(txt, pat, j, i - 1, dp) || isMatchTD(txt, pat, j - 1, i, dp);
    }
    else
        return dp[j][i] = false;
}

bool isMatchBU(string txt, string pat)
{

    int n = txt.size();
    int m = pat.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // base case
    for (int j = 1; j <= m; j++)
        dp[0][j] = false;

    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int ii = 0; ii < i; ii++)
        {
            if (pat[ii] != '*')
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
            dp[i][0] = false;
        else
            dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (txt[i - 1] == pat[j - 1] or pat[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (pat[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}


bool isMatchopt(string txt, string pat)
{

    int m = txt.size();
    int n = pat.size();
    vector<bool> prev(m + 1, false), curr(m + 1, false);

    // base case
    for (int j = 1; j <= n; j++)
        prev[j] = false;

    prev[0] = true;

    for (int i = 1; i <= n; i++)
    {

        int flag = 0;
        for (int ii = 0; ii < i; ii++)
        {
            if (pat[ii] != '*')
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
            curr[0] = false;
        else
            curr[0] = true;

        for (int j = 1; j <= m; j++)
        {
            if (txt[i - 1] == pat[j - 1] or pat[j - 1] == '?')
                curr[j] = prev[j - 1];
            else if (pat[j - 1] == '*')
            {
                curr[j] = curr[j - 1] || prev[j];
            }
            else
            {
                curr[j] = false;
            }
        }

        prev=curr;
    }
    return prev[n];
}


int main()
{
    string str = "baaabab";
    string pattern = "baaa?ab";
    int n = str.size();
    int m = pattern.size();

    if (isMatch(str, pattern, n, m))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    if (isMatchTD(str, pattern, n, m, dp))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    if (isMatchBU(str, pattern))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

        if (isMatchopt(str, pattern))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}