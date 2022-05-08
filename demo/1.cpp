#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{2,8,30,15,25,12};
   
    cout<<"-1"<<" ";
    for(int i=1;i<v.size();i++)
    {
        auto it=lower_bound(v.begin(),v.begin()+i-1,v[i]);
        if(it !=v.end()) cout<<*it<<" ";
        else cout<<"-1"<<" ";

    }

  return 0;
}