class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int row = matrix.size() , col = matrix[0].size();
        
        // make it 1-D array
        int l = 0 , r = row*col-1;
        
        while(l<=r){
            
            int mid = l+ (r-l)/2;
            
            if(matrix[mid/col][mid%col] < target){
                l=mid+1;
            }
            else if(matrix[mid/col][mid%col] > target){
                r=mid-1;
            }
            else{
                return true;
            }             
        }  
        return false; 
        
    }
};


/**
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
**/