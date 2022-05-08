class Solution
{
public:
    int findSubArraySum(int nums[], int n, int k)
    {
        unordered_map<int, int> mp;
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (sum == k)
                ans++;

            if (mp.find(sum - k) != mp.end())
                ans += mp[sum - k];

            mp[sum]++;
        }

        return ans;
    }
};