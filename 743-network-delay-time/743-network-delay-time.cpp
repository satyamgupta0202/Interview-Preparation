class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>adj[n+1];
        vector<int>vis(n+1,0);
        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >q;
        
        for(int i = 0 ; i<times.size() ; i++){
            int a = times[i][0];
            int b = times[i][1];
            int c = times[i][2];
            adj[a].push_back({c,b});
        }
        
        q.push({0,k});
        dis[k]=0;
        
        while(!q.empty()) {
            
            auto curr = q.top().second;
            auto wt = q.top().first;
            q.pop();
            
            for(auto it : adj[curr]){
                auto next = it.second;
                auto nwt = it.first;
                if(dis[next] >  dis[curr]+nwt){
                    dis[next] = dis[curr]+nwt;
                    q.push({dis[next],next});
                }
            } 
        }
        int m  =-1;
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX){
                return -1;
            }
            ans = max(ans , dis[i]);
        }
        return ans;
        
    }
};