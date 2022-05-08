// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
    {
        int n = nums.size();
        vector<pair<int, int>> v;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());

        vector<int> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (v[i].second == i)
            {
                visited[i] = true;
            }
            else
            {
                int node = v[i].second;

                int cycle = 0;
                while (visited[node] != true)
                {

                    visited[node] = true;
                    cycle++;
                    node = v[node].second;
                }

                if (cycle != 0)
                    ans += cycle - 1;
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends