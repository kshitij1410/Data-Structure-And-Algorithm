// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int search(string pat, string txt)
    {

        /*Slinding Window Time - O(26*txt.size())*/
        vector<int> dp(26, 0);
        vector<int> hash(26, 0);
        int ans = 0;
        int n = txt.size();
        int m = pat.size();
        for (int i = 0; i < pat.size(); i++)
        {
            dp[pat[i] - 'a'] += 1;
            hash[txt[i] - 'a'] += 1;
        }
        if (dp == hash)
            ans++;

        for (int i = m; i < n; i++)
        {
            hash[txt[i] - 'a'] += 1;
            hash[txt[i - m] - 'a'] -= 1;

            // compare both the hash fun and dp fun
            if (dp == hash)
                ans++;
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends