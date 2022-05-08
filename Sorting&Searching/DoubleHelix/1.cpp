#include <bits/stdc++.h>
using namespace std;

int maxSolve(vector<int> v1, vector<int> v2, int i, int j)
{
    int ans1 = 0;
    int ans2 = 0;
    int res = 0;
    while (i >= 0 and j >= 0)
    {
        if (v1[i] > v2[j])
        {
            ans1 += v1[i];
            i--;
        }
        else if (v1[i] < v2[j])
        {
            ans2 += v2[j];
            j--;
        }
        else
        {
            // if they ar equal then take max from both the ans
            res += max(ans1, ans2) + v1[i];
            i--;
            j--;
            ans1 = 0;
            ans2 = 0;
        }
    }

    while (i >= 0)
    {
        ans1 += v1[i];
        i--;
    }
    while (j >= 0)
    {
        ans2 += v2[j];
        j--;
    }

    res += max(ans1, ans2);
    return res;
}
int main()
{

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        else
        {
            vector<int> v1;
            vector<int> v2;
            for (int i = 0; i < n; i++)
            {
                int val;
                cin >> val;
                v1.push_back(val);
            }

            int m;
            cin >> m;

            for (int i = 0; i < m; i++)
            {
                int val;
                cin >> val;
                v2.push_back(val);
            }

            cout << maxSolve(v1, v2, n - 1, m - 1)<<endl;
        }
    }
    return 0;
}