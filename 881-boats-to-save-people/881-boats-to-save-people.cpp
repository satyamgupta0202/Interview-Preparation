class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) 
    {
        sort(p.begin() , p.end() , greater<int>());
        int i=0 , j=p.size()-1;
        int cnt=0;
        while(i<=j)
        {
            if(i==j)
            {
                cnt++;
                i++;j--;
            }
            else if(p[i]+p[j]<=limit)
            {
                cnt++;
                i++;
                j--;
            }
            else if(p[i]<=limit)
            {
                i++;
                cnt++;
            }
        }
        return cnt;
    }
};