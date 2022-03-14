class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        
        int dp[row][col];
        int s=0;
        for(int i=0;i<col;i++)
        {
            dp[0][i]=grid[0][i]+s;
            s = dp[0][i];
        }
        
        s=0;
        for(int i=0;i<row;i++)
        {
            dp[i][0]=grid[i][0]+s;
            s=dp[i][0];
        }
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[row-1][col-1];
    }
};