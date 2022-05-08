#include <bits/stdc++.h>
using namespace std;

// Given an array arr[] and an integer K where K is smaller than size of array, the task is to
// find the Kth smallest element
// in the given array. It is given that all array elements are distinct.
// unsorted array

// Expected time -O(N), sc-O(log n)

// solution----------------------

// Approach 1: sort + k travesal ==o(NlogN) time

// Approach 2: QUICK SELECT AVERAGE TIME O(N) , BUT WROST CASE TIME O(N^2)

// APRROACH 3: USES PRIORITY QUEUE TIME- O(N) TIME TO INSERT AND TAKE OUT ELEMTNT O(KLOG N)
// TOTAL TIME : O(N+ KLOG N)

// LOOK AT THE CASES WE CAN REDUCE TIME BY USING MIN HEAP AND MAX HEAP

// SUPPOSE N=100 WE FIND 3TH SMALLEST ELEMENT THEN WE USE MIN HEAP BUT  -- O(N+ 3LOG N)
// SUPPOSE WE FIND 97 SMALLEST ELEMT THEN WE CAN USE MAX HEAP TO READUCE THE TIME COMPLEXITY --O(N+ (N-K)LOG (N-K))

int kthSmallest(int arr[], int l, int r, int k)
{

    int n = (l + r + 1);
    
    // min heap
    priority_queue<int, vector<int>, greater<int>> pmin;
    // max heap
    priority_queue<int, vector<int>> pmax;

    for (int i = l; i <= r; i++)
    {
        pmax.push(arr[i]);
        pmin.push(arr[i]);
    }

    int ans = 0;

    if (k <= n / 2)
    {
        // use min heap
        k--;
        while (k != 0)
        {
            pmin.pop();
            k--;
        }
        ans = pmin.top();
        return ans;
    }
    else
    {
        k = n - k;
        // use max heap
        while (k != 0)
        {
            pmax.pop();
            k--;
        }
        ans = pmax.top();
        return ans;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << kthSmallest(arr, 0, n - 1, k);

    return 0;
}