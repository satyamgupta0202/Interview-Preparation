class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int>lv(n,-1);
        vector<int>rv(n,n);
        stack<pair<int,int>>sl,sr;
        
        for(int i=0;i<n;i++)
        {
            while(!sl.empty() && sl.top().first>=heights[i])
            {
                sl.pop();
            }
            
            if(!sl.empty() && sl.top().first < heights[i])
            {
                lv[i]=sl.top().second;
            }
            
            sl.push({heights[i],i});
        }
        
        //
        
           for(int i=n-1;i>=0;i--)
          {
            while(!sr.empty() && sr.top().first>=heights[i])
            {
                sr.pop();
            }
            
            if(!sr.empty() && sr.top().first < heights[i])
            {
                rv[i]=sr.top().second;
            }
            
            sr.push({heights[i],i});
          }
        
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int a = lv[i];
            int b = rv[i];
            
            ans = max(ans ,  heights[i]* (b-a-1) );
        }
        
        return ans;
    }
};