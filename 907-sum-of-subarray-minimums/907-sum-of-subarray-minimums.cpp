class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        stack<pair<int,int>>s1,s2;
        vector<int>l(n,0),r(n,0);
        
        //left
        //ek barr hi equal wale count karengey
        //concept : count total subarray where particular index value serves as minimim
        // agr side wale (left,right) bigger hai tho hamara element god ho sakta uss subarray kae liye
        
        
        for(int i=0;i<n;i++)
        {
            int cnt = 1;
            
            while(!s1.empty() && s1.top().first>arr[i])
            {
                cnt+=s1.top().second;
                s1.pop();
            }
            
            s1.push({arr[i],cnt});
            l[i]=cnt;
        }
        
        //right
         for(int i=n-1;i>=0;i--)
        {
            int cnt = 1;
            
            while(!s2.empty() && s2.top().first>=arr[i])
            {
                cnt+=s2.top().second;
                s2.pop();
            }
            
            s2.push({arr[i],cnt});
            r[i]=cnt;
        }
        
        int ans= 0;
        int mod = 1e9+7;
        
        for(int i=0;i<n;i++)
        {
               ans = (ans + (long)arr[i]*l[i]*r[i])%mod;
        }
        return ans;   
    }
};