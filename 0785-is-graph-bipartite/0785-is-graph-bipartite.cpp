class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<pair<int,int>> q;
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int start=0;start<n;start++){
            if(vis[start]!=-1) continue;

        q.push({start,-1});
        vis[start]=0;
         int i=1;
        while(!q.empty()){
        int size=q.size();
        for(int j=0;j<size;j++){
        auto front=q.front();
        q.pop();
        int node= front.first;
        int parent=front.second;

        for(auto it :graph[node] ){
          if(vis[it]==-1){
            if(i%2!=0) vis[it]=1;
            else vis[it]=0;
            q.push({it,node});
          }
          else if(it !=parent){
            if(i%2!=0 and vis[it]==0 || i%2!=1 and vis[it]==1 ) return false;
          }
        }}
i++;
        }}
   return true; }
};