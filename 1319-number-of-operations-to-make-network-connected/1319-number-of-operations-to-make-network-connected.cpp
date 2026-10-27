class Solution {
public:
  void dfs (int i,vector<vector<int>> &adjls,vector<int> &vis){
     vis[i]=1;
     for(auto it : adjls[i]){
        if(!vis[it]) dfs(it,adjls,vis);
     }
  }
    int makeConnected(int n, vector<vector<int>>& connections) {
         vector<int> vis(n,0);
         vector<vector<int>> adjls(n);
         if(connections.size()<n-1) return -1;
         for(int i=0;i<connections.size();i++){
            adjls[connections[i][0]].push_back(connections[i][1]);
            adjls[connections[i][1]].push_back(connections[i][0]);
         }
         int cnt=0;
         for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjls,vis);
            }
         }
  return cnt-1;  }
};