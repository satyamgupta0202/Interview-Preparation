// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int nums[], int n)
    {
        // Your code here
        
        stack<pair<int,int>>sl,sr;
        vector<int>left(n,-1);
        vector<int>right(n,n);
        
       //right
        for(int i=n-1;i>=0;i--)
        {
            while(!sr.empty() && sr.top().first>=nums[i])
            sr.pop();
            
            if(!sr.empty() && sr.top().first<nums[i])
            {
                right[i]=sr.top().second;
            }
            
            sr.push({nums[i],i});
        }
        
        //right
        for(int i=0;i<n;i++)
        {
            while(!sl.empty() && sl.top().first>=nums[i])
            sl.pop();
            
            if(!sl.empty() && sl.top().first<nums[i])
            {
                left[i]=sl.top().second;
            }
            
            sl.push({nums[i],i});
        }
        
        
        int ans[n+1]={0};
        
        for(int i=0;i<n;i++)
        {
            int len = right[i]-left[i]-1;
            ans[len]= max(ans[len],nums[i]);
        }
        
        vector<int>res(n);
        
        for(int i=n-1;i>=1;i--)
        {
            ans[i] = max(ans[i],ans[i+1]);
            // res.push_back(temp);
        }
        
        for(int i=1;i<=n;i++)
        {
            res[i-1]=ans[i];
        }
        
        //reverse(res.begin(),res.end());
        return res;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends