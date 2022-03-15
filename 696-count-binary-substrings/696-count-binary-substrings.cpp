class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        int cnt = 0;
        int n = s.size();
        int res=0;
        int a=1,b=0;
        int temp=0;
        for(int i=1;i<n;i++)
        {
            
           if(s[i]==s[i-1])
           {
               a++;
           }
            else
            {
                res+= (min(a,b));
                b=a;
                a=1;
            }   
        }
        res+= (min(a,b));
        
        
        
   
        
        return res;
        
    }
};