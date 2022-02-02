class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size() , col = matrix[0].size();
        bool isRow = false , isCol=false;
        
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0){
                isCol = true;
                break;
            }
        }
        for(int i=0;i<col;i++){
            if(matrix[0][i]==0){
                isRow=true;
                break;
            }
        }
        
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
       
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(isRow){
            for(int i=0;i<col;i++){
                matrix[0][i]=0;
            }
        }
        if(isCol){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }
        
        
    }
};



/**
Day 1 : striver
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
**/