class Solution {
public:
    
    bool dfs(int node ,vector<int>&vis , vector<int>&dfsVis , vector<int>adj[] ){
        
        vis[node]=1;
        dfsVis[node]=1;
        
        for(auto it: adj[node]){
            if(vis[it]==0){
                if(dfs(it,vis,dfsVis,adj))return true;
            }
            else if(dfsVis[it]==1){
                return true;
            }
        }
        dfsVis[node]=0;
        return false;
        
    }
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();
        vector<int>adj[numCourses];
        vector<int>vis(numCourses,0);
        vector<int>dfsVis(numCourses,0);
        
        for(int i=0;i<n;i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[a].push_back(b);
        }
        
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
               if(dfs(i,vis,dfsVis,adj))return false;
            }
        }
        return true;
        
    }
};