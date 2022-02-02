class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int buy = prices[0];
        int sp = 0;
        int profit = INT_MIN;
        for(int i=1;i<n;i++){
            sp = prices[i];
            profit = max(profit , sp-buy);
            buy  = min(buy,prices[i]);
        }
        if(profit<0)return 0;
        return profit;
    }
};