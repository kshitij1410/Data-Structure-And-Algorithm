class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans=false;
        int m=matrix.size();
        int n=matrix[0].size();
        
        //time complexity y*O(M)  y is constant time for lower bound function
        
        for(int i=0;i<m;i++)
        {
            int temp = lower_bound(matrix[i].begin(),matrix[i].end(),target) -matrix[i].begin();
            if(temp<n and matrix[i][temp]==target)
            {
                ans=true;
                break;
            }
        }
        
        return ans;
    }
};