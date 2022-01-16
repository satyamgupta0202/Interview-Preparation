class Solution {
public:
    
    void solve(vector<int>v , int indx , int n , vector<int>&path , vector<vector<int>>&ans){
        
        if(indx == n){
            ans.push_back(path);
            return ;
            
        }
        
        path.push_back(v[indx]);
        solve(v,indx+1,n,path,ans);
        path.pop_back();
        solve(v,indx+1,n,path,ans);
        
    }
    
    
    
    vector<vector<int>> subsets(vector<int>& num1) {
        
        vector<vector<int>>ans;
        vector<int>path;
        int n = num1.size();
        solve(num1,0,n,path,ans);
        return ans;    
    }
};