#include <bits/stdc++.h>
using namespace std;
 
void revereseArray(int arr[], int s, int e)
{
    while(s<e)
    {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
     
    int n = sizeof(arr) / sizeof(arr[0]);
 
     
    // Function calling
    revereseArray(arr, 0, n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
       
    return 0;
}