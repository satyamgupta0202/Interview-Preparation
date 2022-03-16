class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int cp = prices[0];
        int sp = 0;
        int p = 0;
        
        for(int i=1;i<n;i++)
        {
          sp = prices[i];
          p = max(p , sp-cp);
          cp = min(cp,prices[i]);
        }
        
        return p;
        
    }
};