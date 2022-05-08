class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<char, int> mp;

        while (j < n)
        {
            if (mp.find(s[j]) == mp.end())
            {
                mp[s[j]] += 1;
                ans = max(ans, j - i + 1);
                j++;
            }
            else
            {

                while (s[i] != s[j])
                {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                // both are equal
                i++;

                j++;
            }
        }
        return ans;
    }
};