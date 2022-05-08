#include <bits/stdc++.h>
using namespace std;

/*
Q1 Given a matrix of n*n size, the task is to find whether all rows are circular rotations of each other or not.

Examples:

Input: mat[][] = 1, 2, 3
                 3, 1, 2
                 2, 3, 1
Output:  Yes
All rows are rotated permutation
of each other.

Input: mat[3][3] = 1, 2, 3
                   3, 2, 1
                   1, 3, 2
Output:  No
Explanation : As 3, 2, 1 is not a rotated or
circular permutation of 1, 2, 3

*/
const int MAX = 1000;
bool isPermutedMatrix( int mat[MAX][MAX], int n)
{
    
    string str_cat = "";
    for (int i = 0 ; i < n ; i++)
        str_cat = str_cat + to_string(mat[0][i]);
 
    
    str_cat = str_cat + str_cat;
 
    // Start traversing remaining rows
    for (int i=1; i<n; i++)
    {
        // Store the matrix into vector in the form
        // of strings
        string curr_str = "";
        for (int j = 0 ; j < n ; j++)
            curr_str = curr_str + to_string(mat[i][j]);
 
        // Check if the current string is present in
        // the concatenated string or not
        if (str_cat.find(curr_str) == string::npos)
            return false;
    }
 
    return true;
}
 
// Drivers code
int main()
{
    int n = 4 ;
    int mat[MAX][MAX] = {{1, 2, 3, 4},
        {4, 1, 2, 3},
        {3, 4, 1, 2},
        {2, 3, 4, 1}
    };
    isPermutedMatrix(mat, n)? cout << "Yes" :
                              cout << "No";
    return 0;
}