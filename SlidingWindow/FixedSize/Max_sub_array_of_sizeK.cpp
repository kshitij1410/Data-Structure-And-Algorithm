#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    int maximumSumSubarray(int k, vector<int> &arr , int n){
        
        int sum=0;
        
        for(int i=0;i<k;i++)
        {
          sum+=arr[i];    
        }
        
        int mx=sum;
        
        for(int i=k;i<n;i++)
        {
            sum+=arr[i]-arr[i-k];
            
            mx=max(sum,mx);
        }
        
        return mx;
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   