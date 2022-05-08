class Solution {
public:
    string countAndSay(int n) {
       if(n==1)
           return "1";
        
        string s=countAndSay(n-1);
        
        int n1=s.size();
        int count=1;
        string ans="";
        for(int i=0;i<n1-1;i++)
        {
            if(s[i]==s[i+1])
                count++;
            else
            {
                ans+=to_string(count)+s[i];
                count=1;
            }
        }
        
        ans+=to_string(count)+s[n1-1];
        
        return ans;
    }
};