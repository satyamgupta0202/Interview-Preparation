class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t)
    {
        int ans = 0;
        int c = 0;
        int k = 0;
        int lp = -1 , lg= -1 , lm = -1;
        for(auto s: g)
        {
            int m = 0 , p = 0 , g = 0 ;
            
            for(auto it: s)
            {
                
                if(it=='M')m++ , lm = k;
                
                if(it=='P')p++ , lp = k;
                
                if(it=='G')g++ , lg = k;
                
            }
            
            if(m>0)
            {
                ans = ans + m;
            }
            
            if(p>0)
            {
                ans = ans + p;
            }
            
            if(g>0)
            {
                ans = ans + g;
            }
            
            k++;
            
        }
        
      for(int i=1;i<t.size();i++)
      {
          t[i] = t[i] + t[i-1];
      }
        
      if(lm>0)
      {
          ans+=t[lm-1];
      }
    
      if(lp>0)
      {
          ans+=t[lp-1];
      }
        
      if(lg>0)
      {
          cout<<lg<<" ";
          ans+=t[lg-1];
      }
        
      return ans;  
        
    }
};