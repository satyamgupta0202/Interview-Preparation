class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(vector<int>&arr , int target , vector<int>&path, int indx , int sum)
    {
        if(sum == target){
            ans.push_back(path);
            return;
        }
        if(sum>target)return;
        
        for(int i=indx;i<arr.size();i++){
            sum+=arr[i];
            path.push_back(arr[i]);
            solve(arr,target,path,i,sum);   //multiple baar le skate isiliye i hi rakhe ,,, combination 2 +1
            path.pop_back();
            sum-=arr[i];
        }
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        
        vector<int>path;
        solve(arr,target,path,0,0);
        return ans;
    }
};