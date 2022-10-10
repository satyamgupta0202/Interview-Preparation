class Solution {
public:
    string breakPalindrome(string s) 
    {
        
        int n = s.size();
        
        if(n == 1)
            return "";
        
        if(n%2)
        {
            
            int p = n/2;
            bool ok1 = false , ok2 = false;
            for(int i=0;i<n;i++)
            {
                if(i!=p && s[i]!='a')
                {
                    ok1 = true;   
                }
                
                if(i==p && s[i]=='a')
                {
                    ok2 = true;
                }
            }
            
            if(!ok1 && !ok2)
            {
                s[n-1]='b';
                return s;
            }
            
        }
        
        
        int k = n/2;
        
        
        char c = 'a';
        int i = 0;
        
        while(i<n)
        {
           
            while(i<n && s[i]=='a')
            {
                i++;
            }
            
            if(i<n && s[i]!='a')
            {
                s[i]='a';
                return s;
            }
            
            if(i==n)
            {
                // cout<<"lol"<<endl;
                s[i-1]='b';
                return s;
            }
        }
        
        return "";
        
    }
};