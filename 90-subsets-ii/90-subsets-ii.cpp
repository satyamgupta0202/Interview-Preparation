class Solution {
public:
    
    set<vector<int>>s;
    
     void solve(vector<int>nums , int indx , int n , vector<int>&path , vector<vector<int>>&ans){
         
         if(indx==n){
             s.insert(path);
             return ;
         }
         
         if(indx>=n)return ;
        
             
             path.push_back(nums[indx]);
             solve(nums,indx+1,n,path,ans);
             path.pop_back();
             solve(nums,indx+1,n,path,ans);
             
         
         
         
     }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
            sort(nums.begin(),nums.end());
            int n  = nums.size();
            vector<vector<int>>ans;
            vector<int>path;
            solve(nums,0,n,path,ans);
            for(auto it: s){
                vector<int>k;
                for(int i=0;i<it.size();i++){
                    k.push_back(it[i]);
                }
                ans.push_back(k);
            }
            return ans;
    }
};