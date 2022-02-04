class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();
        
        for(auto it: nums){
            mp[it]++;
        }
        vector<int>ans;
        for(auto it: mp){
            if(it.second > floor(n/3)){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};