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
//O(N),O(N)
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int ans=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            long long levelMin = q.front().second;
            int sz = q.size();
            long long first,last;
            for(int i=0;i<sz;i++){
                long long curr_index = q.front().second - levelMin;
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i==0) first = curr_index;
                if(i==sz-1) last = curr_index;
                if(node->left) q.push({node->left,curr_index*2+1});
                if(node->right) q.push({node->right,curr_index*2+2});
               
            }
            ans = max(ans,static_cast<int>(last-first+1));
        }
        return ans;
    }
};