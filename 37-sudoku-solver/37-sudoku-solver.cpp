class Solution {
public:
    
bool solve(vector<vector<char>>& board ,  vector<vector<int>>&row ,  vector<vector<int>>&col ,          vector<vector<int>>&box ,int r , int c ){
        
    if(r==9 && c == 0)return true;
    
        int nr = r , nc = c+1;
    
        if(c==9){
            nr++;
            nc=0;
        }
    
    
        if(board[r][c]!='.'){
            return solve(board, row,col,box,nr,nc);
        }
        
            for(int k=1;k<=9;k++){
                
                int kk = (r/3)*3 +(c/3);
                
                if( row[r][k]==0 && col[c][k]==0 && box[kk][k] == 0 ){
                    
                    board[r][c] = k+'0';
                    row[r][k]=1;
                    col[c][k]=1;
                    box[kk][k]=1;
                    
                    if(solve(board, row,col,box,nr,nc))return true;
                    
                    board[r][c] = '.' ;
                    row[r][k]=0;
                    col[c][k]=0;
                    box[kk][k]=0;        
                }   
        }
    return false;
        
        
    }
    
    
    
    void solveSudoku(vector<vector<char>>& board) {
        
        vector<vector<int>>row(9,vector<int>(10,0));
        vector<vector<int>>col(9,vector<int>(10,0));
        vector<vector<int>>box(9,vector<int>(10,0));


        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                if(board[i][j]!='.'){
                    int val = board[i][j] - '0';
                   // cout<<val<<endl;
                    row[i][val]=1;
                    col[j][val]=1;
                    int temp = (i/3)*3 + (j/3);
                    box[temp][val]=1;  
                }
                   
            }
        } 
        solve(board, row, col , box , 0,0); 
    }
};