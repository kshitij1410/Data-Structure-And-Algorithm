#include <bits/stdc++.h>
using namespace std;

// Recursion
int lcs(string x, string y, int i, int j)
{

    // base case
    if (i == 0 || j == 0)
        return 0;

    if (x[i - 1] == y[j - 1])
        return (1 + lcs(x, y, i - 1, j - 1));
    else
    {
        return max(lcs(x, y, i - 1, j), lcs(x, y, i, j - 1));
    }
}

// Bottom up
void solve(string x, string y)
{
    int n = x.size();
    int m = y.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // for (int i = 0; i<=n; i++)
    // {
    //     dp[0][i] = 0;
    // }

    // for (int i = 0; i <=m; i++)
    // {
    //     dp[i][0] = 0;
    // }

    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int ans = dp[n][m];
    dp.clear();
    cout << ans;
}

// space optimization
//  O(N)  and time O(N*M)
void solve1(string x, string y)
{
    int n = x.size();
    int m = y.size();

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int i = 0; i <=n; i++)
    {
        prev[i] = 0;
    }

    for (int i = 1; i <=n; i++)
    {
        curr[i - 1] = 0;
        for (int j = 1; j <=m; j++)
        {
            if (x[i - 1] == y[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }

        prev = curr;
    }

    int ans = prev[m];
    prev.clear();
    curr.clear();
    cout << ans;
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int m = X.size();
    int n = Y.size();
    // vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
    // cout << "Length of LCS is " << lcs(X, Y, m, n, dp);
    cout << lcs(X, Y, m, n);
    solve1(X, Y);
    solve(X, Y);
    return 0;
}