class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<pair<int,int>>> adjls(n);
        for(int i=0;i<edges.size();i++){
            adjls[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adjls[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int ans=0;
        int prevcnt=INT_MAX;
      for(int i=0;i<n;i++){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
       int cnt=0;
        vector<int> dist(n,1e9);
        q.push({0,i});
        dist[i]=0;
        while(!q.empty()){
            
              int u=q.top().second;
              int dis=q.top().first;
              q.pop();
              for(auto it : adjls[u]){
                  int v=it.first;
                  int wt=it.second;
                  if(dis+wt<dist[v] and dis+wt<=dt){
                    if(dist[v]==1e9) cnt++;
                    dist[v]=dis+wt;
                    q.push({dist[v],v});
                    
                  }
              }

        }
        if(cnt<=prevcnt){
            ans=i;
            prevcnt=cnt;
        }
        
      }  
  
    return ans;}
};