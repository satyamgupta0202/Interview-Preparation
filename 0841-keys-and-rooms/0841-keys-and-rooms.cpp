class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        queue<int>q;
        set<int>s;
        vector<int>vis(n+1,0);
        
        auto v = rooms[0];
        vis[0]=1;
        s.insert(0);
        for(auto it: v)
        {
            q.push(it);
        }
        
        while(q.size())
        {
            auto curr = q.front();
            
            if(vis[curr]==0)
            {
                 q.pop();
                 s.insert(curr);
                 auto v = rooms[curr];
                 for(auto it: v)
                  {
                    q.push(it);
                  }
            }
            else{
                q.pop();
            }
            vis[curr]=1;
        }
           
        return s.size()==n;
        
    }
};