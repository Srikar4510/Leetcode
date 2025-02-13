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
    // void inOrderTraversal(TreeNode* root, vector<int> &v){
    //     if(root == NULL)    return;
        
    //     //left, root, right 
    //     inOrderTraversal(root->left, v);
    //     v.push_back(root->val);
    //     inOrderTraversal(root->right, v);      
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int> v; 
    //     inOrderTraversal(root, v);
    //     return v[k-1];
    // }
    //using tmp 
    void inorder(TreeNode* root,int &ans,int &ctr,int k){
      if(!root) return;
      inorder(root->left,ans,ctr,k);
      ctr++;
      if(ctr==k){
        ans = root->val;
      }
      inorder(root->right,ans,ctr,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0,ctr=0;
        inorder(root,ans,ctr,k);
        return ans;   
    }
    
};