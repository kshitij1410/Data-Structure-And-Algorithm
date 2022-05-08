#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given a 2D grid of characters and a word, find all occurrences of the given word in the grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form).
The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up, Vertically Down and 4 Diagonal directions.
Example:

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "GEEKS"

Output: pattern found at 0, 0
        pattern found at 0, 8
        pattern found at 1, 0
Explanation: 'GEEKS' can be found as prefix of
1st 2 rows and suffix of first row

*/
// const int MAX=20;

#define MAX 20

// I am not appply this method(Backtracking) bcz it goes (1,9)--> (0,9)--> (0,10)--> (0,11)--> (0,12)  this is not possible in that question

// bool solve(char grid[MAX][MAX], int i, int j, int r, int c, string pat, int size, int idx)
// {
//     // boundary case
//     if (i < 0 or i >= r or j < 0 or j >= c)
//         return false;

//     if (grid[i][j] != pat[idx])
//         return false;
//     else
//     {
//         idx += 1;

//         if (size == idx)
//             return true;

//         return solve(grid, i, j + 1, r, c, pat, size, idx) ||     // right
//                solve(grid, i, j - 1, r, c, pat, size, idx) ||     // left
//                solve(grid, i - 1, j, r, c, pat, size, idx) ||     // top
//                solve(grid, i + 1, j, r, c, pat, size, idx) ||    // bottom
//                solve(grid, i - 1, j + 1, r, c, pat, size, idx) || // diagonal right
//                solve(grid, i - 1, j - 1, r, c, pat, size, idx) || // diagonal left
//                solve(grid, i + 1, j - 1, r, c, pat, size, idx) || // diagonal top
//                solve(grid, i + 1, j + 1, r, c, pat, size, idx);   // diagonal bottom
//     }
// }

// bool patternSearch(char grid[MAX][MAX], string pat, int r, int c)
// {
//     int n = pat.size();
//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             if (solve(grid, i, j, r, c, pat, n, 0))
//                 cout << i << " " << j << " ";
//         }
//     }
// }

int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool solve(char grid[MAX][MAX], int i, int j, string pat, int R, int C)
{
    int n = pat.size();
    if (pat[0] != grid[i][j])
    return false;

    for (int dir = 0; dir < 8; dir++)
    {
        //first charcter already match
        int rdir = i+x[dir];
        int cdir = j+y[dir];
        int ii = 1;
        for (ii = 1; ii < n; ii++)
        {
            // boundary condition
            if (rdir < 0 or rdir >= R or cdir < 0 or cdir >= C)
            {
                break;
            }

            if (pat[ii] != grid[rdir][cdir])
            {
                break;
            }
            rdir += x[dir];
            cdir += y[dir];
        }
        if (n == ii)
            return true;
    }
    return false;
}

bool patternSearch(char grid[MAX][MAX], string pat, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (solve(grid, i, j, pat, r, c))
                cout << i << " " << j << " ";
        }
    }
}
int main()
{
    int R = 3, C = 13;
    char grid[MAX][MAX] = {"GEEKSFORGEEKS",
                           "GEEKSQUIZGEEK",
                           "IDEQAPRACTICE"};

    patternSearch(grid, "GEEKS", R, C);
    cout << endl;

    return 0;
}
