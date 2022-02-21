class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        int cnt=0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        
        //cout<<cnt<<endl;
        
//       
        if(cnt==0)return 0;
        int ans = 0;
        int cc=0;
        while(!q.empty())
        {
            
          int m = q.size();
          bool ok  = false;
            
         while(m--)
            {
                
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                // left
                if(c-1>=0 && grid[r][c-1]==1)
                {
                    ok=true;
                    q.push({r,c-1});
                    grid[r][c-1]=2;
                    cc++;
                }
                
                if(c+1<col && grid[r][c+1]==1 )
                {
                     ok=true;
                    q.push({r,c+1});
                    grid[r][c+1]=2;
                    cc++;
                }
                
                if(r-1>=0 && grid[r-1][c]==1)
                {
                    ok=true;
                    q.push({r-1,c});
                    grid[r-1][c]=2;
                    cc++;
                }
                
                if(r+1<row && grid[r+1][c]==1)
                {
                    ok=true;
                    q.push({r+1,c});
                    grid[r+1][c]=2;
                    cc++;
                }                
            }
            
            ans++;    
        }
        
       if(cnt==cc)
        return ans-1;
        return -1;     
    }
};