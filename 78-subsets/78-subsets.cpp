class Solution {
public:
    
    void solve(vector<int>v , int indx , int n , vector<int>&path , vector<vector<int>>&ans){
        
       ans.push_back(path);
        
        if(indx>=n)return;
        
        for(int i=indx;i<n;i++){
            if(i!=indx && v[i]==v[i-1])continue;
            
            path.push_back(v[i]);
            solve(v,i+1,n,path,ans);
            path.pop_back();  
           // solve(v,i+1,n,path,ans);
        }     
    }
    
    
    
    vector<vector<int>> subsets(vector<int>& num1) {
        
        sort(num1.begin(),num1.end());
        vector<vector<int>>ans;
        vector<int>path;
        int n = num1.size();
        solve(num1,0,n,path,ans);
        return ans;    
    }
};