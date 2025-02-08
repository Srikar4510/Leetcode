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
    void findPaths(TreeNode* node,string path,vector<string> &ans){
        if(!node) return;
        
        if(!path.empty()) path += "->";
        path += to_string(node->val);

        if(!node->left && !node->right){
            ans.push_back(path);
            return;
        }

        findPaths(node->left,path,ans);
        findPaths(node->right,path,ans);
    }  
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;    
        findPaths(root,"",ans);
        return ans;
    }
};