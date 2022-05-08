#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        string str;
        cin >> str;

        unordered_map<char, int> mp;
        int n = str.size();

        for (int i = 0; i < n; i++)
        {
            mp[str[i]] += 1;
        }

        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            int same_char = mp[str[i]];
            int odd_digit = n - same_char;

            if (same_char > odd_digit + 1)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
            cout << "0" << endl;
        else
            cout << "1" << endl;
    }


    return 0;
}