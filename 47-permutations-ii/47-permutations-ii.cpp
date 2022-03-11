class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>st;
    void solve(vector<int>&nums, vector<int>&path , int n , int ind){
        
        if(path.size()==n){
            st.insert(path);
            return;
        }
        
        for(int i=ind;i<n;i++)
        {
            if(i!=ind && nums[i]==nums[i-1])continue;
            
            path.push_back(nums[i]);
            swap(nums[i],nums[ind]);
            solve(nums,path,n,ind+1);
            swap(nums[i],nums[ind]);
            path.pop_back();
                       
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<int>path;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        solve(nums,path,n,0);
        vector<vector<int>>res;
        for(auto it: st)
        res.push_back(it);
        return res;
    }
};