class Solution {
public:
    int maxArea(int H, int W, vector<int>& h, vector<int>& v)
    {
        int n1 = h.size();
        int n2 = v.size();
        sort(h.begin() , h.end());
        sort(v.begin() , v.end());
        int mod = 1e9+7;
        
        int a = -1 , b = -1;
        
        a = h[0];
        b = v[0];
        
        for(int i=0;i<n1-1;i++)
        {
            a = max(a , (int)(h[i+1]-h[i]));
        }
        
        a = max(a , H - h[n1-1] );
        
        for(int i=0;i<n2-1;i++)
        {
            b = max(b , v[i+1]-v[i]);
        }
        
        b = max(b , W - v[n2-1]);
        a = a%mod;
        b = b%mod;
        return (1LL*a*b)%mod;
        
    }
};
