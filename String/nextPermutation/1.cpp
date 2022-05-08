
class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        
        if(n==1) return arr;
        
        int i=n-2;
        while(arr[i]>=arr[i+1] and i>=0)
        {
            i--;
        }
        
        int j=n-1;
        if(i>=0)
        {
            while(arr[i]>=arr[j] and j>=0)
            {
               j--;
            }
        }
        
        if(i>=0 and j>=0)
        swap(arr[i],arr[j]);
        
        reverse(arr.begin()+i+1,arr.end());
        
        return arr;
        
    }
};