#include <bits/stdc++.h>
#define MAX 100
using namespace std;

/*Three different approach*/

/* Naive case Take O(N^2 log(k))

int kthSmallest(int arr[MAX][MAX], int n, int k)
{
   priority_queue<int> pq;
   for(int i = 0; i< n; i++){
       for(int j = 0; j< n; j++){
           if(k!=0){
               pq.push(arr[i][j]);
               k--;
           }
           else if(pq.top() > arr[i][j]){
               pq.pop();
               pq.push(arr[i][j]);
           }
       }
   }
   return pq.top();
}

*/

/* Method 2:
priority queue take N + Klogn == K log(N)
Space O(n)
Intution: just greater element find along row and col of that number

*/

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // min heap-    priority_queue<int,vector<int>,greater<int>>pq;
    // but we also store int index value

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push({mat[0][i], {0, i}});
    }

    for (int i = 0; i < k - 1; i++)
    {
        int row = pq.top().second.first;
        int col = pq.top().second.second;

        pq.pop();

        if (row + 1 < n)
            pq.push({mat[row + 1][col], {row + 1, col}});
    }

    return pq.top().first;
}

/*Method 3:

Using binary search
 O(log(max(mat[i][j]))*n*log(n)) and space complexity as O(1)
*/

int kthSmallestopt(int mat[MAX][MAX], int n, int k)
{
    int low = mat[0][0];
    int high = mat[n - 1][n - 1];
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int count = 0; // count no. of element less or equal to mid

        for (int row = 0; row < n; row++)
        {
            int t= upper_bound(mat[row], mat[row]+n, mid) - mat[row];
            count+=t;
        }

        if (count >= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int k = 7;

    int mat[][MAX] = {{16, 28, 60, 64},
                      {22, 41, 63, 91},
                      {27, 50, 87, 93},
                      {36, 78, 87, 94}};

    cout << kthSmallest(mat, 4, k)<<endl;
    cout << kthSmallestopt(mat, 4, k);

    return 0;
}
