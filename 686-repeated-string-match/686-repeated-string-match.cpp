class Solution {
public:
    
    int p = 31;
    long long mod = 1e9+7 ;
    
    vector<int> cal(string b)
    {
        int n = b.size();
        vector<int>prefix(n,0);
        //memset(prefix,0,sizeof(prefix));
        
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
    
    int solve(string a , string b)
    {
        vector<int>prefix = cal(b);
        int i=0 , j=0;
        
        while(i<a.size())
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j!=0)j=prefix[j-1];
                else i++;
            }
            
            if(j==b.size())return 1;
        }
        
        return -1;
    }
    
    
    
    
    int repeatedStringMatch(string a, string b) {
        
        int cnt = 1;
        string temp = a;
        
        
        
        while(a.size()<b.size())
        {
            a = a+temp;
            cnt++;
        }
        
        
        
      if(solve(a,b)!=-1)return cnt;
            
       a = a+temp;
       if(solve(a,b)!=-1)return cnt+1;
        
       return -1;
        
    }
};