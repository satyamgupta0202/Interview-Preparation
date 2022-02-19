class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>>pq;        
        int n = arr.size();
        
        for(int i=0;i<n;i++)
        {
            int kk = abs(x-arr[i]);
            pq.push({kk,arr[i]});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        
        vector<int>ans;
        while(!pq.empty())
        {
            auto a = pq.top().second;
            ans.push_back(a);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};