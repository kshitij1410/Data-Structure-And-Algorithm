#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 4

void spiralTraversal(int r, int c, int mat[R][C])
{
    int top = 0;
    int left = 0;
    int right = c - 1;
    int bottom = r - 1;

    while (top <= bottom and left <= right)
    {
        for (int i = top; i <= right; i++)
            cout << mat[top][i] << " ";
        top++;

        for (int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";
        right--;

        if (top <= bottom) // problem occur when 3X4 matrix
        {
            for (int i = right; i >= left; i--)
                cout << mat[bottom][i] << " ";
            bottom--;
        }

        if (left <= right) // problem occur when 4X3 matrix
        {
            for (int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";
            left++;
        }
    }
}

int main()
{
    int a[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12}};

    spiralTraversal(R, C, a);
    return 0;
}