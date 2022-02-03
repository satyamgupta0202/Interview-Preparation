class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n = intervals.size();
        int low = intervals[0][0];
        int high = intervals[0][1];
        
        for(int i=1;i<n;i++){
            
            int start = intervals[i][0];
            int  end  =   intervals[i][1];
            
            if(high>=start){
                high = max(end,high);
            }
            
            else if(start>high){
                ans.push_back({low,high});
                low = start;
                high = end;
            }
        }
       ans.push_back({low,high});
        return ans;
        
    }
};