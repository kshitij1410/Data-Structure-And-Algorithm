#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(vector<long long> arr, int low, int high)
{
    vector<long long> v;
    int n = high-low+1;
    v.push_back(0); // empty set consider

    for (int i = 1; i < (1 << n); i++)
    {
        int x = i;
        long long s = 0;
        int j = low-1;
        while (x)
        {
            int l = x & 1;
            if (l)
                s += arr[j];
            j++;
            x = x >> 1;
        }

        v.push_back(s);
    }
    return v;
}

int main()
{
    int n;
    cin >> n;
    long long a, b;
    cin >> a >> b;
    vector<long long> arr;

    for (int i = 0; i < n; i++)
    {
        long long val;
        cin >> val;
        arr.push_back(val);
    }

    vector<long long> v1, v2;

    // divide the array into two half
    v1 = solve(arr, 1, (n / 2));
    v2 = solve(arr, (n / 2) + 1, n);

    sort(v2.begin(), v2.end());
    
    long long ans = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        int t1 = lower_bound(v2.begin(), v2.end(), a - v1[i]) - v2.begin();
        int t2 = upper_bound(v2.begin(), v2.end(), b - v1[i]) - v2.begin();
        ans += t2 - t1;
    }
    v1.clear();
    v2.clear();
    arr.clear();
    
    cout << ans << endl;
    return 0;
}