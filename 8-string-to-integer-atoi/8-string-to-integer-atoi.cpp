class Solution {
public:
    int myAtoi(string s) {
        
        int n=s.size();
        int i=0;
        long res=0;
        bool ok = false;
        
        while(i<n && s[i]==' ')i++;
        
        if( s[i]=='-')
        {
            ok=true;
            i++;
        }
        else if(s[i]=='+')i++;
        
        while(i<n)
        {
            if(s[i]>='0' && s[i]<='9' && res<2147483648)
            {
                res  = res*10 + (s[i]-'0');
                i++;
            }
            else
                break;
        }
        
        if(ok)res*=-1;
        if(res<=-2147483648)return  -2147483648;
        if(res>=2147483648)return  2147483647;
        return res;
    }
};