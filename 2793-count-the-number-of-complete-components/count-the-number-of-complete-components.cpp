class DisjointSet{
  

public:
   vector<int> size,parent,rank;
   DisjointSet(int n){
      parent.resize(n+1,0);
      rank.resize(n+1,0);
      size.resize(n+1);

      for(int i=0;i<=n;i++){
         parent[i]=i;
         size[i]=1;
      }
   }

   int findUParent(int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=findUParent(parent[node]);
   }
   
   void UnionBySize(int u,int v){
    int ultParU = findUParent(u);
    int ultParV = findUParent(v);

    if(ultParU==ultParV) return;

    if(size[ultParU]<size[ultParV]){
        parent[ultParU]=ultParV;
        size[ultParV] += size[ultParU];
    }
    else{
        parent[ultParV] = ultParU;
        size[ultParU]+=size[ultParV];
    }
   }

};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        
        unordered_map<int,int> edgeCount;

        for(auto& edge:edges){
            ds.UnionBySize(edge[0],edge[1]);
        }

        for(auto& edge:edges){
            int root = ds.findUParent(edge[0]);
            edgeCount[root]++;
        }

        int completeCount = 0;
        for (int vertex = 0; vertex < n; vertex++) {
            if (ds.findUParent(vertex) == vertex) {  
                int nodeCount = ds.size[vertex];
                int expectedEdges = (nodeCount * (nodeCount - 1)) / 2;
                if (edgeCount[vertex] == expectedEdges) {
                    completeCount++;
                }
            }
        }
        return completeCount;
    }
};