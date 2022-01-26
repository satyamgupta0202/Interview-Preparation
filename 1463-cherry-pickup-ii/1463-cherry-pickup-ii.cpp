class Solution {
public:
    
    int dp[100][100][100];
    int dy[3] = {0,-1,1};
    
    int solve(vector<vector<int>>&grid,int row ,int col ,int i,int j,int k){
      
        if(i==row)return 0;
        
        if(j<0 || k<0 || j>=col || k>=col)return INT_MIN;
        
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        
        int ans = 0;
        
        for(int p=0;p<3;p++){
            for(int q=0;q<3;q++){ 
                ans = max(ans, solve(grid,row,col,i+1,j+dy[p],k+dy[q]));
            }
        }
        
        if(j==k){
            ans+=grid[i][j];
        }else{
            ans+=grid[i][j]+grid[i][k];
        }
        dp[i][j][k]=ans;
        return ans;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        memset(dp,-1,sizeof(dp));
        int row = grid.size();
        int col = grid[0].size();
        return solve(grid,row,col,0,0,col-1);
        
    }
};