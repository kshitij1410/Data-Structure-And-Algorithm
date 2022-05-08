int longestKSubstr(string s, int k)
{
    // your code here
    int i = 0, j = 0, mx = -1;
    unordered_map<int, int> mp;
    int n = s.length();
    while (j < n)
    {
        mp[s[j]]++;
        if (mp.size() < k)
            j++;
        else if (mp.size() == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return mx;
}