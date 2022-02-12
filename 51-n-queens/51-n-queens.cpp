class Solution {
public:
    
    vector<vector<string>>ans;
    
    bool isValid(int i , int j , vector<string>&path , int n)
    {
        int row = i , col = j;
        
        while(col>=0)
        {
            if(path[row][col]=='Q')return false;
            col--;
        }
        
        col = j;
        row=i;
        
        while(col>=0 && row>=0)
        {
            if(path[row][col]=='Q')return false;
            
            row--;
            col--;
        }
        
        col =j;
        row=i;
        
        while(col>=0 && row>=0 && row<n)
        {
            if(path[row][col]=='Q')return false;
            
            row++;
            col--;
        }
        
        return true;
        
        
    }
    
    
    
    void solve(int n , vector<string>&path , int curr)
    {
        if(curr==n)
        {
            ans.push_back(path);
            return;
        }
        
        if(curr>n)return;
        
        for(int i=0;i<n;i++)
        {
            if(isValid(i,curr,path,n))
            {
                path[i][curr]='Q';
                solve(n,path,curr+1);
                path[i][curr]='.';
            }
        }
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        string s(n,'.');
        vector<string>path(n,s);
        
        solve(n,path,0);
    
        return ans;
    }
};