#define pi pair<long long,int>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        const int MOD = 1e9+7;

        for(auto& edge:roads){
            int u = edge[0],v=edge[1],wt=edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<long long> dist(n,LLONG_MAX);
        vector<int> pathCount(n,0);

        priority_queue<pi,vector<pi>,greater<pi>> pq;

        dist[0]=0;
        pathCount[0]=1;
        pq.push({dist[0],0});//dist,node

        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dis>dist[node]) continue;

            for(auto x:adj[node]){
                int adjNode = x.first;
                int wt = x.second;

                if(dist[adjNode]>dis+wt){
                    dist[adjNode]=dis+wt;
                    pathCount[adjNode]=pathCount[node];
                    pq.push({dist[adjNode],adjNode});
                }

                else if(dist[adjNode]==dis+wt){
                    pathCount[adjNode]=(pathCount[adjNode]+pathCount[node])%MOD;
                }
            }
        }
          
    return pathCount[n-1];
    }
};