/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // //Inorder : left root right
    // void Inorder(TreeNode* node,vector<int> &ans){
    //   if(node == NULL) return;
    //   Inorder(node->left,ans);
    //   ans.push_back(node->val);
    //   Inorder(node->right,ans);
    // }
    // //TC ->O(N) SC-> O(N)
    // vector<int> inorderTraversal(TreeNode* root) {
    //    vector<int> ans;
    //    Inorder(root,ans);
    //    return ans;
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                    if (prev->right == NULL) {
                        prev->right = curr;
                        curr = curr->left;
                    }
                    else{
                        prev->right=NULL;
                        inorder.push_back(curr->val);
                        curr = curr->right;
                    }
                }
            }
        
        return inorder;
    }
};