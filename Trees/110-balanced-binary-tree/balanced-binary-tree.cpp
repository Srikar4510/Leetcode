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
    int findHeight(TreeNode* root){
      if(!root) return 0;
      
      int lh = findHeight(root->left);
      if(lh == -1) return -1;
      int rh = findHeight(root->right);
      if(rh == -1) return -1;

      if(abs(rh-lh)>1) return -1;

      return 1+ max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        return (findHeight(root) != -1);
    }
};