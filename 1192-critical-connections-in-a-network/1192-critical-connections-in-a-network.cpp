class Solution {
    private:
   int timer=1;

public:
    void dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &vis,vector<int> &tim,vector<int>&low,vector<vector<int>>&bridges){
        vis[node]=1;
        tim[node]=timer;
        low[node]=timer;
        timer++;
        for(auto it : adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){
                dfs(it,node,adj,vis,tim,low,bridges);
                low[node]=min(low[node],low[it]);
                if(low[it]>tim[node]) bridges.push_back({it,node});}
                else{

                low[node]=min(low[node],low[it]);
                }
                 
            }
        }
    
   
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
         vector<vector<int>> adj(n);
         for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
         }
   vector<int> vis(n,0);
   vector<int> tim(n);
   vector<int>low(n);
   vector<vector<int>> bridges;
   dfs(0,-1,adj,vis,tim,low,bridges);
   return bridges;

    }
};