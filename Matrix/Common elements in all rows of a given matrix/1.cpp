#include <bits/stdc++.h>
using namespace std;
#define M 4
#define N 5

// time complexity  (rclogc)
// method 1:

vector<int> printCommonElements(int mat[M][N], int r, int c)
{
    vector<int> result;
    unordered_set<int> ans;

    // time - O(r*clogc)
    for (int i = 0; i < r; i++)
        sort(mat[i], mat[i] + c);

    // time O(c*(r+c))
    for (int i = c - 1; i >= 0; i--)
    {
        int top = mat[0][i];
        int count = 0;
        int temp = c - 1;
        int row = 1;

        while (row < r and temp >= 0)
        {
            if (top < mat[row][temp])
                temp--;
            else if (top > mat[row][temp])
                break;
            else
            {
                count++;
                row++;
                temp = c - 1;
            }
        }

        if (count == r - 1)
            ans.insert(top);
    }

    for (auto x : ans)
    {
        result.push_back(x);
    }
    return result;
}

// method 2: O(m*n)
void printCommonElements2(int mat[][N], int r, int c)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < c; i++)
        mp[mat[0][i]] = 1;

    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mp[mat[i][j]] == i)
            {
                mp[mat[i][j]] += 1;

                if (i == r - 1 and mp[mat[i][j]] == r)
                {
                    cout << mat[i][j] << " ";
                }
            }
        }
    }
}

int main()
{

    int mat[M][N] =
        {
            {1, 2, 1, 4, 8},
            {3, 7, 8, 5, 1},
            {8, 7, 7, 3, 1},
            {8, 1, 2, 7, 9},
        };

    vector<int> ans = printCommonElements(mat, M, N);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;
    printCommonElements2(mat, M, N);
    return 0;
}