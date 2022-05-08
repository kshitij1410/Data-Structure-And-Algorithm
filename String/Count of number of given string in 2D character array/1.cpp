#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

int solve(string pat, string input[], int i, int j, int n, int m, int idx)
{
    int ans = 0;
    if (i >= 0 and i < n and j >= 0 and j < m and pat[idx] == input[i][j])
    {
        int len = pat.size();
        char temp = temp[i][j];
        input[i][j] = 0;
        if (idx + 1 == len)
        {
            found = 1;
        }
        else
        {
            // left
            found + = solve(pat, input, i, j - 1, n, m, idx + 1);
            found += solve(pat, input, i, j + 1, n, m, idx + 1);  // right
            found + = solve(pat, input, i - 1, j, n, m, idx + 1); // top
            found += solve(pat, input, i + 1, j, n, m, idx + 1);  // bottom
        }
        input[i][j] = temp;
    }
    return found;
}

int searchword(string needle, string input[])
{
    int n = sizeof(input) / sizeof(input[0]);
    int m = input[0].size();
    int ans = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            ans += solve(needle, input, row, col, n, m, 0);
        }
    }
    return ans;
}

int main()
{
    string needle = "MAGIC";
    string input[] = {"BBABBM",
                      "CBMBBA",
                      "IBABBG",
                      "GOZBBI",
                      "ABBBBC",
                      "MCIGAM"};

    return 0;
}
