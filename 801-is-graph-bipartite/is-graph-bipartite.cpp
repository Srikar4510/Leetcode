class Solution {
public:
    bool dfs(int node,int col,vector<vector<int>>& graph,vector<int>& color){
        //color the node 
        color[node]=col;
        //change the to color the adjacent Nodes
        col = 1-col;

        for(auto adjNode:graph[node]){
            //if adjNode is not colored,go and color them   
            if(color[adjNode]==2){
                if(!dfs(adjNode,col,graph,color))
                 return false;
            }
            //if the adjNode is colored and adjNode color is no different return false 
            else if(color[adjNode]!=col){
                return false;
            }
        }
        return true;
    } 
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,2);

        for(int i=0;i<n;i++){
            if(color[i]==2){
                if(!dfs(i,0,graph,color)){
                    return false;
                }
            }
        }
        return true;
    }
};