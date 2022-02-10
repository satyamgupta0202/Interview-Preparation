class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(vector<int>&a , int target , int indx , vector<int>&path){
        
        if(indx==a.size()){
            if(target==0)ans.push_back(path);
            
            return;
        }
        
        if(a[indx]<=target){
            path.push_back(a[indx]);
            solve(a,target-a[indx],indx,path);
            path.pop_back();
        }
        
         solve(a,target,indx+1,path);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        
        vector<int>path;
        solve(a,target,0,path);
        
        return ans;
        
    }
};



/**
class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>s;
    void solve(vector<int>&a , int target , vector<int>&path , int indx,int sum){
        
        if(indx>=a.size()){
            int ss=0;
            
            for(int i=0;i<path.size();i++){
               ss+=path[i];
            }
          
            if(ss==target){
                s.insert(path);
            }

            return;
        }
        if(sum>target)return ;
        
        path.push_back(a[indx]);
        solve(a,target,path,indx,sum+a[indx]);
        path.pop_back();
       
        path.push_back(a[indx]);
        solve(a,target,path,indx+1,sum+a[indx]);
        path.pop_back();
        solve(a,target,path,indx+1,sum);       
       
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        
        vector<int>path;
        int indx = 0;
        int sum = 0;
        solve(a,target,path,0,0);
        vector<vector<int>>res;
        for(auto it: s){
            res.push_back(it);
        }
        return res;
    }
};
**/