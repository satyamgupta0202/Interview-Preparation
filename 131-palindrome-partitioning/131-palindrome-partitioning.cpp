class Solution {
public:

    vector<vector<string>>ans;
    
    bool check(int i , int j , string s)
    {
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    
    void solve(string s , int index, int n , vector<string>&path)
    {
        if(index == n){
            ans.push_back(path);
            return;
        }
        
        for(int i=index;i<n;i++){
            
            if(check(index,i,s))
            {
              
                path.push_back(s.substr(index , i-index+1));
                solve(s,i+1,n,path);
                path.pop_back();
            }
            
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        
        vector<string>path;
        int n = s.size();
        
        solve(s,0,n,path);
        
        return ans;
        
    }
};