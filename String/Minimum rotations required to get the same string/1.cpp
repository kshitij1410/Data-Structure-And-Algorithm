#include<bits/stdc++.h>
using namespace std;

/*

Q1
Given a string, we need to find the minimum number of rotations required to get the same string.
Examples: 
 

Input : s = "geeks"
Output : 5

Input : s = "aaaa"
Output : 1
         
*/

/* time complexity -O(N*N) and space O(2*N) i.e substr method also take n time 
 Method 1  temp=str+str 
  ex- geeks
  temp=geeksgeeks
  for(int i=1;i<=n;i++)
  {
      string t= temp.substr(i,n);
      if(t==str)
      return i;
  }
*/

/* Method 2: O(N*N) but space O(1)
 ex-geeks
 for 1 st iteration eeks + g
 for 2nd iteration eks +ge
 for 3rd iteration ks + gee
 for 4 rd iteration s+geek wrong i am starting the index from 1 so only three iteration is possible
 
*/



int findRotations(string str)
{
    int n=str.size();
    for(int i=1;i<n-1;i++)
    {
        if(str.substr(i,n-i) + str.substr(0,i) == str)
         return i;

    }
    return n;
    
}


int main()
{
    string str = "geeks";
    cout << findRotations(str) << endl;
    return 0;
}
