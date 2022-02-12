class Solution {
public:
    
    vector<vector<int>>ans;
    
    void solve(vector<int>&nums , int n , vector<int>&path , int ind){
        
        if(path.size()==n){
            ans.push_back(path);
            return ;
        }
        
        if(ind>=n)return;
        
        for(int i=ind;i<n;i++){
            
            path.push_back(nums[i]);
            swap(nums[ind],nums[i]);
            solve(nums,n,path,ind+1);
            swap(nums[ind],nums[i]);
            path.pop_back();
           
            
            
            
            
        }
        
       
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>path;
        
        // map<int,int>mp;
        // for(int i=0;i<n;i++)mp[nums[i]]=-1;
        
        solve(nums,n,path,0);
        return ans;
    }
};



/** extra space 
 if(path.size()==n){
            ans.push_back(path);
            return;
        }
        
        if(ind>=n)return;
        
        for(int i=0;i<n;i++){
            
            if(mp[nums[i]]==-1){
                
                path.push_back(nums[i]);
                mp[nums[i]]=1;
                solve(nums,n,path,mp,i);
                path.pop_back();
                mp[nums[i]]=-1; 
                //solve(nums,n,path,mp,i+1);
          }    
       }
       **/