#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given two strings str1 and str2 and below operations that can be performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace


Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.
*/

// time complexity O(3^M)  Recursion

int editDist(string str1, string str2, int i, int j)
{

    // base case
    if (j < 0 and i >= 0)
        return i + 1;
    if (i < 0 and j >= 0)
        return j + 1;
    if (i < 0 and j < 0)
        return 0;

    if (str1[i] == str2[j])
        return 0 + editDist(str1, str2, i - 1, j - 1);
    else
    {

        // insert
        int x = 1 + editDist(str1, str2, i, j - 1);

        // delete
        int y = 1 + editDist(str1, str2, i - 1, j);

        // replace
        int z = 1 + editDist(str1, str2, i - 1, j - 1);

        return min(x, min(y, z));
    }
}

// time complexity
// DP Approach (Memoization)
// TOP DOWN DP
// O(N*M) and space O(N*M) + O(N+M) AUXILIARY SPACE

int editDist1(string str1, string str2, int i, int j, vector<vector<int>> &dp)
{

    // base case

    if (j < 0 and i >= 0)
        return i + 1;
    if (i < 0 and j >= 0)
        return j + 1;
    if (i < 0 and j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str1[i] == str2[j])
        return dp[i][j] = 0 + editDist1(str1, str2, i - 1, j - 1, dp);
    else
    {

        // insert
        int x = 1 + editDist1(str1, str2, i, j - 1, dp);

        // delete
        int y = 1 + editDist1(str1, str2, i - 1, j, dp);

        // replace
        int z = 1 + editDist1(str1, str2, i - 1, j - 1, dp);

        return dp[i][j] = min(x, min(y, z));
    }
}

// TRY TO REMOVE AUXILIARY space then we use tabulation method
// BOTTOM UP APPROACH
// Time -O(N*M) ,SPACE O(N*M)

int editDistBU(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // base case

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }

    return dp[n][m];
}

// optimized approach
// TIME-O(N*M) , SPACE -O(M)

int editDistopt(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<int> prev(m + 1, -1), curr(m + 1, -1);

    // base case

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                curr[j] = prev[j - 1];
            else
            {
                curr[j] = 1 + min(curr[j - 1], min(prev[j], prev[j - 1]));
            }
        }

        prev = curr;
    }

    return prev[m];
}

int main()
{
    // your code goes here
    string str1 = "voldemort";
    string str2 = "dumbledore";

    cout << editDist(str1, str2, str1.length() - 1, str2.length() - 1);
    cout << endl;

    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << editDist1(str1, str2, str1.length() - 1, str2.length() - 1, dp);
    cout << endl;

    cout << editDistBU(str1, str2);
    cout << endl;

    cout << editDistopt(str1, str2);

    return 0;
}