class Solution {
public:
    
    int solve(vector<int>&values , int i , int j ,  vector<vector<int>>&dp)
    {
        
        if(i>=j)return 0;
        
        long ans = INT_MAX;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        for(int k=i;k<j;k++)
        {
            
            long temp = solve(values , i , k , dp ) + solve(values , k+1 , j , dp) + (long long) 1LL*values[i-1]*values[k]*values[j];
            ans = min(ans , temp);
        }
        
        
        return dp[i][j] =  ans;
        
        
    }
        
        
        
        
        
        
        
    int minScoreTriangulation(vector<int>& values) 
    {
        vector<vector<int>>dp(51 ,  vector<int>(51 , -1));
        int n = values.size();
        // memset(dp  , sizeof(dp) , -1);
        return solve(values , 1 , n-1 , dp);
    }
};