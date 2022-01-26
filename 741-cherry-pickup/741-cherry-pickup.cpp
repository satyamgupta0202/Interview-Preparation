class Solution {
public:
    int dy[2]={1,1};
    int dp[50][50][50][50];
    int solve(vector<vector<int>>&grid,int i1,int j1 , int i2,int j2) {
        
        if(i1>=grid.size() || i2>=grid.size() || j1>=grid[0].size() || j2>=grid[0].size() || grid[i1][j1]==-1 || grid[i2][j2]==-1)return INT_MIN;
        
        if(i1==grid.size()-1 && j1==grid[0].size()-1){
            return grid[i1][j1];
        }
        
        if(i2==grid.size()-1 && j2==grid[0].size()-1){
            return grid[i2][j2];
        }
        
        if(dp[i1][j1][i2][j2]!=-1)return dp[i1][j1][i2][j2];
        
        
        int c=0;
          
        int op1 = solve(grid,i1,j1+1,i2,j2+1);
        int op2 = solve(grid,i1+1,j1,i2+1,j2);
        int op3 = solve(grid,i1+1,j1,i2,j2+1);
        int op4 = solve(grid,i1,j1+1,i2+1,j2);
        
        c=max( max(op1,op2) , max(op3,op4) ); 
        if(i1==i2 && j1==j2){
            c+=grid[i1][j1];
        }
        else{
            c+= grid[i1][j1]+grid[i2][j2];
        }
        dp[i1][j1][i2][j2]=c;
        return c;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
       
        int row = grid.size();
        int col = grid[0].size();
        memset(dp,-1,sizeof(dp));
        int k =solve(grid,0,0,0,0);
        if(k<0)return 0;
        return k;
      
    }
};