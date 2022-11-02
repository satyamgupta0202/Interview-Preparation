class Solution {
public:
    
    int check(string s1 , string s2)
    {
        int n = s1.size();
        int c = 0;
        
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])c++;
        }
        return c;
    }
    
    int ans = INT_MAX;
    map<string , bool>mpka;
    
    
    void solve(string start , string  end , vector<string>& bank,int count)
    {
        
        if(start == end)
        {
            ans =  min(ans , count);
            return;
        }
        
        int n = bank.size();
        
        for(int i=0;i<n;i++)
        {
            auto s = bank[i];
            if(mpka[s]==false && check(s,start)==1)
            {
                
                mpka[s]=true;
                solve(s , end , bank ,count+1);
                mpka[s]=false;
                // solve(s,end,bank , count);
            }
        }
    }
    
    
    int minMutation(string start, string end, vector<string>& bank) 
    {
        
        for(auto it: bank)
        {
            mpka[it] = false;
        }
        
        solve(start , end , bank , 0);
        if(ans==INT_MAX)return -1;
        return ans;
    }
};