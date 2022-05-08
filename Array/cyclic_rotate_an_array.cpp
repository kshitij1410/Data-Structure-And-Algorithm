#include<bits/stdc++.h>
using namespace std;

//method 1:-rotate function
//take about left rotation i.e 1,2,3,4,5 ==> 5,1,2,3,4 ==> 
// rotate(first iterator,middle iterator,last iterator)
//rotate(arr,arr+n-1,arr+n)

//right rotation i.e 1,2,3,4,5 ==> 2,3,4,5,1 
//rotate(arr,arr+1,arr+n)
void rotate(int arr[] ,int n)
{
  rotate(arr,arr+n-1,arr+n);
}

//method2: -- swapping 

void rotate1(int arr,int n)
{
    for(int i=n-1;i>0;i--)
    swap(arr[i],arr[i-1]);
    
}

int main()
{
   int arr[]={1,2,3,4,5};
   int n=sizeof(arr)/sizeof(arr[0]);
   rotate(arr,n);
    return 0;
}