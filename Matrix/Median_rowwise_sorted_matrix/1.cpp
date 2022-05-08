#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int countNumberofElementLesserthanorEqualto(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

//time complexity - (32 * rlog(c))  32 for upper bound function 
int median(vector<vector<int>> &matrix, int r, int c)
{

    int ans = -1;
    int high = 2000; // according to the constraint
    // why i am taking high according to the constraint bcz question not say it is column wise sorted
    //  so test case like r=3 , c=1 ==> 6,3,1  then according to the solution -1 (when high=matrix[r-1][c-1]) will be the answer but the correct answer is 6.

    // if question will say that row and column wise sorted matrix then take (high=matrix[r-1][c-1]) otherwise take value from constraint.

    int low = 1;

    /* condition given r*c is always odd*/

    int medianplace = ((r * c) / 2) + 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int count = 0;

        for (int i = 0; i < r; i++)
        {
            // count += countNumberofElementLesserthanorEqualto(matrix[i], mid);
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (count >= medianplace)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}
int main()
{
    int r = 3;
    int c = 3;

    /* condition r*c is always odd*/

    vector<vector<int>> matrix = {
        {16, 28, 60},
        {22, 41, 63},
        {27, 50, 87},
    };
    cout << median(matrix, r, c);

    return 0;
}
