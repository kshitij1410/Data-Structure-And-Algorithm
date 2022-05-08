#include<bits/stdc++.h>
using namespace std;

/* greater than both nebighour
Ex-: 5,20,40,30,20,50,60
  ans 40>20 and 40>30

Ex- 40 30 20
 ans 40

ex- 10 20 30
 ans 30 >20

*/

int peakEle(int arr[],int n)
{
  int high=n-1;
  int low=0;

  while(low<=high)
  {
   
   int mid=(low+high)/2;

   if(mid==0 and arr[mid]> arr[mid+1]) return arr[mid];
   if(mid==n-1 and arr[mid]>arr[mid-1]) return arr[mid];
   else if(arr[mid]> arr[mid-1]  and arr[mid]> arr[mid+1]) return arr[mid];
   else if (arr[mid]<=arr[mid-1]) high=mid-1;
   else low=mid+1;
  }

}


int main()
{
    int arr[] ={5,20,40,30,20,50,60};
    int n=sizeof(arr)/sizeof(arr[0]);
   cout<<peakEle(arr,n);
    return 0;
}