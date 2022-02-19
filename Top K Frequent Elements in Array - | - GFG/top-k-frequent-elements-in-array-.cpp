// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        map<int,int>mp;
        for(auto it: nums)
        {
            mp[it]++;
        }
        
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        
        for(auto it: mp)
        {
            pq.push({it.second , it.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int>ans;
        while(pq.size()!=0)
        {
            int jk = pq.top().second;
            pq.pop();
            ans.push_back(jk);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends