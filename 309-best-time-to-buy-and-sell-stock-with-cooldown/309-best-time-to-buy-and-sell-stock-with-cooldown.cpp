class Solution {
public:
    int maxProfit(vector<int>& p) 
    {
        int n = p.size();
        int buy = -p[0];
        int sell = 0;
        int cool = 0;
        
        for(int i=1;i<n;i++)
        {
            
            int nbuy = max(buy , cool-p[i]);
            int nsell = max(sell , p[i]+buy );
            int ncool  = max(cool , sell);
            
            buy = nbuy;
            sell = nsell;
            cool=ncool;
        }
        cout<<buy<<" "<<sell<<" "<<cool;
        return sell;
    }
};