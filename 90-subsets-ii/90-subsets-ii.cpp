class Solution {
public:
    vector<vector<int>>ans;
    //Cisco
    void solve(vector<int>& nums, int indx , vector<int>&path)
    {
        ans.push_back(path);
        
        if(indx>=nums.size())return;
        
        for(int i=indx;i<nums.size();i++)
        {
            
            if(i!=indx && nums[i]==nums[i-1])
            {
                continue;
            }
            path.push_back(nums[i]);
            solve(nums,i+1,path);
            path.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>path;
        solve(nums,0,path);
        return ans;
    }
};