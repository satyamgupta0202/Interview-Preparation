class Solution {
public:
    
    vector<int>solve(string b)
    {
        int n = b.size();
        vector<int>prefix(n,0);
        
        for(int i=1;i<n;i++)
        {
            int j = prefix[i-1];
            
            while(j>0 && b[i]!=b[j])
            {
                j = prefix[j-1];
            }
            if(b[i]==b[j])
            {
                j++;
            }
            prefix[i]=j;
        }
        return prefix;
    }
    
    
    int strStr(string a, string b) {
        
        if(b.size()==0)return 0;
        
        vector<int>prefix = solve(b);
        int i=0,j=0;
        
        while(i<a.size())
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j!=0)
                {
                    j = prefix[j-1];
                }
                else
                {
                    i++;
                }
            }
            
            if(j==b.size())
            {
                return i-b.size();
            }
        }
        return -1;
    }
};