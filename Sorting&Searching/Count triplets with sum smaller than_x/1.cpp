/* Intution: 
ex- -2,0,1,3  => pick -2 > (0,1,3) pick element with smaller sum possible pair (high-low) exit like (0,3) (0,1)   */

class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        long long ans = 0;
        sort(arr, arr + n);

        for (int i = 0; i < n; i++)
        {
            int low = i + 1;
            int high = n - 1;
            int target = sum - arr[i];

            while (low < high)
            {
                int temp = arr[low] + arr[high];

                if (target > temp)
                {
                    ans += high - low;
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        return ans;
    }
};
