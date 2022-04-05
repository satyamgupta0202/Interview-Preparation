class Solution {
public:
    int maxArea(vector<int>& height) {
        
//         [2,3,4,5,18,17,6]
        
        int n = height.size()-1;
        int j=n;
        int i=0;
        int min_h = min(height[i],height[j]);
        int max_h = max(height[i],height[j]);
        int max_area ((j-i)*(min_h));
        
        while(i<j){
            
            if(height[j]>min_h){
                i++;
            }else{
                j--;
            }
            min_h = min(height[i],height[j]);
            max_h = max(height[i],height[j]);
            
            max_area = max(max_area , min_h*(j-i));            
            
        }
        return max_area;
        
    }
};