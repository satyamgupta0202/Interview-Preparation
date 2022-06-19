class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
       int ans = 0;
        for(auto it: s)
        {
            if(it=='0')ans++;
        }
        
        int base = 1;
        int num = 0;
        int n = s.size();
        for(int i=n-1;i>=0;i--)
        {
            if(num + base <=k)
            {
                if(s[i]=='1')
                {
                    num+=base;
                    ans++;
                }
            }
            else
            {
                return ans;
            }
            base = base*2;
        }
        return ans;
    }
};