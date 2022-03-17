class Solution {
public:
    int maxProfit(vector<int>& p) 
    {
       int n = p.size();
       vector<int>v1(n,0);
       vector<int>v2(n,0);
    
        int cp = p[0];
        int sp = 0;
        int k=0;
        for(int i=1;i<n;i++)
        {
          sp = p[i];
          if(sp-cp > k)
          {
              k = sp-cp;
          }  
          v1[i]=k;
          cp = min(cp,p[i]);  
        }
        
        k=0;
        sp = p[n-1];
        cp = 0;
        
        for(int i=n-2;i>0;i--)
        {
           cp = p[i];
           if(sp - cp > k)
           {
               k = sp - cp;
           }
         sp = max(sp,p[i]);
        v2[i+1] = k;
        }
        
        
        // for(int i=0;i<n;i++)
        //     cout<<v1[i]<<" ";
        // cout<<'\n';
        // for(int i=0;i<n;i++)
        //     cout<<v2[i]<<" ";
        
        int ans = 0;
        
        for(int i=0;i<n-1;i++)
        {
            ans = max(ans , v1[i]+v2[i+1]);
        }
        
        ans = max(ans , v1[n-1]);
  
        
        
      return ans;  
        
        
    }
};