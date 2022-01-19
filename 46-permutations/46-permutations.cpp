class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(vector<int>&nums,map<int,bool>&mp , vector<int>&path ,  int i , int n){
        
        if(path.size()==n){
            ans.push_back(path);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(!mp[nums[i]]){
                path.push_back(nums[i]);
                mp[nums[i]]=true;
                solve(nums,mp,path,i,n);
                path.pop_back();
                mp[nums[i]]=false;
            }
            
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        map<int,bool>mp;
        for(int i=0;i<n;i++)mp[nums[i]]=false;
        vector<int>path;
        solve(nums,mp,path,0,n);
        return ans;
    }
};