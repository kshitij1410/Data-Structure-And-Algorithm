#include <bits/stdc++.h>
using namespace std;

// This approach won’t work for negative numbers


int lenOfLongSubarr(int arr[], int n, int k)
{
    int i, j;
    i = j = 0;
    int ans = 0;
    int sum = 0;
    while (j < n)
    {
        sum += arr[j];

        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            ans = max(j - i + 1, ans);
            j++;
        }
        else
        {
            // ex- 15,5,7,30 k=30
            // i=0, j=3 sum=57
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }

            j++;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {-5, 8, -14, 2, 4, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 15;
    cout << "Length = "
         << lenOfLongSubarr(arr, n, k);
    return 0;
}