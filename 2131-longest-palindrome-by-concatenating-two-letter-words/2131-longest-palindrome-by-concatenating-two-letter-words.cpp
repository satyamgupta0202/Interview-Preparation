class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        
        map<string,int>mp;
        for(auto it: words)
        {
            mp[it]++;
        }
        int lol = 0;
        int ans = 0;
        bool ok = false;
        
        for(auto it: mp)
        {

            auto s = it.first;
            auto n = it.second;
            auto ss = s;
            reverse(s.begin() , s.end());
            auto k = ss;
            ss = s;
            s = k;
            
            if(ss == s)
            {
                if(mp[ss]%2)
                {
                    int p = mp[ss]/2;
                    ans+= (p*4);
                    lol = 2;
                }
                else
                {
                    ok = true;
                    ans+= (mp[ss]*2);
                }
                mp[ss] = 0;
            }
            
            else
            {
                    if(mp.find(ss)!=mp.end())
                        {
                            ok = true;
                            ans+= (min(mp[ss] , mp[s]))*4;
                            mp[ss]=0;
                            mp[s]=0;
                        }
                    else
                        {
                            mp[s]=0;
                        }
            }
        }
        ans+=lol;
        
        return ans;
    }
};