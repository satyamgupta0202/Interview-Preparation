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