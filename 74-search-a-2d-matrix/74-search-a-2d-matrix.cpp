class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //naive approach (o) m*n
        
        int row = matrix.size() , col = matrix[0].size();
        
        for(int i=0;i<row;i++)
        {
            if(binary_search(matrix[i].begin() , matrix[i].end() , target)==true)
            {
                return true;
            }
        }
        return false;
    }
};