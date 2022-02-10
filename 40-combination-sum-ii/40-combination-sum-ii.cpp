class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(vector<int>&a, int target , vector<int>&path , int indx , int sum){
        
        if(sum == target){
            ans.push_back(path);
            return;
        }
        if(sum>target || indx>a.size())
        {
            return;
        }        
        
        for(int i=indx;i<a.size();i++){
            if(i!=indx && a[i-1]==a[i])continue;
            
            path.push_back(a[i]);
            sum=sum+a[i];
            solve(a,target,path,i+1,sum);
            path.pop_back();
            sum-=a[i];
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        
        sort(a.begin(),a.end());
        vector<int>path;
        solve(a,target,path,0,0);
        return ans;
        
    }
};