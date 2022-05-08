// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<int> st;
        vector<long long> left(n, -1);
        vector<long long> right(n, n);
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            if (st.top() == -1)
            {
                st.pop();
            }

            else
            {
                int temp = arr[st.top()];

                while (temp >= arr[i])
                {
                    st.pop();
                    if (!st.empty())
                        temp = arr[st.top()];
                    else
                        break;
                }

                if (temp < arr[i])
                    left[i] = st.top();
            }

            st.push(i);
        }

        while (!st.empty())
            st.pop();

            
        st.push(n);

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.top() == n)
            {
                st.pop();
            }

            else
            {
                int temp = arr[st.top()];

                while (temp >= arr[i])
                {
                    st.pop();
                    if (!st.empty())
                        temp = arr[st.top()];
                    else
                        break;
                }

                if (temp < arr[i])
                {
                    right[i] = st.top();
                }
            }

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = max((right[i] - left[i] - 1) * arr[i], ans);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends