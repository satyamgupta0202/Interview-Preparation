class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, pair<int,int>>mp;
        
        for(auto it: nums)
        {
            if(mp.count(it) == 0)
            {
                mp[it] = {1,it};
            }
            else
            {
                mp[it].first++;
            }
        }
        
        vector<pair<int,int>>v;
        
        for(auto it: mp)
        {
            v.push_back(it.second);
        }
        
        sort(v.begin() , v.end() , greater<pair<int,int>>());
        
        vector<int>ans;
        
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        
        return ans;
    
    }
};