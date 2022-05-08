// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, n;
        cin >> l >> n;
        int arr[l];
        for (int i = 0; i < l; i++)
            cin >> arr[i];
        if (findPair(arr, l, n))
            cout << 1 << endl;
        else
            cout << "-1" << endl;
    }

    return 0;
} // } Driver Code Ends

bool findPair(int arr[], int size, int n)
{
   // x-y=n ==> x=y+n or y=x-n  
   // two possible case 
   
    unordered_set<int> s;

    for (int i = 0; i < size; i++)
    {
        if (s.find(arr[i] + n) != s.end() or s.find(arr[i] - n) != s.end())
            return 1;
        else
            s.insert(arr[i]);
    }

    s.clear();
    return 0;
}