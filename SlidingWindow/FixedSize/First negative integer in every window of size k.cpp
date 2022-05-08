// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k)
{

    queue<long long> q;
    vector<long long> ans;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            q.push(arr[i]);
    }

    if (q.empty() == true) // all no. are positive
    {
        ans.push_back(0);
    }
    else
    { // at least one no. are negative
        ans.push_back(q.front());
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] < 0) // check current element is negative
            q.push(arr[i]);

        if (q.size() > 0 and q.front() == arr[i - k]) // if remove element in sliding window is equal to q.front then pop() it
            q.pop();

        if (q.empty() == true)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(q.front());
        }
    }

    return ans;
}

int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
