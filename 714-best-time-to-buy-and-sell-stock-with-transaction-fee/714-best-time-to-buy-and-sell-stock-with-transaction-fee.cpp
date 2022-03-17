class Solution {
public:
    int maxProfit(vector<int>& p, int f)
    {
        int cp = -p[0];
        int sp = 0;
        int n = p.size();
        
        for(int i=1 ;i<n; i++)
        {
            cp = max(cp , sp-p[i]);
            sp = max(sp , cp+p[i]-f);
            
        }
        
        return sp;
    }
};