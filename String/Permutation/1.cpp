#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> find_permutation(string S)
    {
        vector<string> s;
        
        sort(S.begin(), S.end());
        s.push_back(S);

        
        while (next_permutation(S.begin(), S.end()))
        {
            s.push_back(S);
        }
        return s;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
