class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int t) 
    {
        int r = grid.size();
        int c = grid[0].size();
        
        int  n = r*c;
        
        int v[n];
        int k = 0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                v[k++]=grid[i][j];
            }
        }
        
        //for(auto it:v)cout<<it<<" ";
        
        while(t--)
        {
            int temp = v[n-1];
            for(int i=n-1;i>0;i--)
            {
                v[i]=v[i-1];
            }
            v[0]=temp;
        }
        
      //  for(auto it:v)cout<<it<<" ";
        
        vector<vector<int>>ans(r,vector<int>(c,0));
        for(int i=0;i<n;i++)
        {
            ans[i/c][i%c]=v[i];
        }
        return ans;
    }
};