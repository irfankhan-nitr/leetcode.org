class DisjointSet {
public:
vector<int> rank,parent,size;
    DisjointSet(int n) {
     rank.resize(n+1,0);
     size.resize(n+1,1);
     parent.resize(n+1);
     for(int i=0;i<n+1;i++){
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

bool isvalid(int adji,int adjj,int n,int m){
    return (adji>=0 and adji<n and adjj>=0 and adjj<m);
}


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int di[]={1,0,-1,0};
        int dj[]={0,1,0,-1};
        DisjointSet ds(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                 for(int k=0;k<4;k++){
                     int adji=i+di[k];
                    int adjj=j+dj[k];
                    if(isvalid(adji,adjj,n,m) and  grid[adji][adjj] == 1){
                        if(ds.findUP(adji*m+adjj)!=ds.findUP(i*m+j)){
                          ds.unionBySize(adji*m+adjj,i*m+j);
                        }
                    }
                 }
                }
            }
        }
        int maxi=0;
 for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
    int sizem=1;
    set<int> parent_check;
 if(grid[i][j]==0 ){
     for(int k=0;k<4;k++){
          int adji=i+di[k];
         int adjj=j+dj[k]; 
            if(isvalid(adji,adjj,n,m) and grid[adji][adjj]==1){

                 if(parent_check.find(ds.findUP(adji*m+adjj))==parent_check.end()){
                    parent_check.insert(ds.findUP(adji*m+adjj));
                 sizem+=ds.size[ds.findUP(adji*m+adjj)];}
 }}
 }   
      maxi=max(maxi,sizem); }
 }       
if(maxi==0 || maxi==1){
    for(int i=0;i<(ds.size).size();i++){
        maxi=max(maxi,ds.size[i]);
    }
}
return maxi;
    }
};