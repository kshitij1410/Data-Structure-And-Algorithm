#include<bits/stdc++.h>
using namespace std;

int minStringValue(string str, int k)
{
    unordered_map<char,int>mp;
    int n=str.size();

    for(auto x : str)
    {
        mp[x]+=1;
    }
  
    priority_queue<int>pq;

    for(auto ele : mp)
    {
       pq.push(ele.second);
    }

    //pop element utill k become zero
    while(k!=0)
    {
        int t=pq.top();
        pq.pop();
        t=t-1;
        pq.push(t);
        k--;
    }

    int ans=0;
    while(!pq.empty())
    {
        int t=pq.top();
        pq.pop();
        ans+=t*t;
    }

return ans;
}

int main()
{
    string str = "abbccc"; // Input 1
    int k = 2;
    cout << minStringValue(str, k) << endl;
 
    str = "aaab"; // Input 2
    k = 2;
    cout << minStringValue(str, k);
 
    return 0;
}