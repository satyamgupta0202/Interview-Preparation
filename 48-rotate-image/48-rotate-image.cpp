class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int row = matrix.size() , col = matrix[0].size();
        
        int i=0,j=0;
        int n = row;
        while(i<row && j<col){
            
            int p=i;
            while(p<n){
               
                swap(matrix[i][p] , matrix[p][j]);
                p++;
                
            }
            i++;
            j++;    
        }
        
       
        
        for(int i=0;i<n;i++){
            
            reverse(matrix[i].begin(),matrix[i].end());
            
        }
        
       
        
        
    }
};