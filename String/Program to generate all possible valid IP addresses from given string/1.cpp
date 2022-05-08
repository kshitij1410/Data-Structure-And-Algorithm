#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255.
The numbers cannot be 0 prefixed unless they are 0.

Input: 25525511135
Output: [“255.255.11.135”, “255.255.111.35”]
Explanation:
These are the only valid possible
IP addresses.

Input: "25505011535"
Output: []
Explanation:
We cannot generate a valid IP
address with this string.


*/
void solve(string s, int i, int j, int level, string ans, vector<string> &res)
{

    // base case
    if (i == (j + 1) and level == 5)
    {
        res.push_back(ans.substr(1));
        return;
    }
    if(level>5) return ;

    for (int k = i; k < i + 3 and k <= j; k++)
    {
        string sub = s.substr(i, k - i + 1);
        stringstream ss;
        ss << sub;
        int num;
        ss >> num;

        // check for valid ip
        if ((s[i] == '0' and sub.size() > 1) or num > 255)
            return;

        solve(s, k + 1, j, level + 1, ans + '.' + sub, res);
    }
}

vector<string> validIp(string s, int n)
{
    vector<string> res;
    solve(s, 0, n - 1, 1, "", res);
    return res;
}

int main()
{
    string s = "25525511135";
    int n = s.length();
    vector<string> res;
    res = validIp(s, n);

    for (auto x : res)
    {
        cout << x << endl;
    }
    return 0;
}
