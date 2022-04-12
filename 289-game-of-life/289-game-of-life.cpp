class Solution {
public:
    
    int check(vector<vector<int>>& board , int i ,int j)
    {
        int cnt = 0;
        int r = board.size();
        int c = board[0].size();
        
        if(j-1>=0 && (board[i][j-1]==1||board[i][j-1]==2))cnt++;
        if(j+1<c && (board[i][j+1]==1||board[i][j+1]==2))cnt++;
        if(i-1>=0 && (board[i-1][j]==1||board[i-1][j]==2))cnt++;
        if(i+1<r && (board[i+1][j]==1||board[i+1][j]==2))cnt++;
           
        if(j-1>=0 && i-1>=0 && (board[i-1][j-1]==1||board[i-1][j-1]==2))cnt++;
        if(i-1>=0 && j+1<c && (board[i-1][j+1]==1||board[i-1][j+1]==2))cnt++;
          
        if(j-1>=0 && i+1<r && (board[i+1][j-1]==1||board[i+1][j-1]==2))cnt++;
        if(i+1<r && j+1<c && (board[i+1][j+1]==1||board[i+1][j+1]==2))cnt++;
          cout<<cnt<<endl;
          return cnt;
        
        
    }
    
    
    void gameOfLife(vector<vector<int>>& board) 
    {
        int r = board.size();
        int c = board[0].size();
//       0->1   :3
//       1->0   : 2
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int k = check(board,i,j);
                if(board[i][j]==0)
                {
                   if(k==3)
                   {
                       board[i][j]=3;
                   }
                }
                else
                {
                    if(k<2 || k>3)
                    {
                        board[i][j]=2;
                    }
                }
            }
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==2)
                {
                    board[i][j]=0;
                }
                if(board[i][j]==3)
                {
                    board[i][j]=1;
                }
            }
        }
        
        
    }
};