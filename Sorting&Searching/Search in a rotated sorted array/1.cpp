class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        int high = arr.size() - 1;
        int low = 0;
        int ans = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] == target)
            {
                ans = mid;
                break;
            }

            // left part is sorted
            if (arr[low] <= arr[mid])
            {
                if (arr[low] <= target and arr[mid] >= target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (arr[mid] <= target and arr[high] >= target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return ans;
    }
};