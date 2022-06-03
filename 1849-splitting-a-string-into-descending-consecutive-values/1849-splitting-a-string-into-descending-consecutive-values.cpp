class Solution {
public:

    
    bool solve(string k , unsigned long long indx , unsigned long long n , long unsigned long prev)
    {
        
        if(indx==n)return true;
        
        
        
        for(unsigned long long i = 1; i<=k.size();i++)
        {
            string jk = k.substr(0,i);
            unsigned long long a = stoull(jk);
            if(a == prev)
            {
                string temp = k.substr(i);
                if(solve(temp , 0 , temp.size() , a-1))return true;
            }  
        }
        return false; 
    }
    
    
    
    bool splitString(string s) {
        
        unsigned long long n = s.size();
        for(long long i=1;i<n;i++)
        {
            string lol = s.substr(0,i);
            string k = s.substr(i);
            unsigned long long kk = stoull(lol);
            if(solve(k,0,k.size(),kk-1))return true;
        }
        return false;
        
    }
};