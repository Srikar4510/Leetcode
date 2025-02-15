/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void buildGraph(TreeNode* node,unordered_map<int,vector<int>> &adj,TreeNode* parent){
        if(!node) return;
        if(parent){
            adj[node->val].push_back(parent->val);
            adj[parent->val].push_back(node->val);
        }
        buildGraph(node->left,adj,node);
        buildGraph(node->right,adj,node);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adj;
        buildGraph(root,adj,nullptr);
        //start bfs
        queue<int> q;
        q.push(start);

        unordered_set<int> visited;
        visited.insert(start);

        int minutes=-1;
        while(!q.empty()){
          int size=q.size();
          minutes++;
          for(int i=0;i<size;i++){
            int node = q.front();
            q.pop();
            for(int neighbour:adj[node]){
                 if(!visited.count(neighbour)){
                    visited.insert(neighbour);
                    q.push(neighbour);
                 }
            }
          }  
        }
        return minutes;
    }
};