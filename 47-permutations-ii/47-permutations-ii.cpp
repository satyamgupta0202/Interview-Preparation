class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>s;
    
    void solve(vector<int>nums,int start,int end,vector<int>&path){
        
        if(start>=end){
           ans.push_back(nums);
            return;
        }
        set<int>s;
        for(int i=start;i<=end;i++){
            if(s.find(nums[i])!=s.end())continue;
            s.insert(nums[i]);
            swap(nums[i],nums[start]);
            solve(nums,start+1,end,path);
            swap(nums[i],nums[start]);
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n= nums.size();
        vector<int>path;
        solve(nums,0,n-1,path);
        
//         for(auto it: s){
//             ans.push_back(it);
//         }
        return ans;
        
    }
};