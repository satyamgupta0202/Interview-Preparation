class Solution {
public:
    
    bool dfs(int node , vector<int>&vis , vector<int>adj[],int par,int c,vector<int>&col){
        vis[node]=1;
        col[node]=c;
        for(auto it: adj[node]){
            if(vis[it]==0){
             if(!dfs(it , vis, adj,node,!c,col))return false;
            }
            else if(col[it]==col[node]){
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int>adj[n+1];
        for(int i=0;i<dislikes.size();i++){
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int ans=0;
        vector<int>col(n+1,-1);
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                if(!(dfs(i,vis,adj,-1,0,col))){
                    return false;
                }     
            } 
        }
        return true;
        
    }
};