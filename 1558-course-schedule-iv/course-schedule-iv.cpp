class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<int> indegree(n);
        vector<int> adj[n];
        vector<unordered_set<int>> isPrereq(n); // Stores all prerequisites for each course

        // Step 1: Build adjacency list and indegree array
        for (auto x : pre) {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
            isPrereq[x[1]].insert(x[0]); // Direct prerequisite
        }

        // Step 2: Perform Topological Sorting (Kahn's Algorithm - BFS)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto adjNode : adj[node]) {
                // Inherit prerequisites from the current node
                for (auto preNode : isPrereq[node]) {
                    isPrereq[adjNode].insert(preNode);
                }
                isPrereq[adjNode].insert(node);

                // Reduce indegree and push to queue if it becomes 0
                if (--indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        // Step 3: Answer Queries in O(1)
        vector<bool> ans;
        for (auto q : queries) {
            ans.push_back(isPrereq[q[1]].count(q[0])); // Check if q[0] is a prerequisite of q[1]
        }
        return ans;
    }
};
