class DisjointSet{

vector<int> rank,size,parent;

  public:
     DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i] = 1;
        }
     }

     int findUParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUParent(parent[node]);
     }

     void UnionByRank(int u,int v){
        int ultParU = findUParent(u);
        int ultParV = findUParent(v);
        if(ultParU==ultParV) return;

        if(rank[ultParU]<rank[ultParV]){
            parent[ultParU]=ultParV;
        }
        else if(rank[ultParV]<rank[ultParU]){
            parent[ultParV]=ultParU;
        }
        else{
            parent[ultParV]=ultParU;
            rank[ultParU]++;
        }
     }

     void UnionBySize(int u,int v){
        int ultParU = findUParent(u);
        int ultParV = findUParent(v);

        if(ultParU == ultParV) return;

        if(size[ultParU]<size[ultParV]){
            parent[ultParU]=ultParV;
            size[ultParV]+=size[ultParU];
        }
        else{
            parent[ultParV]=ultParU;
            size[ultParU]+=size[ultParV];
        }
     }
};


class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        DisjointSet ds(n);

        //define component array to (2^32-1)(binary contains all 1's)
        vector<int> componentCost(n,INT_MAX);
        
        //find all connected components
        for(auto& edge:edges){
            ds.UnionBySize(edge[0],edge[1]);
        }

        //find all compoment costs
        for(auto& edge:edges){
            int ultPar = ds.findUParent(edge[0]);
            componentCost[ultPar] &= edge[2];
        }

        vector<int> ans;
        for(auto& query:queries){
            int u = query[0],v=query[1];

            if(ds.findUParent(u)!=ds.findUParent(v)){
                ans.push_back(-1);
            }
            else{
                int ultPar = ds.findUParent(u);
                ans.push_back(componentCost[ultPar]);
            }
        }

        return ans;
    }
};