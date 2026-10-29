class DisjointSet {
public:
vector<double> rank,parent,size;
    DisjointSet(double n) {
     rank.resize(n+1,0);
     size.resize(n+1,1);
     parent.resize(n+1);
     for(double i=0;i<n+1;i++){
        parent[i]=i;
     }
    }
    int findUP(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUP(parent[node]);
    }

    bool find(int u, int v) {
    int u_lp=findUP(u);
    int v_lp=findUP(v);
    if(u_lp==v_lp) return true;
    return false;
    }

    void unionByRank(int u, int v) {
    int u_lp=findUP(u);
    int v_lp=findUP(v);
    if(rank[u_lp]>rank[v_lp]){
         parent[v_lp]=u_lp;
    }
    else if(rank[v_lp]>rank[u_lp]){
        parent[u_lp]=v_lp;
    }
    else{
         parent[v_lp]=u_lp;
         rank[u_lp]++;
    }
    }

    void unionBySize(int u, int v) {
    int u_lp=findUP(u);
    int v_lp=findUP(v);
    if(size[u_lp]>size[v_lp]){
        parent[v_lp]=u_lp;
        size[u_lp]+=size[v_lp];
    }
    else{
        parent[u_lp]=v_lp;
        size[v_lp]+=size[u_lp];
    }

    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int maxcol=0;
        int n=stones.size();
        for(int i=0;i<stones.size();i++){
            maxrow=max(maxrow,stones[i][0]);
            maxcol=max(maxcol,stones[i][1]);

        }
    DisjointSet ds(maxrow+maxcol+1);
    unordered_map<int,int> mpp;
    for(auto it : stones){
        long long row=it[0];
        long long col=it[1];
         col=maxrow+col+1;
        ds.unionBySize(row,col);
        mpp[row]=1;
        mpp[col]=1;
    }
    int ans=0;
for(auto it: mpp){
    if(ds.parent[it.first]==it.first) ans++;
}

   return n-ans; }
};