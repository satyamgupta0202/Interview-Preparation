class Solution {
public:
    int maximumUnits(vector<vector<int>>& a, int w) 
    {
        int n = a.size();
        vector<pair<int,int>>v;
        
        for(auto it: a)
        {
            v.push_back({it[1] , it[0]});
        }
        
        sort(v.begin() , v.end() , greater<pair<int,int>>());
        
        int ans = 0;
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            if(ans + v[i].second <=w)
            {
                res+= v[i].first*v[i].second;
                ans+=v[i].second;
            }
            
            else
            {
                int k = w - ans;
                res+=k*(v[i].first);
                return res;
            }
        }
        return res;
        
    }
};