class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjls(n);
        for(int i=0;i<roads.size();i++){
          adjls[roads[i][0]].push_back({roads[i][1],roads[i][2]});
          adjls[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long,int>,
               vector<pair<long long,int>>,
               greater<pair<long long,int>>> pq;
        vector<long long > dist(n,LLONG_MAX);
        vector<long long> ways(n,0);
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            int u=pq.top().second;
            long long dis=pq.top().first;
             pq.pop();
            for(auto it : adjls[u]){
            int  v=it.first;
            long long newdis=dis+it.second;
            if(newdis<dist[v]){
                dist[v]=newdis;
                ways[v]=ways[u];
                pq.push({newdis,v});

            }
            else if(newdis==dist[v]){
                ways[v]=(ways[v]+ways[u])%(1000000007LL) ;
            }

            }
             

        }

      return ways[n-1] ;}
};