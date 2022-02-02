class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){   
                if(matrix[i][j]==0){          
                   q.push({i,j});       
                }   
            }
        }
        
        while(!q.empty()){
            
            auto r = q.front().first;
            auto c = q.front().second;
            q.pop();
            for(int i=0;i<col;i++){
                matrix[r][i]=0;
            }
            for(int i=0;i<row;i++){
                matrix[i][c]=0;
            } 
        }
        
    }
};