
#include <bits/stdc++.h>
#define R 4
#define C 4
using namespace std;

/* time complexity O(r+c)*/

/* you can take top most col and bottom most row */

void searchRowColWise(int r, int c, int mat[R][C], int s)
{
    int row = 0;
    int col = c - 1;
    while (col >= 0 and row < r)
    {
        if (mat[row][col] > s)
        {
            col--;
        }
        else if (mat[row][col] < s)
        {
            row++;
        }
        else
        {
            break;
        }
    }

    if (col < 0 or row >= r)
        printf("element not exist");
    else
        cout << row << " " << col << endl;
}

int main()
{

    int a[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 13, 14},
                   {15, 16, 17, 19}};
    int s = 12;

    searchRowColWise(R, C, a, s);
    return 0;
}