
#include <bits/stdc++.h>
#define R 4
#define C 4
using namespace std;

void rotatematrix(int m, int n, int mat[R][C])
{
    int top = 0;
    int right = n - 1;
    int left = 0;
    int bottom = m - 1;

    int temp = mat[0][0];

    while (top < bottom and left < right)
    {
        int prev = mat[top + 1][left];
        for (int i = left; i <= right; i++)
        {
            int curr = mat[top][i];
            mat[top][i] = prev;
            prev = curr;
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            int curr = mat[i][bottom];
            mat[i][bottom] = prev;
            prev = curr;
        }
        right--;

        for (int i = right; i >= left; i--)
        {
            int curr = mat[bottom][i];
            mat[bottom][i] = prev;
            prev = curr;
        }
        bottom--;

        for (int i = bottom; i >= top; i--)
        {
            int curr = mat[i][left];
            mat[i][left] = prev;
            prev = curr;
        }
        left++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int a[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}};

    // int a[R][C] = {{1, 2, 3},
    //                {4, 5, 6},
    //                {7, 8, 9}};

    rotatematrix(R, C, a);
    return 0;
}