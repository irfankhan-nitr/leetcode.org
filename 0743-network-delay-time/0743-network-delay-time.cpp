class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjls(n+1);
        for(int i=0;i<times.size();i++){
            adjls[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int dis=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            for(auto it : adjls[u]){
                int v=it.first;
                int wt=it.second;
                if(dis+wt<dist[v]){
                    dist[v]=dis+wt;
                    pq.push({dist[v],v});
                }
            }
        }int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
               maxi=max(maxi,dist[i]);
        }
   return maxi; }
};