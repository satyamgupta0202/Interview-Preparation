class Solution {
public:
    
    int ans = 0;
    
    
    int dfs(vector<vector<int>>& grid,int i , int j ,int r , int c , int s)
    {
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]==0 )return 0;
        
            int temp = grid[i][j];
            grid[i][j]=0;
            int t1 =  dfs(grid,i+1,j,r,c,s);
            int t2 =  dfs(grid,i-1,j,r,c,s);
            int t3 =  dfs(grid,i,j-1,r,c,s);
            int t4 =  dfs(grid,i,j+1,r,c,s); 
            grid[i][j]=temp;
            return grid[i][j] + max(max(t1,t2) , max(t3,t4));  
    }
    
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]!=0)
                {
                    int s = 0;
                    
                    ans = max(ans , dfs(grid,i,j,r,c,0));
                  //  cout<<ans<<endl;
                    
                }
            }
        }     
        return ans;
    }
};