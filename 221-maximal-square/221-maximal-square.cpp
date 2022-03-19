class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0;
        int dp[row][col];
        
        for(int i = 0;i<row;i++)
        {
            dp[i][0] = matrix[i][0]-'0';
            ans = max(ans, dp[i][0]);
        }
        for(int i=0;i<col;i++)
        {
            dp[0][i] = matrix[0][i]-'0';
            ans = max(ans , dp[0][i]);
        }
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i][j] = 1+ min(dp[i-1][j-1] , min(dp[i-1][j] ,dp[i][j-1]) );
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return ans*ans;
    }
};