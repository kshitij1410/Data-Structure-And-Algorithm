#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

void rotate90(int mat[R][C])
{
    for (int i = 0; i < C; i++)
    {
        int first = 0;
        int last = R - 1;
        while (first <= last)
        {
            swap(mat[first][i], mat[last][i]);
            first++;
            last--;
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << mat[i][j] << " ";

        cout << endl;
    }
}

void transpose(int r, int c, int mat[R][C])
{
    for (int i = 0; i < c; i++)
    {
        int j = i + 1;
        while (j < c and j < r)
        {
            swap(mat[i][j], mat[j][i]);
            j++;
        }
    }


   for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << mat[i][j] << " ";

        cout << endl;
    }

    cout<<"rotation is "<<endl;
    rotate90(mat);
}

int main()
{
    int a[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}};

    transpose(R, C, a);
    return 0;
}