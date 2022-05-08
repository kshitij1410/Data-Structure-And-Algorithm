#include <bits/stdc++.h>
using namespace std;

/* greater than both nebighour
Ex-: 5,20,40,30,20,50,60
  ans 40>20 and 40>30

Ex- 40 30 20
 ans 40

ex- 10 20 30
 ans 30 >20

*/

//Method 1: use hashmap or unordered map take Time O(N) but space O(n)

// Efficient approach O(n) Moore's Voting Algo  , space O(1)
int majorityElement(int a[], int size)
{
    int cand = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (count == 0)
            cand = a[i];
        if (a[i] == cand)
            count++;
        else
            count--;
    }

   //check cand is actually a majority element 
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (cand == a[i])
            count++;
    }

    if (count > (size / 2))
        return cand;
    return -1;
}

int main()
{
    int arr[] = {5, 20, 40, 30, 20, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << majorityElement(arr, n);
    return 0;
}