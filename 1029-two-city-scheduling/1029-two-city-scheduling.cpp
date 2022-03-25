class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& v) 
    {
        
        int n = v.size();
        int k = n/2;
        
        sort(v.begin(),v.end() , [](vector<int>&a , vector<int>&b){
           return abs(a[0]-a[1])>abs(abs(b[0]-b[1])); 
        });
        
        int a=0,b=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            
            if(b>=k)
            {
                ans+=v[i][0];
                a++;
            }
            
            else if(a>k)
            {
                ans+=v[i][0];
                a++;
            }
            
            else
            {
                if(v[i][0]<=v[i][1] && a<k)
                {
                    ans+=v[i][0];
                    a++;
                }
                else
                {
                    ans+=v[i][1];
                    b++;
                }
            }
            
            
        }
        return ans;
    }
};