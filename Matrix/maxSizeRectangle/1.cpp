// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


class Solution
{
public:
    int maxHistogram(vector<int> arr, int n)
    {
        stack<int> st;
        vector<int> left(n, -1);
        vector<int> right(n, n);
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

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = max((right[i] - left[i] - 1) * arr[i], ans);
        }

        return ans;
    }

    int maxArea(int arr[MAX][MAX], int n, int m)
    {

        vector<int> dp;
        for (int i = 0; i < m; i++)
            dp.push_back(arr[0][i]);
        int ans = maxHistogram(dp, m);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 0)
                    dp[j] = 0;
                else
                    dp[j] = dp[j] + 1;
            }

            int temp = maxHistogram(dp, m);
            ans = max(ans, temp);
        }

        return ans;
    }
};


int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
