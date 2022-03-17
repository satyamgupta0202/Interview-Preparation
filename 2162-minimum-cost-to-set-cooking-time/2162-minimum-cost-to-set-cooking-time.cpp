class Solution {
public:
    
    int solve(int start , int move , int push , int left , int right)
    {
        
        int f1 = left/10 , f2 = left%10   , s1 = right/10 , s2 = right%10 ;
        int ans = 0;
        int check = start;
        
        if(f1)
        {
            ans+= (check==f1?0:move) + push;
            check = f1;
        }
        
        if(f1 || f2)
        {
            ans+= (check==f2?0:move) + push;
            check = f2;
        }
        
        if(f1||f2||s1)
        {
            ans+= (check==s1?0:move) + push;
            check = s1;
        }
        
        ans+= (check==s2?0:move) + push;
        
        return ans;
        
    }
    
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds)
    {
        int ans = INT_MAX;
        if(targetSeconds<60)
        {
           return  solve(startAt , moveCost , pushCost ,  0 ,targetSeconds);
        }
        
        int left = targetSeconds/60 , right = targetSeconds%60;
        
        if(left<=99)
        {
           ans = solve(startAt , moveCost , pushCost ,  left , right);
        }
        
        left--;
        right+=60;
        if(right<=99)
        ans = min(ans , solve(startAt , moveCost , pushCost ,  left ,right));
    
        return ans;
            
    }
};