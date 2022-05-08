/* find max mat[c][d]-mat[a][b] where c>a and d>b
  logic : let suppose (a,b)==(0,0) then (c,d)must be lie between (1-n,1-n)

  if any how i can find the max value between (1-n,1-n)
  then i will subtract from mat(0,0) then it is contribute to my  possible answer.

  */

//Time - O(N*N);
int findMaxValue(vector<vector<int>> &mat, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = n - 1; j >= 0; j--)
        {
            dp[i][j] = mat[i][j];
            if (j + 1 < n)
                dp[i][j] = max(dp[i][j], dp[i][j + 1]);
            if (i + 1 < n)
                dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            ans = max(ans, dp[i + 1][j + 1] - mat[i][j]);
        }
    }

    delete[] dp;

    return ans;
}