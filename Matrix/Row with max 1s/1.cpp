// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	   int top=m-1;
	   int row=0;
	   int ans=-1;
	   while(top>=0 and row<n)
	   {
	       if(arr[row][top]==1)
	       {
	           ans=row;
	           top--;
	       }
	       else
	       row++;
	       
	   }
	   
	   return ans;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends